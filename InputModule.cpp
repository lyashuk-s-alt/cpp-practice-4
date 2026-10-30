/**
 * @file InputModule.cpp
 * @brief Реалізація функцій введення даних з перевіркою коректності.
 */

#include "InputModule.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void input(double& sum, string& from, string& to) {
    cout << "Сума: ";
    
    // Перевірка 1: Чи введене значення є числом
    if (!(cin >> sum)) {
        throw invalid_argument("Критична помилка: Введене значення суми не є числом!");
    }

    // Перевірка 2: Чи не є сума від'ємною
    if (sum < 0) {
        throw invalid_argument("Помилка: Сума для конвертації не може бути від'ємною!");
    }

    cout << "З якої валюти (USD, EUR, UAH): ";
    cin >> from;

    cout << "В яку валюту (USD, EUR, UAH): ";
    cin >> to;
}

