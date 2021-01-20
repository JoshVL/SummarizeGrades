# Makefile for SummarizeGrades

CXX=g++
CXXFLAGS=-Wall

all: build

SummarizeGrades.o: SummarizeGrades.h

clean:
	-rm SummarizeGrades.o
	-rm summarizegrades

build: demo.cpp SummarizeGrades.o
	$(CXX) $(CXXFLAGS) -o summarizegrades demo.cpp SummarizeGrades.o
