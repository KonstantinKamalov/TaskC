#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000
#define IN 1
#define OUT 0

/*
    Напишите программу для удаления лишних пробелов и табуляций (функция trim())
    в каждой поступающей с входного потока строки.
    todo: реализовать удаление пустой строки
*/

int getLine(char line[], int lim);
void trim(char line[], int len);
void clearArr(char line[], int lim);
void copy(char to[], char from[]);
int countLen(char line[]);

int main()
{
    int len, count;
    char str[MAXLINE];

    clearArr(str, MAXLINE);

    count = 0;
    while((len = getLine(str, MAXLINE)) > 0 ){
        count = countLen(str);
        printf("\n%d, %d - %s", len, count, str);
        trim(str, len);
        count = countLen(str);
        printf("%d - %s\n",count, str);
    }

    return 0;
}

/*getLine: заполняет массив символами из потока формируя при этом строку, возвращает длину введенной строки*/
int getLine(char line[], int lim){
    int c, index;

    for(index = 0; index < lim-1 && (c = getchar()) != EOF && c != '\n'; ++index) line[index] = c;

    if('\n' == c){
        line[index] = c;
        ++index;
    }
    line[index] = '\0';
    return index;
}

/*clearArr: заполняет массив нулями*/
void clearArr(char line[], int lim){
    for(int i = 0; i < lim; ++i) line[i] = 0;
}

/*trim: удаляет лишние пробелы и табы в начале, в конце, в самом тексте*/
void trim(char line[], int len){
    int start, end, i, status, count;
    char temp[len];
    clearArr(temp, len);
    copy(temp, line);
    clearArr(line, len);

    /*считаем с начала и с конца пробелы и табы*/
    for(start = 0; start < len; ++start){
        if(temp[start] != ' ' && temp[start] != '\t') break;
    }

    for(end = (len-2); end >= 0; --end){
        if(temp[end] != ' ' && temp[end] != '\t') break;
    }

    //printf("\nstart: %d end: %d\n", start, end);

    status = OUT;
    for(i = start, count = 0; i <= end; ++i){
        if(temp[i] != ' ' && temp[i] != '\t'){
            status = IN;
            line[count] = temp[i];
            ++count;
        }else if(status == IN && (temp[i] == ' ' || temp[i] == '\t')){
            status = OUT;
            line[count] = temp[i];
            ++count;
        }
    }
    line[count] = '\n';
    line[count+1] = '\0';
}

/* copy: копируем из from в to*/
void copy(char to[], char from[]){
    for(int i = 0; (to[i] = from[i]) != '\0'; ++i);
}

/*countLen: подсчет символов в строке (включая \n и \0)*/
int countLen(char line[]){
    int i;
    for(i = 1; line[i] != '\0'; ++i);
    if(line[i] == '\0') ++i;
    return i;
}




