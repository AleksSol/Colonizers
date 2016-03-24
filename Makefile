all: obj app

main: my_main app
	touch main
obj:
	g++ -c -Wall -Werror -std=c++11 -I include/ src/*.cpp
app: 
	g++ -Wall -Werror -std=c++11 *.o -o App
clear: 
	rm *.o App
my_main:
	g++ -c -Wall -Werror -std=c++11 -I include/ src/main.cpp
help:
	echo "Create application\nobj to create *.o \napp to create application\nclear to clear created file\nmain to create main.o\ntest to start valgrind\nrun to run application\n "
test:
	valgrind ./App
run: 
	./App
