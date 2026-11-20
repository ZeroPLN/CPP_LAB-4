#include "Money.h"
#include <iostream>

bool InputVal(int& value) {
    if (std::cin >> value) return true;
    std::cout << "Ошибка ввода\n";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    return false;
}

int main() {
  setlocale(LC_ALL, "ru_RU.UTF-8");

  std::cout << "Тестирование класса Money\n";
  std::cout << "Доступные действия:\n";
  std::cout << "1. Создать объект через конструктор по умолчанию\n";
  std::cout << "2. Создать объект через конструктор с параметрами\n";
  std::cout << "3. Создать объект через конструктор копирования\n";
  std::cout << "4. Создать объект через конструктор из double\n";
  std::cout << "5. Проверить метод вычитания\n";
  std::cout << "6. Проверить метод сравнение\n";
  std::cout << "7. Проверить сеттеры\n";
  std::cout << "8. Проверить валидацию\n";
  std::cout << "-1. Выход\n";

  while (true) {
    std::cout << "\nВыберите действие: ";
    int action;
    std::cin >> action;

    if (action == -1) {
      break;
    }

    switch (action) {
    case 1: {
      Money defaultMoney;
      std::cout << "Объект по умолчанию: " << defaultMoney << std::endl;
      break;
    }

    case 2: {
      int rubles;
      int kopeks;
      while (true) {
        std::cout << "Введите рубли: ";
        InputVal(rubles);
        if (rubles < 0) {
          std::cout << "Рубли не могут быть отрицательными, попробуйте снова\n";
          continue;
        }
        std::cout << "Введите копейки (0-99): ";
        InputVal(kopeks);
        if (kopeks < 0 || kopeks > 99) {
          std::cout << "Копейки должны быть в диапазоне (0-99), попробуйте снова\n";
          continue;
        }
        break;
      }
      Money m(rubles, kopeks);
      std::cout << "Объект создан: " << m << std::endl;
      break;
    }

    case 3: {
      Money original(100, 50);
      std::cout << "Исходный объект: " << original << std::endl;
      Money copy(original);
      std::cout << "Копия объекта: " << copy << std::endl;
      break;
    }

    case 4: {
      double amount;
      while (true) {
        std::cout << "Введите сумму (double): ";
        if (!(std::cin >> amount)) {
          std::cout << "Ошибка ввода, попробуйте снова\n";
          std::cin.clear();
          std::cin.ignore(10000, '\n');
          continue;
        }
        if (amount < 0) {
          std::cout << "Сумма не может быть отрицательной, попробуйте снова\n";
          continue;
        }
        break;
      }
      Money m(amount);
      std::cout << "Объект создан из double: " << m << std::endl;
      break;
    }

    case 5: {
      int r1;
      int k1;
      int r2;
      int k2;
      while (true) {
        std::cout << "Введите первую сумму\n";
        std::cout << "Рубли: ";
        InputVal(r1);
        std::cout << "Копейки (0-99): ";
        InputVal(k1);
        std::cout << "Введите вторую сумму\n";
        std::cout << "Рубли: ";
        InputVal(r2);
        std::cout << "Копейки (0-99): ";
        InputVal(k2);
        if (r1 < 0 || r2 < 0) {
          std::cout << "Сумма не может быть отрицательной, попробуйте снова\n";
          continue;
        }
        if (k1 < 0 || k1 > 99 || k2 < 0 || k2 > 99) {
          std::cout << "Копейки должны быть в диапазоне (0-99), попробуйте снова\n";
          continue;
        }
        if (r1 * 100 + k1 < r2 * 100 + k2) {
          std::cout << "Результат вычитания не может быть отрицательным, попробуйте снова\n";
          continue;
        }
        break;
      }
      Money m1(r1, k1);
      Money m2(r2, k2);
      std::cout << "Первая сумма: " << m1 << std::endl;
      std::cout << "Вторая сумма: " << m2 << std::endl;
      Money result = m1.subtract(m2);
      std::cout << "Результат вычитания: " << result << std::endl;
      break;
    }

    case 6: {
      int r1;
      int k1;
      int r2;
      int k2;
      while (true) {
        std::cout << "Введите первую сумму\n";
        std::cout << "Рубли: ";
        InputVal(r1);
        std::cout << "Копейки (0-99): ";
        InputVal(k1);
        std::cout << "Введите вторую сумму\n";
        std::cout << "Рубли: ";
        InputVal(r2);
        std::cout << "Копейки (0-99): ";
        InputVal(k2);
        if (r1 < 0 || r2 < 0) {
          std::cout << "Рубли не могут быть отрицательными, попробуйте снова\n";
          continue;
        }
        if (k1 < 0 || k1 > 99 || k2 < 0 || k2 > 99) {
          std::cout << "Копейки должны быть в диапазоне (0-99), попробуйте снова\n";
          continue;
        }
        break;
      }
      Money m1(r1, k1);
      Money m2(r2, k2);
      std::cout << "Первая сумма:  " << m1 << std::endl;
      std::cout << "Вторая сумма:  " << m2 << std::endl;
      if (m1.equals(m2)) {
        std::cout << "Суммы РАВНЫ\n";
      } else {
        std::cout << "Суммы НЕ равны\n";
      }
      break;
    }

    case 7: {
      Money testMoney(100, 50);
      int rubles, kopeks;
      std::cout << "Исходный объект: " << testMoney << std::endl;
      while (true) {
        std::cout << "Введите новое количество рублей: ";
        InputVal(rubles);
        if (rubles < 0) {
          std::cout << "Рубли не могут быть отрицательными, попробуйте снова\n";
          continue;
        }
        break;
      }
      testMoney.set_rubles(rubles);
      std::cout << "После изменения рублей: " << testMoney << std::endl;
      while (true) {
        std::cout << "Введите новое количество копеек (0-99): ";
        InputVal(kopeks);
        if (kopeks < 0 || kopeks > 99) {
          std::cout << "Копейки должны быть в диапазоне (0-99), попробуйте снова\n";
          continue;
        }
        break;
      }
      testMoney.set_kopeks(kopeks);
      std::cout << "После изменения копеек: " << testMoney << std::endl;
      break;
    }

    case 8: {
      std::cout << "Тестирование валидации:\n";
      std::cout << "\n1. Попытка создать Money с копейками > 99:\n";
      int r1, k1;
      std::cout << "Введите рубли: ";
      InputVal(r1);
      std::cout << "Введите копейки (например, 150): ";
      InputVal(k1);
      std::cout << "Пытаемся создать Money(" << r1 << ", " << k1 << ")\n";
      try {
        Money invalid(r1, k1);
        std::cout << "Объект создан: " << invalid << std::endl;
      } catch (const std::invalid_argument& e) {
        std::cout << "Поймано исключение: " << e.what() << std::endl;
      }
      std::cout << "\n2. Попытка создать Money из отрицательного double:\n";
      double amount;
      std::cout << "Введите сумму (например, -50.0): ";
      while (!(std::cin >> amount)) {
        std::cout << "Ошибка ввода, попробуйте снова: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
      }
      std::cout << "Пытаемся создать Money(" << amount << ")\n";
      try {
        Money invalid(amount);
        std::cout << "Объект создан: " << invalid << std::endl;
      } catch (const std::invalid_argument& e) {
        std::cout << "Поймано исключение: " << e.what() << std::endl;
      }
      std::cout << "\n3. Попытка вычесть большее число из меньшего:\n";
      int rA;
      int kA;
      int rB;
      int kB;
      std::cout << "Первая сумма\n";
      std::cout << "Рубли: ";
      InputVal(rA);
      std::cout << "Копейки: ";
      InputVal(kA);
      std::cout << "Вторая сумма (должна быть больше первой)\n";
      std::cout << "Рубли: ";
      InputVal(rB);
      std::cout << "Копейки: ";
      InputVal(kB);
      std::cout << "Пытаемся вычислить ("
        << rA << " руб. " << kA << " коп.) - ("
        << rB << " руб. " << kB << " коп.)\n";
      try {
        Money mA(rA, kA);
        Money mB(rB, kB);
        Money result = mA.subtract(mB);
        std::cout << "Результат: " << result << std::endl;
      } catch (const std::exception& e) {
        std::cout << "Поймано исключение: " << e.what() << std::endl;
      }
      std::cout << "\n4. Попытка установить копейки > 99:\n";
      int r4, k4;
      std::cout << "Введите рубли для объекта: ";
      InputVal(r4);
      std::cout << "Введите копейки для set_kopeks (например, 150): ";
      InputVal(k4);
      std::cout << "Создаём Money(" << r4 << ", 0) и вызываем set_kopeks(" << k4 << ")\n";
      try {
        Money m(r4, 0);
        m.set_kopeks(k4);
        std::cout << "Объект: " << m << std::endl;
      } catch (const std::invalid_argument& e) {
        std::cout << "Поймано исключение: " << e.what() << std::endl;
      }
      std::cout << "\n5. Проверка is_valid() на корректном объекте:\n";
      int r5, k5;
      while (true) {
        std::cout << "Введите рубли: ";
        InputVal(r5);
        if (r5 < 0) {
          std::cout << "Рубли не могут быть отрицательными, попробуйте снова\n";
          continue;
        }
        std::cout << "Введите копейки (0-99): ";
        InputVal(k5);
        if (k5 < 0 || k5 > 99) {
          std::cout << "Копейки должны быть в диапазоне (0-99), попробуйте снова\n";
          continue;
        }
        break;
      }
      Money ok(r5, k5);
      std::cout << "Объект: " << ok
        << " | is_valid() = " << (ok.is_valid() ? "true" : "false") << "\n";
      break;
    }

    default:
        std::cout << "Неверный выбор действия\n";
        break;
    }
  }

  return 0;
}