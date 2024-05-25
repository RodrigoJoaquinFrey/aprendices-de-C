#include <time.h>
#include <stdio.h>
#include "utils.h"

int calcularEdad(char *fechaNacimiento) {
  int year, month, day;
    sscanf(fechaNacimiento, "%d-%d-%d", &year, &month, &day);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int edad = tm.tm_year + 1900 - year;
    if (tm.tm_mon + 1 < month || (tm.tm_mon + 1 == month && tm.tm_mday < day)) {
        edad--;
    }
    return edad;
}