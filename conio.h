#ifndef CONIO_LINUX_H
#define CONIO_LINUX_H

namespace conio {

  // Функция для инициализации
  void init(void);

  // Функция для освобождения ресурсов
  void reset(void);

  // Проверяет наличие нажатой клавиши без ожидания
  int kbhit(void);

  // Читает нажатую клавишу без вывода на экран
  int getch(void);
}

#endif //CONIO_LINUX_H
