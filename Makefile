CC = g++
CFLAGS = -std=c++11 -Wall -g 
SRCS = main.cpp datetime.cpp address.cpp phone.cpp person.cpp people.cpp
#SRCS = ${wildcard *.cpp}
OBJS = ${SRCS:.cpp=.o}
#INCLS = ${wildcard *.h}
INCLS = ${SRCS:.cpp=.h} datetime.h address.h phone.h person.h people.h

a.out: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)

$(OBJS):
	$(CC) $(CFLAGS) -c $*.cpp

depend: Makefile.dep
	$(CC) -MM $(SRCS) > Makefile.dep

Makefile.dep:
	touch Makefile.dep

.PHONY: submit clean

clean:
	rm -f $(OBJS) a.out core

include Makefile.dep