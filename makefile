objects = user.o undergrad.o postgrad.o main.o
registration: $(objects)
	g++ -std=c++11 -o registration $(objects)
	./registration
	make clean

user.o: user.cpp user.h
	g++ -std=c++11 -c $< -o $@

undergrad.o: undergrad.cpp
	g++ -std=c++11 -c $< -o $@

postgrad.o: postgrad.cpp
	g++ -std=c++11 -c $< -o $@

test:
	g++ -std=c++11 -o out user.cpp undergrad.cpp postgrad.cpp main.cpp
	./out < testcases/input.txt | diff - testcases/realoutput.txt
	rm -rf output.txt
	rm -rf out

clean:
	rm *.o registration
	clear