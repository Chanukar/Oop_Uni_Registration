objects = user.o undergrad.o postgrad.o main.o
registration: $(objects)
	g++ -std=c++11 -o registration $(objects)
	clear
	./registration
	make clean

user.o: user.cpp user.h
	g++ -std=c++11 -c $< -o $@

undergrad.o: undergrad.cpp
	g++ -std=c++11 -c $< -o $@

postgrad.o: postgrad.cpp
	g++ -std=c++11 -c $< -o $@

test: $(objects)
	g++ -std=c++11 -o out $(objects)
	clear
	bash testall
	rm -rf out
	rm *.o

code:
	g++ -std=c++11 -o out user.cpp undergrad.cpp postgrad.cpp main.cpp
	./out
	rm -rf out

clean:
	rm *.o registration
	clear