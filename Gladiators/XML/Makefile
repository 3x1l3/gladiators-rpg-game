## definitions
CC = g++
CCFLAGS = -Wall
OBJS1 = driver.o pugixml.o XMLWrapper.o

## targets and prerequisites
.PHONY : all
all : prog1

prog1 : $(OBJS1)
	$(CC) $^ -o $@

# default rule for compiling .cc to .o
%.o: %.cc                               ## next line must begin with a TAB
	$(CC) -c $(CCFLAGS) $< 

## generate the prerequistes and append to the desired file
.prereq : $(OBJS1:.o=.cc) $(OBJS2:.o=.cc) $(OBJS3:.o=.cc) $(wildcard *.h) Makefile
	rm -f .prereq
	$(CC) $(CCFLAGS) -MM $(OBJS1:.o=.cc) $(OBJS2:.o=.cc) $(OBJS3:.o=.cc) >> ./.prereq 

## include the generated prerequisite file
include .prereq

.PHONY : clean
clean :                 ## next lines must begin with a TAB
	rm -f *.o
	rm -f *~ *# .#*

.PHONY : clean-all
	clean-all : clean      ## next line must begin with a TAB
	rm -f prog1
