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
clean:
	rm $(LF).o $(RES)
```
