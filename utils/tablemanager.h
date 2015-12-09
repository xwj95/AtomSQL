#ifndef DBMS_TABLEMANAGER_H_
#define DBMS_TABLEMANAGER_H_

#include "io.h"
#include "../table/tabledef.h"

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

	int writeHeader(int fileID, int pageID, Columns &header) {

	}

	Columns& readHeader(int fileID, int pageID) {

	}
};

#endif
