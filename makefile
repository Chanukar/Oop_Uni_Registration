registration: user.o undergrad. postgrad.o main.o
	g++ -o registration user.o undergrad.o postgrad.o main.o

user.o: user.cpp user.h
	g++ -c user.cpp

undergrad.o: undergrad.cpp undergrad.h
	g++ -c undergrad.cpp user.cpp

postgrad.o: postgrad.cpp postgrad.h
	g++ -c postgrad.cpp undergrad.cpp user.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o registration