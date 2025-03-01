# Linux_Conio
English: A library that implements the functionality of the kbhit and getch commands on GNU/Linux systems / Русский:  Библиотека, реализующая функционал команд kbhit и getch в системах GNU/Linux

Как превратить это в библиотеку и связать с файлом:
Статическая:
Скопируйте этот текст в Makefile
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

Статическая:
Скопируйте этот текст в Makefile
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
