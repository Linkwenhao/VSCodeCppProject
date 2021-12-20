#include <stdio.h>
#include <string.h>

int main()
{
    char string[30] = {0};
    scanf("%s", &string);
    const char *str = string;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        printf("%c", *(str + i) - 4);
    }
}