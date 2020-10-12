/*
 * Author   : Hugo Torres <hugotorres@protonmail.com>
 * License  : BSD 2-Clause
 * Date     : 2020/10/11
 *
 * Description: Simple library for coloring C programs at the windows prompt.
 *
 * Supported colors:
 *                  +-------------------+-------------------+
 *                  | Background        | Font Color        |
 *                  +-------------------+-------------------+
 *                  | BACK_BLACK        | FONT_BLACK        |
 *                  | BACK_BLUE         | FONT_BLUE         |
 *                  | BACK_GREEN        | FONT_GREEN        |
 *                  | BACK_AQUA         | FONT_AQUA         |
 *                  | BACK_RED          | FONT_RED          |
 *                  | BACK_PURPLE       | FONT_PURPLE       |
 *                  | BACK_YELLOW       | FONT_YELLOW       |
 *                  | BACK_WHITE        | FONT_WHITE        |
 *                  | BACK_GRAY         | FONT_GRAY         |
 *                  | BACK_LIGHT_BLUE   | FONT_LIGHT_BLUE   |
 *                  | BACK_LIGHT_GREEN  | FONT_LIGHT_GREEN  |
 *                  | BACK_LIGHT_AQUA   | FONT_LIGHT_AQUA   |
 *                  | BACK_LIGHT_RED    | FONT_LIGHT_RED    |
 *                  | BACK_LIGHT_PURPLE | FONT_LIGHT_PURPLE |
 *                  | BACK_LIGHT_YELLOW | FONT_LIGHT_YELLOW |
 *                  | BACK_LIGHT_WHITE  | FONT_LIGHT_WHITE  |
 *                  +-------------------+-------------------+
 *
 * way of use:
 *              pprint(string, background color, font color);
 *
 * Example:
 *              pprint("Hello world\n", BACK_BLACK, FONT_LIGHT_GREEN);
 */

#include <stdio.h>
#include <windows.h>
#include "pcolor.h"

void pprint(char *phrase, int background_color, int font_color)
{
    HANDLE hStdout, hStdin;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD savedAttributes;

    // Saving current color scheme.
    GetConsoleScreenBufferInfo(hStdout, &consoleInfo);
    savedAttributes = consoleInfo.wAttributes;

    // Applying new scheme to the entered sentence.
    SetConsoleTextAttribute(hStdout, background_color + font_color);
    printf("%s", phrase);

    // Returning previous schema.
    SetConsoleTextAttribute(hStdout, savedAttributes);
}
