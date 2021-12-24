#include <stdio.h>
#include <stdlib.h>

// FILE *fopen(char *filename, char *mode);

int main()
{
    char name[100] = {0};
    printf("filename:");
    scanf("%s", name);
    char content[100] = {0};
    printf("content:");
    scanf("%s", content);

    FILE *fp = fopen(name, "w+");
    if (fp == NULL)
    {
        printf("fail");
        exit(0);
    }
    else
    {
        fputs(content, fp);
    }
    if (ferror(fp))
    {
        puts("fail");
    }
    else
    {
        puts("success");
    }
    fclose(fp);

    return 0;
}
