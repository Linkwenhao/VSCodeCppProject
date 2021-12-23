#include <stdio.h>
#include <string.h>

//反转（逆置）字符串
void reverse(char *str)
{
    int len = strlen(str);
    if (len > 1)
    {
        char temp = str[0];
        str[0] = str[len - 1];
        str[len - 1] = '\0'; //最后一个字符在下次递归时不再处理
        reverse(str + 1);    //递归调用
        str[len - 1] = temp;
    }
}

int main()
{
    char str[20] = "abCdefg";
    reverse(str);   //传入的是指针,所以不用返回值保存
    printf("%s\n", str);
    return 0;
}