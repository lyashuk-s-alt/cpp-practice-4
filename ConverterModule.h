/**
 * @file ConverterModule.h
 * @brief Заголовковий файл модуля обчислення конвертації.
 */

#ifndef CONVERTER_MODULE_H
#define CONVERTER_MODULE_H

#include <string>

using namespace std;

/**
 * @brief Обчислює суму після конвертації за фіксованим курсом.
 */
double convert(double sum, string from, string to);

#endif // CONVERTER_MODULE_H
