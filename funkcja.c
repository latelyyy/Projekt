#include <string.h>
#include <stdio.h>
#include "plik.h"
int znajdzPozycje(char *tekst, char znak, int pierwsza)
{
    int pozycja = -1;
    int dlugosc = 0;

    while (tekst[dlugosc] != '\0')
    {
        dlugosc++;
    }

    for (int i = 0; i < dlugosc; ++i)
    {
        if (tekst[i] == znak)
        {
            pozycja = i + 1;
            break;
        }
    }

    return pozycja;
}
