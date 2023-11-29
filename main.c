#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funkcja.c"
#include "funkcja2.c"
#include "plik.h"
int znajdzPozycje(char *tekst, char znak, int pierwsza);
int znajdzOstatniZnak(FILE *plik, char znak);
int main()
{
    setlocale(LC_ALL, "");
    FILE *fd = fopen("tekst.txt", "r, ccs=WINDOWS-1250");
    if (fd == NULL)
    {
        printf("blad otwarcia pliku");
        return 0;
    }

    char *tekst = NULL;
    size_t rozmiar = 0;
    size_t rozmiar2;

    printf("Podaj znak, ktorego pozycje chcesz znalezc: ");
    char znak;
    znak = getchar();
    while (getchar() != '\n')
        ;
    int pierwsza;
    int wynik2;
    printf("Czy szukac pierwsze (1) czy ostatnie (0) wystapienie znaku? ");
    wynik2 = scanf("%d", &pierwsza);

    if (wynik2 != 1)
    {
        printf("blad wczytywania\n");
        free(tekst);
        return 1;
    }

    if (pierwsza != 1 && pierwsza != 0)
    {
        printf("blad wczytywania, podaj 1 lub 0\n");
        free(tekst);
        return 1;
    }
    int pozycja;
    if (pierwsza == 1)
    {
        while ((rozmiar2 = getline(&tekst, &rozmiar, fd)) != -1)
        {
            pozycja = znajdzPozycje(tekst, znak, pierwsza);
            if (pozycja != -1)
            {
                break;
            }
            numerlinii++;
        }
    }
    else if (pierwsza == 0)
    {
        pozycja = znajdzOstatniZnak(fd, znak);
    }
    fclose(fd);
    if (pozycja != -1)
    {
        if (pierwsza)
        {
            printf("Pierwsze wystapienie znaku znalezione na pozycji: %d w linii: %d\n", pozycja, numerlinii);
        }
        else
        {
            printf("Ostatnie wystapienie znaku znalezione na pozycji: %d w linii: %d\n", pozycja, numerlinii);
        }
    }
    else
    {
        printf("Znak nie wystapil w tekscie.\n");
    }
    free(tekst);
    return 0;
}
