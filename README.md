# Linux Conio Library
English: A library that implements the functionality of the kbhit and getch commands from conio in DOS systems on GNU/Linux / Русский:  Библиотека, реализующая функционал команд kbhit и getch из conio в DOS-системах в GNU/Linux

How do I turn this into a library and link it to a file / Как превратить это в библиотеку и связать с файлом:

Static / Статическая:

Copy this text to the Makefile / Скопируйте этот текст в Makefile
```
LF = conio
IF = File.cpp
RES = result

all:
	g++ -c $(LF).cpp
	ar rcs lib$(LF).a $(LF).o
	g++ $(IF) -L. -l$(LF) -o $(RES) -static
run:
	./$(RES)
clean:
	rm $(LF).o $(RES)
```

Dynamic / Динамическая:

Copy this text to the Makefile / Скопируйте этот текст в Makefile
```
LF = conio
IF = File.cpp
RES = result

all:
	g++ -c $(LF).cpp -fPIC
	g++ -shared $(LF).o -o lib$(LF).so
	g++ $(IF) -L. -l$(LF) -o $(RES)
run:
	export LD_LIBRARY_PATH=. && ./$(RES)
install:
	sudo cp conio.h /usr/include
	sudo cp conio.h /usr/include
clean:
	rm $(LF).o $(RES)
```

Example of use in a project / Пример использования в проекте:
```
#include <iostream>
#include "conio.h"

int main() {
	conio::init();
	atexit(conio::reset);
	while (true){ 
		if (conio::kbhit()) {
			switch (static_cast<int>(conio::getch())) {
				case 27:
					system("clear");
					return 0;
				case 75:
					std::cout << "Left button" << endl;
					break;
				case 77:
					std::cout << "Right button" << endl;
					break;
			}
		}
	}
	return 0;
}
```
