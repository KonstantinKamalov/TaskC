#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000    //����������� ���������� �������� ��� �����
#define MAXSTR 10       //����������� ���������� ����� � �������
#define MINCHARS 10     //����������� ���������� �������� � ������

/*
    �������� ��������� ��� ������ ���� ����� �������� ������,
    ������� ����� ����� 80 ��������
*/

int getLine(char line[], int lim);
void copy(char to[], char from[]);

int main()
{
    /*
        strIndex - ������ ������� (������)
        chIndex - ������ ������ (������)
        lineBuf - ������ ����� ������������ � MAXSTR
        line - ������� ������
        len - ����� ������� ������
    */

    int strIndex, chIndex, len;
    char line[MAXLINE];
    char lineBuf[MAXSTR][MAXLINE];

    /*�������� ������ �����*/
    for(strIndex = 0; strIndex < MAXSTR; ++strIndex){
        for(chIndex = 0; chIndex < MAXLINE; ++chIndex){
            lineBuf[strIndex][chIndex] = 0;
            if(line[chIndex] != 0) line[chIndex] = 0;
        }
    }

    /*��������� �������� ������*/
    for(strIndex = 0; strIndex < MAXSTR; ++strIndex){
        printf("input>");
        if((len = getLine(line, MAXLINE)) > MINCHARS) copy(lineBuf[strIndex], line);
    }

    /*������ ����������*/
    printf("\n");
    for(strIndex = 0; strIndex < MAXSTR; ++strIndex){
        printf("%s", lineBuf[strIndex]);
    }

    return 0;
}

/*
    getLine: �� �������� ������ ����������� ��������� ������ � ������������ lim.
    ���������� ���������� �������� � ������ (�� ������ lim)
*/
int getLine(char line[], int lim){

    /*
        c - ������
        index - ������ ������� line
        lim - ������ �������
        line - ������ �������� ��� �������� �������� �� ������
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
    copy: �������� from � to
*/
void copy(char to[], char from[]){
    for(int i = 0; (to[i] = from[i]) != '\0'; ++i);
}
