#include "conio.h"
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <iostream>
#include <sys/ioctl.h>

namespace conio {
    static struct termios old_termios; //Для сохранения старых настроек терминала

    void init() {
        tcgetattr(STDIN_FILENO, &old_termios); //Сохраняем старые настройки

        struct termios new_termios = old_termios;
        new_termios.c_lflag &= ~(ICANON | ECHO); // Отключаем канонический режим и эхо
        tcsetattr(STDIN_FILENO, TCSANOW, &new_termios); // Устанавливаем новые настройки
    }

    void reset() {
        tcsetattr(STDIN_FILENO, TCSANOW, &old_termios); // Восстанавливаем старые настройки
    }


    int kbhit() {
        int byteswaiting;
        ioctl(STDIN_FILENO, FIONREAD, &byteswaiting);
        return byteswaiting > 0;
    }

    int getch() {
        char buf[3];
        int bytes_read = read(STDIN_FILENO, buf, 3);
        if (bytes_read == 1) {
            if (buf[0] == '\033') return 27;
            else return buf[0];
        } else if (bytes_read > 0) {
            if (buf[0] == '\033' && buf[1] == '[') {
                if (buf[2] == 'C') return 77;
                if (buf[2] == 'D') return 75;
            }
            return -1; // Ошибка обработки escape-последовательности
        }
        return -1; // Ошибка
    }
}
