objects = user.o undergrad.o postgrad.o prompt.o register_user.o admin.o main.o
registration: $(objects)
	g++ -std=c++11 -o registration $(objects)
	clear
	./registration
	make clean

user.o: user.cpp
	g++ -std=c++11 -c $< -o $@

undergrad.o: undergrad.cpp
	g++ -std=c++11 -c $< -o $@

postgrad.o: postgrad.cpp
	g++ -std=c++11 -c $< -o $@

prompt.o: prompt.cpp
	g++ -std=c++11 -c $< -o $@

register_user.o: register_user.cpp
	g++ -std=c++11 -c $< -o $@

admin.o: admin.cpp
	g++ -std=c++11 -c $< -o $@

main.o: main.cpp
	g++ -std=c++11 -c $< -o $@

test: $(objects)
	g++ -std=c++11 -o out $(objects)
	clear
	bash testall
	rm -rf out
	rm *.o
	g++ -std=c++11 prompt.cpp prompt_test.cpp -o prompt
	

code:
	g++ -std=c++11 -o out user.cpp undergrad.cpp postgrad.cpp prompt.cpp register_user.cpp admin.cpp main.cpp
	./out
	rm -rf out

set:
	g++ -std=c++11 -o out user.cpp undergrad.cpp postgrad.cpp prompt.cpp register_user.cpp admin.cpp main.cpp
	./out < testcases/input01.txt > testcases/output01.txt
	./out < testcases/input02.txt > testcases/output02.txt
	./out < testcases/input03.txt > testcases/output03.txt
	./out < testcases/input04.txt > testcases/output04.txt
	./out < testcases/input05.txt > testcases/output05.txt
	echo All set!
	rm -rf out
	clear

clean:
	rm *.o registration
	clear