/**
 * @file ConverterModule.cpp
 * @brief Реалізація бізнес-логіки конвертації з обробкою помилок.
 */

#include "ConverterModule.h"
#include <stdexcept>
#include <algorithm>

using namespace std;

double convert(double sum, string from, string to) {
    // Переводимо коди у верхній регістр для надійності порівняння
    transform(from.begin(), from.end(), from.begin(), ::toupper);
    transform(to.begin(), to.end(), to.begin(), ::toupper);

    if (from == to) {
        return sum;
    }

    // Фіксовані курси валют
    if (from == "USD" && to == "UAH") return sum * 41.50;
    if (from == "EUR" && to == "UAH") return sum * 44.80;
    if (from == "UAH" && to == "USD") return sum * 0.024;
    if (from == "UAH" && to == "EUR") return sum * 0.022;

    // Якщо введено неправильну валюту або курс відсутній
    throw runtime_error("Помилка: Непідтримувана валюта або курс для пари " + from + " -> " + to + " не знайдено!");
}
