main: main.cpp
	g++ -g -Wall -Weffc++ -Wextra  -std=c++2b *.cpp -o main

main.cpp:

clean:
	compiledb make

