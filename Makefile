CPPFLAGS= -g -Wall -pedantic -std=c++14 -iquote inc

__start__: ./kolejka
	./kolejka

./kolejka:obj obj/main.o obj/kolejka.o
	g++ -o ./kolejka obj/main.o obj/kolejka.o

obj/main.o:src/main.cpp inc/kolejka.hh
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/kolejka.o:src/kolejka.cpp inc/kolejka.hh
	g++ -c ${CPPFLAGS} -o obj/kolejka.o src/kolejka.cpp

clean:
	rm -f obj/*.o kolejka

obj:
	mkdir -p obj