# 
# Makefile for the AtomSQL project parser
# 
# Huang Huan
# CST, Tsinghua University
# 

TARGET = -o sql_parser
# CXX = g++ -std=c++11
CXX = g++
YACC = bison -d
LEX = flex
OPTS = -Wall

all: sql_parser
	@echo "Finished building!"

sql_parser: bison.tab.c lex.yy.c 
	$(CXX) $(OPTS) $(TARGET) bison.tab.c lex.yy.c 

bison.tab.h: bison.tab.c

bison.tab.c: bison.y
	$(YACC) -v bison.y

lex.yy.c: flex.l scanhelp.c bison.tab.h
	$(LEX) flex.l

nodes.o: nodes.c
