#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 20

//кодировка ЮТФ8
/*getLine: считывает строку в line, возвращает ее длину*/
int getLine(char line[], int maxLine);
/*copy: копирует строку 'from' в 'to'; длина to считается достаточной*/
void copy(char to[], char from[]);

/*
    вывод самой длинной строки в потоке
    *   доработать главный модуль программы так, чтобы она могла печатать самую
        длинную строку (в пределах ограничения) и ее размер (без учета ограничения)
*/

int main()
{
    /*длина текущей строки*/
    int len;

    /*текущая максимальная длина*/
    int max;

    /*текущая введенная строка*/
    char line[MAXLINE];

    /*самая длинная строка из введенных*/
    char longest[MAXLINE];

    /*заполняем массивы нулями*/
    for(int i = 0; i < MAXLINE; ++i) line[i] = longest[i] = 0;

    len = max = 0;
    /*если есть строка и она больше предыдушей, копируем*/
    while((len = getLine(line, MAXLINE)) > 0){
        if(len > max){
            max = len;
            copy(longest, line);
        }
    }

    /*если была непустая строка выводим результат*/
    if(max > 0) printf("line size : %d\n%s", max, longest);
    return 0;
}

/*
    getLine: считывает строку в s, возвращает ее длину
    s является указателем на начало массива (не копируется),
    поэтому значения s можно изменять в функции
*/
int getLine(char s[], int lim){
    int c, i, j;

    /*
        c - символ
        j - индекс массива символов строки с учетом MAXLINE (для вывода)
        i - индекс массива символов строки без учета MAXLINE (общий подсчет символов строки)
    */

    for(i = j = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if(i < lim - 1) {
            s[j] = c;
            ++j;
        }

    if(c == '\n'){
        s[j] = c;
        ++j;
        ++i;
    }

    s[j] = '\0';
    return i;
}

/*
    copy: копирует строку 'from' в 'to'; длина to считается достаточной
*/
void copy(char to[], char from[]){
    int index;
    index = 0;

    while((to[index] = from[index]) != '\0') ++index;
}
