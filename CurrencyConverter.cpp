#include "CurrencyConverter.h"
#include <stdexcept>
#include <algorithm>

const CurrencyRate RATES[] = {
    {"USD", "UAH", 41.50},
    {"EUR", "UAH", 44.80},
    {"UAH", "USD", 0.024},
    {"UAH", "EUR", 0.022}
};
const int RATES_COUNT = sizeof(RATES) / sizeof(RATES);

double convertCurrency(double amount, const std::string& from, const std::string& to) {
    if (amount < 0) {
        throw std::invalid_argument("Помилка: Сума для конвертації не може бути від'ємною!");
    }

    std::string fromUpper = from;
    std::string toUpper = to;
    std::transform(fromUpper.begin(), fromUpper.end(), fromUpper.begin(), ::toupper);
    std::transform(toUpper.begin(), toUpper.end(), toUpper.begin(), ::toupper);

    if (fromUpper == toUpper) {
        return amount;
    }

    for (int i = 0; i < RATES_COUNT; ++i) {
        if (RATES[i].fromCurrency == fromUpper && RATES[i].toCurrency == toUpper) {
            return amount * RATES[i].rate;
        }
    }

    throw std::runtime_error("Помилка: Курс для пари " + fromUpper + " -> " + toUpper + " не знайдено у базі даних!");
}
