#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int getLine(char line[], int lim);
void clearArr(char line[], int lim);
int detab(char line[], int numSpaces);
int trim(char line[], int len);
int splice(int index, char line[], char subLine[]);
void removeByIndex(char line[], int index);
int getLenght(char line[]);
void copyArr(char to[], char from[]);

/*
    ��������� detab, ������� �������� ������� ��������� �� ������� ������
    ��������������� ����������� �������� �� ��������� ������� ���������.
    ��������� ����� ������������� ������ n ��������.
*/

int main()
{
    int len;
    char str[MAXLINE];

    len = 0;
    while((len = getLine(str, MAXLINE)) > 0){
        len = trim(str, len);
        printf("%d - %s\n", len, str);
        len = detab(str, 5);
        printf("%d - %s\n", len, str);
    }
    return 0;
}

int getLine(char line[], int lim){
    if(lim < 0) return -1;
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
    if(lim < 0) return;
    for(int i = 0; i < lim; ++i) line[i] = 0;
}

/*
    detab: �������� ��������� � ������ ������ ����������� �������� numSpaces
*/
int detab(char line[], int numSpaces){
    if(numSpaces < 0) return;
    int i, len, lineLen;

    /*��������� ������ � ������ ����������� ��������*/
    len = numSpaces+1;
    char spaces[len];
    clearArr(spaces,len);
    for(i = 0; i < len-1; ++i) spaces[i] = ' ';

    lineLen = getLenght(line);
    /*todo �������� splice ���, ����� �� �� �������� � ������ �������, � ������� ������ ������ �� ��������� ������*/
    for(i = 0; i <= lineLen; ++i) {
        if('\t' == line[i]) {
            removeByIndex(line, i);
        }
    }

    return i;
}

/*
    ������� ��� ������ ��������� (�������) �� ���������� ������� (������� �������) �� ������� ������
    ���������� ����� ����� ������
*/
int splice(int index, char line[], char subLine[]){
    if(index < 0) return -1;
    int lineLen, subLineLen, i, j;

    lineLen = getLenght(line);
    subLineLen = getLenght(subLine);

    char temp[lineLen];
    copyArr(temp, line);

    for(i = index, j = 0; i < (lineLen + subLineLen) && i < MAXLINE && j < subLineLen-1; ++i, ++j){
        line[i] = subLine[j];
    }
    for(j = index; j < lineLen && i < (lineLen + subLineLen); ++j, ++i){
        line[i] = temp[j];
    }
    return i;
}

/**/
void removeByIndex(char line[], int index){
    if(index < 0) return;

    int i,j, len;
    len = getLenght(line);
    char temp[len];
    copyArr(temp, line);

    for(i = index, j = i+1; i < len && j < len; ++i, ++j){
        line[i] = temp[j];
    }

}

int trim(char line[], int len){

    if(len < 0) return -1;

    int i, j, start, end;
    char temp[len];

    clearArr(temp, len);
    copyArr(temp, line);

    for(start = 0; (temp[start] == ' ' || temp[start] == '\t') && start < len; ++start);
    for(end = (len-2); (temp[end] == ' ' || temp[end] == '\t') && end >= 0; --end);

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

/*getLenght: �������� ������ ������*/
int getLenght(char line[]){
    int i;
    for(i = 0; line[i] != '\0'; ++i);
    return i;
}
