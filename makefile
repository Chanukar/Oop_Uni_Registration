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
	clear
	g++ -std=c++11 prompt.cpp test_prompt.cpp -o prompt
	g++ -std=c++11 test_register_user.cpp register_user.cpp user.cpp undergrad.cpp postgrad.cpp -o register
	clear
	bash unittest
	rm -rf prompt
	rm -rf register


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
	./out < testcases/input06.txt > testcases/output06.txt
	g++ -std=c++11 prompt.cpp test_prompt.cpp -o prompt
	./prompt < testcases/unit_input01.txt > testcases/unit_output01.txt
	./prompt < testcases/unit_input02.txt > testcases/unit_output02.txt
	g++ -std=c++11 test_register_user.cpp register_user.cpp user.cpp undergrad.cpp postgrad.cpp -o register
	./register < testcases/unit_input03.txt > testcases/unit_output03.txt
	./register < testcases/unit_input04.txt > testcases/unit_output04.txt
	./register < testcases/unit_input05.txt > testcases/unit_output05.txt
	./register < testcases/unit_input06.txt > testcases/unit_output06.txt
	./register < testcases/unit_input07.txt > testcases/unit_output07.txt
	./register < testcases/unit_input08.txt > testcases/unit_output08.txt
	echo All set!
	rm -rf out
	rm -rf prompt
	rm -rf register
	clear

clean:
	rm *.o registration
	clear