# $File: Makefile
# $Date: Dec 05 2014
# $Author: huanghuan <huanghuanthu@163.com>

BUILD_DIR = build
TARGET = -o sql
OBJS = dbms.o

CXX = g++ -std=c++11

all : $(OBJS)
	$(CXX) $(TARGET) $(OBJS)

$(OBJS) : dbms/*.h filesystem/*.h table/*.h utils/*.h

clean :
	rm $(TARGET) $(OBJS)
