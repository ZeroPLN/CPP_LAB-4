#pragma once
#include <iostream>

class Money {
public:
  // конструкторы
  Money();
  Money(unsigned int r, short int k);
  Money(const Money& m);
  Money(double amount);

  // геттеры
  unsigned int get_rubles() const { return rubles; }
  short int get_kopeks() const { return kopeks; }
  void set_rubles(unsigned int r);
  void set_kopeks(short int k);

  // методы
  Money subtract(const Money& other) const;
  bool equals(const Money& other) const;
  void normalize();

  // перегрузка операторов
  friend std::ostream& operator<<(std::ostream& out, const Money& m);

  // валидация
  bool is_valid() const;

  private:
  unsigned int rubles;
  short int kopeks;
};
