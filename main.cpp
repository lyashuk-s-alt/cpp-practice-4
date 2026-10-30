/**
 * @file main.cpp
 * @brief Головний модуль програми з обробкою винятків try/catch.
 */

#include <iostream>
#include <string>
#include "InputModule.h"
#include "ConverterModule.h"
#include "OutputModule.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    double sum = 0.0;
    string from = "";
    string to = "";
    double res = 0.0;

    cout << "=== Програма конвертації валют із захистом від помилок ===\n\n";

    try {
        // 1. Введення даних
        input(sum, from, to);

        // 2. Обчислення
        res = convert(sum, from, to);

        // 3. Виведення результату
        print(sum, from, res, to);
    }
    catch (const invalid_argument& ex) {
        // Перехоплення помилок некоректного типу даних чи від'ємної суми
        cerr << "\n[Помилка валідації]: " << ex.what() << "\n";
    }
    catch (const runtime_error& ex) {
        // Перехоплення помилок відсутності курсів валют
        cerr << "\n[Помилка виконання]: " << ex.what() << "\n";
    }
    catch (...) {
        cerr << "\n[Невідома помилка системи] Програма буде закрита.\n";
    }

    cout << "\nПрограма успішно завершила роботу без аварійного падіння.\n";
    return 0;
}
