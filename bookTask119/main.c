#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

void reverse(char str[]);
int getLine(char str[], int lim);
/*
    программа теста функции reverse(s).
*/
int main()
{
    char line[MAXLINE];
    int l,index;

    for(index = 0; index < MAXLINE; ++index) line[index] = 0;

    l = getLine(line, MAXLINE);
    printf("%d - %s\n", l, line);
    reverse(line);
    printf("%d - %s\n", l, line);
    return 0;
}

/*
    reverse: переписывает строковый аргумент str в обратном порядке
*/

void reverse(char str[]){

    int i, j, strSize;
    char temp;

    /*считаем кол-во символов в str без \n и \0*/
    for(strSize = 1; str[strSize] != '\n'; strSize++);

    /*меняем конец и начало местами, и так до середины*/
    temp = 0;
    for(i = 0, j = strSize - 1; i < j; ++i,--j){
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
    }
}

/*
    getLine: вводим символы из потока в str + \n\0
*/

int getLine(char str[], int lim){

    int c, i;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) str[i] = c;

    if('\n' == c) {
        str[i] = c;
        ++i;
    }
    str[i] = '\0';

    return i;
}


