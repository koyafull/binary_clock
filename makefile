binary_clock : main.o led_line.o
	g++ -o binary_clock main.o led_line.o

main.o : src/main.cpp led_line.o
	g++ -c -o main.o src/main.cpp

led_line.o : src/led_line.cpp headers/led_line.h
	g++ -c -o led_line.o src/led_line.cpp

clean :
	rm *.o
