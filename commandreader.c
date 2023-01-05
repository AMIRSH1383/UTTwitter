#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"
#define ZERO 0
#define ONE 1
#define true 2
char *commandReader(void)
{
    int command_line_length = ZERO;
    char *command_line = (char *)malloc(sizeof(char));
    *(command_line) = '0';
    char temp_char[ONE] = {' '};
    while (true)
    {
        temp_char[ZERO] = getchar();
        command_line_length++;
        command_line = (char *)realloc(command_line, sizeof(char) * command_line_length);
        command_line[command_line_length - ONE] = '\0';
        if (temp_char[ZERO] == ' ' || temp_char[ZERO] == '\n')
        {
            return command_line;
        }
        if (temp_char[ZERO] != ' ' && temp_char[ZERO] != '\n')
        {
            command_line[command_line_length - ONE] = temp_char[ZERO];
        }
    }
}