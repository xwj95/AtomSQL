#ifndef DBMS_TABLEMANAGER_H_
#define DBMS_TABLEMANAGER_H_

#include "io.h"
#include "../table/tabledef.h"
#include "../table/columns.h"

class TableManager {

	BufPageManager *bpm;
	IO *io;

public:

	TableManager (BufPageManager *bpm, IO *io) {
		this->bpm = bpm;
		this->io = io;
	}

	~TableManager() {
	}

	//写入表的元数据
	void writeHeader(int fileID, int pageID, Columns &header, bool alloc = true) {
		int index;

		//申请或者获得元数据页
		BufType b;
		if (alloc) {
			b = bpm->allocPage(fileID, pageID, index, true);
		}
		else {
			b = bpm->getPage(fileID, pageID, index);
		}
		bpm->markDirty(index);
		b = header.writeColumns(b, io);
	}

	//读入表的元数据
	Columns readHeader(int fileID, int pageID) {
		int index;

		//读取元数据页
		BufType b = bpm->getPage(fileID, pageID, index);
		bpm->access(index);
		Columns header;
		b = header.readColumns(b, io);
		return header;
	}
};

#endif
