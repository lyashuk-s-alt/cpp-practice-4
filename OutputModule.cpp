/**
 * @file OutputModule.cpp
 * @brief Реалізація форматованого виведення.
 */

#include "OutputModule.h"
#include <iostream>

using namespace std;

void print(double sum, string from, double res, string to) {
    cout << "\n=== Результат конвертації ===\n";
    cout << sum << " " << from << " = " << res << " " << to << "\n";
}
