ifdef debug
	DEBUG=-DDEBUG_MODE
endif

binary_clock : main.o led_line.o led_panel.o GPIO.o debug_GPIO.o
	g++ -g -std=c++11 -o binary_clock main.o led_line.o led_panel.o GPIO.o debug_GPIO.o
	make clean

main.o : src/main.cpp headers/common.h utils.o led_line.o led_panel.o GPIO.o debug_GPIO.o
	g++ $(DEBUG) -g -c -std=c++11 -o main.o src/main.cpp

utils.o : src/utils.cpp
	g++ -g -c -std=c++11 -o utils.o src/utils.cpp

led_line.o : src/led_line.cpp headers/led_line.h
	g++ -g -c -std=c++11 -o led_line.o src/led_line.cpp

led_panel.o : src/led_panel.cpp headers/common.h headers/led_panel.h led_line.o GPIO.o debug_GPIO.o
	g++ -g -c -std=c++11 -o led_panel.o src/led_panel.cpp

GPIO.o : src/GPIO.cpp headers/GPIO.h
	g++ -g -c -std=c++11 -o GPIO.o src/GPIO.cpp

debug_GPIO.o : src/debug_GPIO.cpp headers/GPIO.h
	g++ -g -c -std=c++11 -o debug_GPIO.o src/debug_GPIO.cpp

clean :
	rm *.o
