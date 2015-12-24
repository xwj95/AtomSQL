#ifndef DBMS_TABLEMANAGER_H_
#define DBMS_TABLEMANAGER_H_

#include "io.h"
#include "../table/tabledef.h"
#include "../table/columns.h"
#include "../condition/condition.h"
#include "../expression/expressions.h"

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
		BufType b = bpm->getPage(fileID, pageID, index);\
		bpm->access(index);
		Columns header;
		b = header.readColumns(b, io);
		return header;
	}

	//插入记录
	int insertRecord(int fileID, Columns &header, Rows &records) {
		int pageID = 1;
		int record = 0;
		while (record < records.rows.size()) {
			Rows page;
			if (pageID > header.pages) {
				//需要申请新的页面
				page.newPage(bpm, io, fileID, pageID, header);
				writeHeader(fileID, 0, header, false);
			}
			else {
				page.read(bpm, io, fileID, pageID, header);
			}
			//当前页面已满
			if (page.counts == 0) {
				pageID++;
				continue;
			}
			//寻找空槽
			for (int i = 0; i < header.num; ++i) {
				if (page.rows[i].next != 1) {
					continue;
				}
				//当前槽为空槽
				page.rows[i] = records.rows[record];
				page.rows[i].rid = (pageID - 1) * header.num + i;
				int j = i;
				do {
					if ((j < header.num - 1) && (page.rows[j + 1].next != 0)) {
						page.rows[j].next = page.rows[j + 1].next + 1;
					}
					else {
						page.rows[j].next = 0;
					}
					j--;
				}
				while ((j >= 0) && (page.rows[j].next != 1));
				page.counts--;
				record++;
				if (record >= records.rows.size()) {
					break;
				}
			}
			page.write(bpm, io, fileID, pageID, header);
		}
		cout << "PageID = " << pageID << endl;
		return 0;
	}

	//删除记录
	int deleteRecord(int fileID, Columns &header, vector<int> &delta) {
		int pageID = 1;
		int record = 0;
		while ((record < delta.size()) && (pageID <= header.pages)) {
			int pageDel = delta[record] / header.num + 1;
			//当前页没有要删除的记录
			if (pageDel != pageID) {
				pageID++;
				continue;
			}
			//获取当前页的记录
			Rows page;
			page.read(bpm, io, fileID, pageID, header);
			int del = delta[record] % header.num;
			//待删除记录为空
			if (page.rows[del].next == 1) {
				record++;
				continue;
			}
			//删除记录
			page.rows[del].next = 1;
			//更新next指针
			for (int i = del - 1; i >= 0; --i) {
				if (page.rows[i].next == 1) {
					break;
				}
				page.rows[i].next = page.rows[i + 1].next + 1;
			}
			page.counts++;
			page.write(bpm, io, fileID, pageID, header);
			record++;
		}
		return 0;
	}

	//更新记录
	int updateRecord(int fileID, Columns &header, vector<int> &delta, Rows &records) {
		int pageID = 1;
		int record = 0;
		while ((record < delta.size()) && (pageID <= header.pages)) {
			int pageUpd = delta[record] / header.num + 1;
			//当前页没有要更新的记录
			if (pageUpd != pageID) {
				pageID++;
				continue;
			}
			//获取当前页的记录
			Rows page;
			page.read(bpm, io, fileID, pageID, header);
			int upd = delta[record] % header.num;
			//待更新记录为空
			if (page.rows[upd].next == 1) {
				record++;
				continue;
			}
			//更新记录
			records.rows[record].next = page.rows[upd].next;
			records.rows[record].rid = page.rows[upd].rid;
			page.rows[upd] = records.rows[record];
			page.write(bpm, io, fileID, pageID, header);
			record++;
		}
		return 0;
	}

	//选择记录
	int selectRecord(int fileID, Columns &header, vector<int> &delta, Expressions expressions) {
		int pageID = 1;
		int record = 0;
		while ((record < delta.size()) && (pageID <= header.pages)) {
			int pageSel = delta[record] / header.num + 1;
			//当前页没有要选择的记录
			if (pageSel != pageID) {
				pageID++;
				continue;
			}
			//获取当前页的记录
			Rows page;
			page.read(bpm, io, fileID, pageID, header);
			int sel = delta[record] % header.num;
			//待选择记录为空
			if (page.rows[sel].next == 1) {
				record++;
				continue;
			}
			expressions.cal(page.rows[sel]);
			record++;
		}
		return 0;
	}

	//更新记录
	int updateRecord(int fileID, Columns &header, vector<int> &delta, Condition &condition) {
		int pageID = 1;
		int record = 0;
		while ((record < delta.size()) && (pageID <= header.pages)) {
			int pageUpd = delta[record] / header.num + 1;
			//当前页没有要更新的记录
			if (pageUpd != pageID) {
				pageID++;
				continue;
			}
			//获取当前页的记录
			Rows page;
			page.read(bpm, io, fileID, pageID, header);
			int upd = delta[record] % header.num;
			//待更新记录为空
			if (page.rows[upd].next == 1) {
				record++;
				continue;
			}
			//更新记录
			//records.rows[record].next = page.rows[upd].next;
			//records.rows[record].rid = page.rows[upd].rid;
			//page.rows[upd] = records.rows[record];
			//page.write(bpm, io, fileID, pageID, header);
			record++;
		}
		return 0;
	}

	//查找待删除/更新/选择记录
	int recordFind(int fileID, Columns &header, Condition &condition, vector<int> &delta) {
		int pageID = 1;
		int record = 0;
		delta.clear();
		while (pageID <= header.pages) {
			//获取当前页的记录
			Rows page;
			page.read(bpm, io, fileID, pageID, header);
			for (int i = 0; i < header.num; ++i) {
				if (page.rows[i].next == 1) {
					record++;
					continue;
				}
				bool term;
				int result = condition.cal(page.rows[i], term);
				if (result) {
					return result;
				}
				if (term) {
					delta.push_back(record);
				}
				record++;
			}
			pageID++;
		}
		return 0;
	}

	//查找待更新记录
	int deleteFind(int fileID, Columns &header, Condition &condition, vector<int> &delta) {
		int pageID = 1;
		int record = 0;
		delta.clear();
		while (pageID <= header.pages) {
			//获取当前页的记录
			Rows page;
			page.read(bpm, io, fileID, pageID, header);
			for (int i = 0; i < header.num; ++i) {
				if (page.rows[i].next == 1) {
					record++;
					continue;
				}
				bool term;
				int result = condition.cal(page.rows[i], term);
				if (result) {
					return result;
				}
				if (term) {
					delta.push_back(record);
				}
				record++;
			}
			pageID++;
		}
		return 0;
	}
};

#endif
