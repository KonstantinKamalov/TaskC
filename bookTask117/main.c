#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000    //ограничение количества символов для ввода
#define MAXSTR 10       //ограничение количества строк в буффере
#define MINCHARS 10     //минимальное количество символов в строке

/*
    Напишите программу для вывода всех строк входного потока,
    имеющих длину более 80 символов
*/

int getLine(char line[], int lim);
void copy(char to[], char from[]);

int main()
{
    /*
        strIndex - индекс буффера (строка)
        chIndex - индекс строки (символ)
        lineBuf - буффер строк размерностью в MAXSTR
        line - текущая строка
        len - длина текущей строки
    */

    int strIndex, chIndex, len;
    char line[MAXLINE];
    char lineBuf[MAXSTR][MAXLINE];

    /*Обнуляем буффер строк*/
    for(strIndex = 0; strIndex < MAXSTR; ++strIndex){
        for(chIndex = 0; chIndex < MAXLINE; ++chIndex){
            lineBuf[strIndex][chIndex] = 0;
            if(line[chIndex] != 0) line[chIndex] = 0;
        }
    }

    /*Заполняем строками буффер*/
    for(strIndex = 0; strIndex < MAXSTR; ++strIndex){
        printf("input>");
        if((len = getLine(line, MAXLINE)) > MINCHARS) copy(lineBuf[strIndex], line);
    }

    /*Печать результата*/
    printf("\n");
    for(strIndex = 0; strIndex < MAXSTR; ++strIndex){
        printf("%s", lineBuf[strIndex]);
    }

    return 0;
}

/*
    getLine: из входного потока посимвольно заполняет массив с размерностью lim.
    Возвращает количество символов в строке (не больше lim)
*/
int getLine(char line[], int lim){

    /*
        c - символ
        index - индекс массива line
        lim - предел массива
        line - массив символов для хранения символов из потока
    */

    int c, index;

    for(index = 0; index < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++index) line[index] = c;

    if(c == '\n'){
        line[index] = c;
        ++index;
    }

    line[index] = '\0';

    return index;
}

/*
    copy: копирует from в to
*/
void copy(char to[], char from[]){
    for(int i = 0; (to[i] = from[i]) != '\0'; ++i);
}
