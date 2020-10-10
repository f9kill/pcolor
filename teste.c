/*
* Programa que mostra todas as cores, possiveis
* da biblioteca windows.h
*/

#include <stdio.h>
#include <windows.h>

int main (void)
{
     int count;
     HANDLE hConsole;
     hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

     for (count=0; count<257; count++) {
        SetConsoleTextAttribute(hConsole, count);
        printf ("This color combination has the number of %i\n", count);
     }

     SetConsoleTextAttribute(hConsole, 15);
     system ("pause");
     return 0;
}
