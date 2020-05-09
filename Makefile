a.out: main.o address.o phone.o person.o datetime.o people.o
	g++ -std=c++11 -Wall -g main.o address.o phone.o person.o datetime.o people.o
main.o: main.cpp main.h person.cpp person.h datetime.cpp datetime.h people.h people.cpp
	g++ -std=c++11 -c main.cpp
people.o: people.cpp people.h person.cpp person.h address.cpp address.h
	g++ -std=c++11 -c people.cpp
person.o: person.cpp person.h address.cpp address.h
	g++ -std=c++11 -c person.cpp
datetime.o: datetime.cpp datetime.h
	g++ -std=c++11 -c datetime.cpp
address.o: address.cpp address.h
	g++ -std=c++11 -c address.cpp
phone.o: phone.cpp phone.h
	g++ -std=c++11 -c phone.cpp


.PHONY: clean

clean:
	rm -f *.o core a.out