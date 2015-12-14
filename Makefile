# $File: Makefile
# $Date: Dec 05 2014
# $Author: huanghuan <huanghuanthu@163.com>

BUILD_DIR = build
TARGET = -o sql
CPPS = dbms.cpp

CXX = g++ -std=c++11

all : $(HEADERS)
	$(CXX) $(TARGET) $(CPPS)

$(HEADERS) : dbms/*.h filesystem/*.h table/*.h utils/*.h

clean :
	rm $(TARGET)
