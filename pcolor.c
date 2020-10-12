/*
 * Author   : Hugo Torres <hugotorres@protonmail.com>
 * License  : BSD 2-Clause
 * Date     : 11/10/2020
 *
 * Description: Simple library for coloring C programs at the windows prompt.
 */

#include <stdio.h>
#include <windows.h>
#include "pcolor.h"

void pprint(char *phrase, int color_background, int color_font)
{
    HANDLE hStdout, hStdin;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD savedAttributes;

    // Salvando esquema de cores atual.
    GetConsoleScreenBufferInfo(hStdout, &consoleInfo);
    savedAttributes = consoleInfo.wAttributes;

    // Aplicando novo esquema na frase informada.
    SetConsoleTextAttribute(hStdout, color_background + color_font);
    printf("%s", phrase);

    // Retornando esquema anterior.
    SetConsoleTextAttribute(hStdout, savedAttributes);
}
