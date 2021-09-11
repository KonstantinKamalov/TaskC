#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int getLine(char line[], int lim);
void clearArr(char line[], int lim);
void detab(char line[], int numSpaces);
int trim(char line[], int len);
void copyArr(char to[], char from[]);


int main()
{
    int len, temp;
    char str[MAXLINE];

    len = temp = 0;
    while((len = getLine(str, MAXLINE)) > 0){
        detab(str, 3);
        len = trim(str, len);
        printf("%d - %s\n", len, str);
    }
    return 0;
}

int getLine(char line[], int lim){
    int c, i;

    clearArr(line, lim);

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) line[i] = c;

    if('\n' == c) {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}

void clearArr(char line[], int lim){
    for(int i = 0; i < lim; ++i) line[i] = 0;
}

/*
    detab: заменяет табуляции в строке нужным количеством пробелов numSpaces
*/
void detab(char line[], int numSpaces){

}

int trim(char line[], int len){

    int i, j, start, end;
    char temp[len];

    clearArr(temp, len);
    copyArr(temp, line);

    for(start = 0; (temp[start] == ' ' || temp[start] == '\t') && start < len; ++start);
    for(end = (len-2); (temp[end] == ' ' || temp[end] == '\t') && end >= 0; --end);
    //printf("%d %d\n", start, end);

    clearArr(line, len);

    for(i = 0, j = start; i < len && j <= end; ++i,++j) line[i] = temp[j];

    line[i] = '\n';
    ++i;
    line[i] = '\0';
    return i;
}

void copyArr(char to[], char from[]){
    for(int i = 0; (to[i] = from[i]) != '\0'; ++i);
}
