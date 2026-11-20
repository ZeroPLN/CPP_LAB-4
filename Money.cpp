#include "Money.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

Money::Money() : rubles(0), kopeks(0) { 
}


Money::Money(unsigned int r, short int k) : rubles(r), kopeks(k)
{
  if (kopeks < 0 || kopeks > 99) {
    throw std::invalid_argument("Некорректное количество копеек");
  }
  normalize();
}

Money::Money(const Money &m) : rubles(m.rubles), kopeks(m.kopeks) {
}

Money::Money(double amount) {
  if (amount < 0) {
    throw std::invalid_argument("Сумма не может быть отрицательной");
  }
  long long total = std::llround(amount * 100);   //
  rubles = static_cast<unsigned int>(total / 100);
  kopeks = static_cast<short int>(total % 100);
  normalize();
}

void Money::set_rubles(unsigned int r) {
  rubles = r;
  normalize();
}

void Money::set_kopeks(short int k) {
  if (k < 0 || k > 99) {
    throw std::invalid_argument("Копейки должны быть в диапозоне (0-99)");
  }
  kopeks = k;
  normalize();
}

Money Money::subtract(const Money &other) const {
  // Преобразуем в общий формат (копейки) для вычитания
  long long this_kopeks = static_cast<long long>(rubles) * 100 + kopeks;
  long long other_kopeks = static_cast<long long>(other.rubles) * 100 + other.kopeks;
  long long result_kopeks = this_kopeks - other_kopeks;

  // Проверка, что результат не отрицательный
  if (result_kopeks < 0) {
    throw std::runtime_error("Результат вычитания не может быть отрицательным");
  }

  // Преобразуем обратно в рубли и копейки
  Money result;
  result.rubles = static_cast<unsigned int>(result_kopeks / 100);
  result.kopeks = static_cast<short int>(result_kopeks % 100);
  return result;
}

bool Money::equals(const Money& other) const {
  return rubles == other.rubles && kopeks == other.kopeks;
}

void Money::normalize() {
  rubles += kopeks / 100;
  kopeks %= 100;
}

bool Money::is_valid() const {
  return (kopeks >= 0 && kopeks <= 99);
}

std::ostream &operator<<(std::ostream &out, const Money &m) {
  out << m.rubles << " руб. " << m.kopeks << " коп.";
  return out;
}
