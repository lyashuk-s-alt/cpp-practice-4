#ifndef CURRENCY_CONVERTER_H
#define CURRENCY_CONVERTER_H

#include <string>

struct CurrencyRate {
    std::string fromCurrency;
    std::string toCurrency;
    double rate;
};

double convertCurrency(double amount, const std::string& from, const std::string& to);

#endif // CURRENCY_CONVERTER_H
