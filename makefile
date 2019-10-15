registration: user.o undergrad.o postgrad.o main.o
	g++ -std=c++11 -o registration user.o undergrad.o postgrad.o main.cpp

user.o: user.cpp user.h
	g++ -std=c++11 -c user.cpp

undergrad.o: undergrad.cpp
	g++ -std=c++11 -c undergrad.cpp

postgrad.o: postgrad.cpp
	g++ -std=c++11 -c postgrad.cpp

test:
	g++ -std=c++11 -o out user.cpp undergrad.cpp postgrad.cpp main.cpp
	./out < testcases/input.txt | diff - testcases/realoutput.txt
	rm -rf output.txt
	rm -rf out

clean:
	rm *.o registration