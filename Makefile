# Course: Object Oriented Programming
# Major Practical
# Authors:
# Student IDs: a1782891, a, a
# Description: Makefile for our University enrolment system

all: registration

registration:
	g++ -std=c++11 -o out user.cpp undergrad.cpp postgrad.cpp main.cpp
	./out
	rm -rf out
	clear

faculty:
	g++ test_faculty.cpp Degree.cpp Faculty.cpp -o out
	./out

test:
	g++ -std=c++11 -o out user.cpp undergrad.cpp postgrad.cpp main.cpp
	./out < testcases/ input.txt > testcases/output.txt
	nano testcases/output.txt
	rm -rf output.txt
	rm -rf out
clean:
	rm -rf out