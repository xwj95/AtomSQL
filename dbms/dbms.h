/*
 * dbms.h
 *
 *  Created on: 2015年10月26日
 *      Author: Xwj95
 */

#ifndef DBMS_DBMS_H_
#define DBMS_DBMS_H_

#include "tableManager.h"
#include <algorithm>
#include <string>
#include <map>

class Dbms {
	FileManager* fm;
	BufPageManager* bpm;
	tableManager* tb;
	IO* io;
	map<string, int> files;
	map<string, Column> headers;
	string directory;
	//切换目录，切换数据库时调用该接口
	int useDirectory(string directory) {
		//打开目录
		DIR *dirp = opendir(directory.c_str());
		if (dirp == NULL) {
			return -1;
		}
		dirent *direntp;
		//打开当前目录下的所有文件
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
	//删除目录，删除数据库时调用该接口
	int removeDirectory(string directory) {
		//打开目录
		DIR *dirp = opendir(directory.c_str());
		if (dirp == NULL) {
			return -1;
		}
		dirent *direntp;
		//打开当前目录下的所有文件，并全部删除
		while ((direntp = readdir(dirp)) != NULL) {
			string file = string(direntp->d_name);
			if ((file != ".") && (file != "..")) {
				file = directory + separator + file;
				remove(file.c_str());
			}
		}
		closedir(dirp);
		return 0;
	}
	//列出当前目录下所有表的文件名
	int showDirectory(string directory) {
		//打开目录
		DIR *dirp = opendir(directory.c_str());
		if (dirp == NULL) {
			return -1;
		}
		dirent *direntp;
		//打开当前目录下的所有文件
		while ((direntp = readdir(dirp)) != NULL) {
			string file = string(direntp->d_name);
			//判断文件是否是.db格式
			if ((file.length() >= dbtype.length()) && (file.substr(file.length() - dbtype.length(), dbtype.length()) == dbtype)) {
				cout << file.substr(0, file.length() - dbtype.length()) << endl;
			}
		}
		return 0;
	}
	//打开表
	//exist为true时，表明本次查找希望指定表存在，从而可以打开表
	//exist为false时，表明本次查找希望指定表不存在，从而可以创建新的表
	int openTable(string tableName, bool exist = true) {
		if (opendir(directory.c_str())) {
			string file = directory + tableName + dbtype;
			//表没有找到
			if (files.find(tableName) == files.end()) {
				if (exist) {
					cout << file << " does not exist." << endl;
					return -1;
				}
				return 0;
			}
		}
		else {
			cout << "Please specify an existing database." << endl;
			return -1;
		}
		if (!exist) {
			cout << tableName + dbtype << " already exists." << endl;
			return -1;
		}
		return 0;
	}
public:
	Dbms() {
		fm = new FileManager();
		bpm = new BufPageManager(fm);
		files.clear();
		headers.clear();
		directory = "";
		io = new IO();
		tb = new tableManager(bpm, io);
	}
	~Dbms() {
		if (bpm != NULL) {
			bpm->close();
			delete bpm;
		}
		if (fm != NULL) {
			fm->closeAll();
			delete fm;
		}
		if (tb != NULL) {
			delete tb;
		}
		if (io != NULL) {
			delete io;
		}
	}
	//创建数据库
	int createDatabase(string dbName) {
		int result = mkdir(dbName.c_str(), S_IRWXU);
		return result;
	}
	//删除数据库
	int dropDatabase(string dbName) {
		//如果待删除的数据库是当前数据库，则清除文件和表的元数据
		if (directory == dbName + separator) {
			directory = "";
			bpm->close();
			fm->closeAll();
			files.clear();
			headers.clear();
		}
		//待删除数据库不存在
		if (removeDirectory(dbName)) {
			cout << dbName << " does not exist." << endl;
			return -1;
		}
		int result = rmdir(dbName.c_str());
		return result;
	}
	//切换数据库
	int useDatabase(string dbName) {
		string _directory = dbName + separator;
		//如果不是当前数据库，则执行切换，否则不执行切换
		if (directory != _directory) {
			//待切换数据库不存在
			if (!opendir(_directory.c_str())) {
				cout << dbName << " does not exist." << endl;
				return -1;
			}
			//切换目录
			directory = _directory;
			bpm->close();
			fm->closeAll();
			files.clear();
			headers.clear();
			//获取所有表和表的元数据
			useDirectory(directory);
		}
		return 0;
	}
	//创建表
	int createTable(string tableName, Column &column) {
		//待创建表已存在，或没有指定数据库
		if (openTable(tableName, false)) {
			return -1;
		}
		//表项为空
		if (column.type.size() < 1) {
			cout << "Empty table cannot be created." << endl;
			return -1;
		}
		//表项超过上限
		if (column.type.size() > MAX_COL_NUM) {
			cout << "Column number cannot exceed " << MAX_COL_NUM << "." << endl;
		}
		string file = directory + tableName + dbtype;
		//创建表
		fm->createFile(file.c_str());
		int fileID;
		fm->openFile(file.c_str(), fileID);
		//创建表的元数据页
		column.canNull[column.major] = false;
		column.countSize();
		files[tableName] = fileID;
		headers[tableName] = column;
		//将表的元数据写入文件第一页
		tb->writeHeader(fileID, 0, column);
		return 0;
	}
	//删除表
	int dropTable(string tableName) {
		//待删除表不存在，或没有指定数据库
		if (openTable(tableName)) {
			return -1;
		}
		//关闭文件，并清除表和元数据的缓存
		fm->closeFile(files[tableName]);
		files.erase(tableName);
		headers.erase(tableName);
		string file = directory + tableName + dbtype;
		//删除表
		int result = remove(file.c_str());
		return result;
	}
	//列出当前数据库所有表
	int showTables() {
		if (opendir(directory.c_str())) {
			showDirectory(directory);
			return 0;
		}
		//没有指定数据库
		else {
			cout << "Please specify an existing database." << endl;
			return -1;
		}
	}
	//列出表的模式信息
	int descTable(string tableName) {
		//表不存在，或没有指定数据库
		if (openTable(tableName)) {
			return -1;
		}
		//直接从缓存中获取元数据
		Column column = headers[tableName];
		cout << column.schema << endl;
		return 0;
	}
	//插入记录
	int insertData(string tableName, vector<Data> &data_insert, Column column) {
		//表不存在，或没有指定数据库
		if (openTable(tableName)) {
			return -1;
		}
		//获取表的元数据
		Column header = headers[tableName];
		vector<int> indexs;
		//获取待插入的列项的列数，并检查是否有非法情况
		if (tb->getIndexs(column, header, indexs, true)) {
			return -1;
		}
		vector<Data> data_write;
		//将记录转化为文件中存储格式，并检查是否有非法情况
		if (tb->getWriteData(column, header, indexs, data_insert, data_write)) {
			return -1;
		}
		//将记录插入表中
		string file = directory + tableName + dbtype;
		int fileID = files[tableName];
		int result = tb->writeData(fileID, header, data_write);
		headers[tableName] = header;
		return result;
	}
	//删除记录
	int deleteData(string tableName, vector<int> page_delete, vector<int> index_delete) {
		//表不存在，或没有指定数据库
		if (openTable(tableName)) {
			return -1;
		}
		//待删除行为空
		if (index_delete.size() < 1) {
			return 0;
		}
		//获取表的元数据
		Column header = headers[tableName];
		int fileID = files[tableName];
		int result = tb->deleteData(fileID, header, page_delete, index_delete);
		headers[tableName] = header;
		return result;
	}
	//更新记录
	int updateData(string tableName, vector<int> page_update, vector<int> index_update, vector<Data> &data_update) {
		//表不存在，或没有指定数据库
		if (openTable(tableName)) {
			return -1;
		}
		//待更新行为空
		if (index_update.size() < 1) {
			return 0;
		}
		//获取表的元数据
		Column header = headers[tableName];
		int fileID = files[tableName];
		int result = tb->updateData(fileID, header, page_update, index_update, data_update);
		headers[tableName] = header;
		return result;
	}
	//查找记录
	int selectData(string tableName, vector<Data> &data, vector<Data> &result) {
		//表不存在，或没有指定数据库
		if (openTable(tableName)) {
			return -1;
		}
		//获取表的元数据
		Column header = headers[tableName];
		return 0;
	}
};

#endif /* DBMS_DBMS_H_ */
