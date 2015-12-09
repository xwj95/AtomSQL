#ifndef DBMS_DOCUMENT_H_
#define DBMS_DOCUMENT_H_

#include "filedef.h"
#include "tablemanager.h"
#include "../table/columns.h"
#include <map>

class Document {

	FileManager *fm;
	BufPageManager *bpm;
	TableManager *tb;
	IO *io;
	map<string, int> files;
	map<string, Columns> headers;
	string directory;

	//打开目录
	DIR* openDirectory(string directory) {
		return opendir(directory.c_str());
	}

	//查找文件
	//exist为true时，表明本次查找希望指定文件存在，从而可以打开文件
	//exist为false时，表明本次查找希望指定文件不存在，从而可以创建新的文件
	int findFile(string fileName, bool exist = true) {
		if (openDirectory(directory) == NULL) {
			return -2;
		}
		string file = directory + fileName + dbtype;
		//文件没有找到
		if (files.find(fileName) == files.end()) {
			return exist ? -3 : 0;
		}
		else {
			return exist ? 0 : -3;
		}
	}

	//新建文件
	int newFile(string fileName, int &fileID) {
		string file = directory + fileName + dbtype;
		fm->createFile(file.c_str());
		fm->openFile(file.c_str(), fileID);
		return 0;
	}

	void clear() {
		bpm->close();
		fm->closeAll();
		files.clear();
		headers.clear();
		directory = "";
	}

public:

	Document() {
		fm = new FileManager();
		bpm = new BufPageManager(fm);
		io = new IO();
		tb = new TableManager(bpm, io);
		clear();
	}

	~Document() {
		clear();
		if (tb != NULL) {
			delete tb;
		}
		if (bpm != NULL) {
			bpm->close();
			delete bpm;
		}
		if (fm != NULL) {
			fm->closeAll();
			delete fm;
		}
		if (io != NULL) {
			delete io;
		}
	}

	//创建目录
	int createDirectory(string directory) {

		mkdir(directory.c_str(), S_IRWXU);
		return 0;
	}

	//删除目录
	int removeDirectory(string directory) {

		//如果删除的是当前目录，则清除缓存
		if (this->directory == directory + separator) {
			clear();
		}

		//打开目录
		DIR *dirp = openDirectory(directory);

		//待删除目录不存在
		if (dirp == NULL) {
			return -1;
		}

		//打开该目录下的所有文件，并全部删除
		dirent *direntp;
		while ((direntp = readdir(dirp)) != NULL) {
			string file = string(direntp->d_name);
			if ((file != ".") && (file != "..")) {
				file = directory + separator + file;
				remove(file.c_str());
			}
		}
		closedir(dirp);

		rmdir(directory.c_str());
		return 0;
	}

	//切换目录
	int useDirectory(string directory) {

		string useDirectory = directory + separator;

		//如果是当前目录，则不执行切换
		if (this->directory == useDirectory) {
			return 0;
		}

		DIR *dirp = openDirectory(useDirectory);
		//待切换数据库不存在
		if (dirp == NULL) {
			return -1;
		}

		//切换目录
		clear();
		this->directory = useDirectory;

		//打开当前目录下的所有文件
		dirent *direntp;
		while ((direntp = readdir(dirp)) != NULL) {
			string file = string(direntp->d_name);
			if (file.length() < dbtype.length()) {
				continue;
			}
			string tableName = file.substr(0, file.length() - dbtype.length());
			string typeName = file.substr(file.length() - dbtype.length(), dbtype.length());
			//判断文件是否是.db格式
			if (typeName == dbtype) {
				int fileID;
				fm->openFile((directory + file).c_str(), fileID);
				files[tableName] = fileID;
				headers[tableName] = tb->readHeader(fileID, 0);
			}
		}
		closedir(dirp);
		return 0;
	}

	//列出当前目录下所有表的文件名
	int showDirectory(string directory) {

		//打开目录
		DIR *dirp = openDirectory(directory);

		//待删除目录不存在
		if (dirp == NULL) {
			return 1;
		}

		//打开当前目录下的所有文件
		dirent *direntp;
		while ((direntp = readdir(dirp)) != NULL) {
			string file = string(direntp->d_name);
			//判断文件格式是否为.db
			if ((file.length() >= dbtype.length()) && (file.substr(file.length() - dbtype.length(), dbtype.length()) == dbtype)) {
				cout << file.substr(0, file.length() - dbtype.length()) << endl;
			}
		}
		closedir(dirp);

		return 0;
	}

	//创建文件
	int createFile(string fileName, Columns &header) {

		int result = findFile(fileName, false);
		//待创建文件已存在，或没有指定目录
		if (result) {
			return result;
		}

		//创建文件
		int fileID;
		newFile(fileName, fileID);
		files[fileName] = fileID;
		headers[fileName] = header;

		//将表的元数据写入第零页
		tb->writeHeader(fileID, 0, header);
		return 0;
	}
};

#endif