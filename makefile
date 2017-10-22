binary_clock : main.o led_line.o led_panel.o
	g++ -o binary_clock main.o led_line.o led_panel.o

main.o : src/main.cpp led_line.o led_panel.o
	g++ -c -o main.o src/main.cpp

led_line.o : src/led_line.cpp headers/led_line.h
	g++ -c -o led_line.o src/led_line.cpp

led_panel.o : src/led_panel.cpp headers/led_panel.h led_line.o
	g++ -c -o led_panel.o src/led_panel.cpp

clean :
	rm *.o
