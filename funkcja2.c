#include <stdio.h>
#include "plik.h"

int znajdzOstatniZnak(FILE *plik, char szukanyZnak)
{
    int numerAktualnejLinii = 0;
    int ostatniaPozycjaZnaku = -1;

    char *linia = NULL;
    size_t rozmiarLinii = 0;

    while (getline(&linia, &rozmiarLinii, plik) != -1)
    {
        numerAktualnejLinii++;
        char *pozycjaZnaku = strrchr(linia, szukanyZnak);

        if (pozycjaZnaku != NULL)
        {
            ostatniaPozycjaZnaku = (int)(pozycjaZnaku - linia);
            numerlinii = numerAktualnejLinii;
        }
    }

    free(linia);
    return ostatniaPozycjaZnaku + 1;
}
