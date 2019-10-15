registration: user.o undergrad.o postgrad.o main.o
	g++ -std=c++11 -o registration user.o undergrad.o postgrad.o main.cpp

user.o: user.cpp user.h
	g++ -std=c++11 -c user.cpp

undergrad.o: undergrad.cpp
	g++ -std=c++11 -c undergrad.cpp

postgrad.o: postgrad.cpp
	g++ -std=c++11 -c postgrad.cpp

clean:
	rm *.o registration