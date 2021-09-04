#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 20

//��������� ���8
/*getLine: ��������� ������ � line, ���������� �� �����*/
int getLine(char line[], int maxLine);
/*copy: �������� ������ 'from' � 'to'; ����� to ��������� �����������*/
void copy(char to[], char from[]);

/*
    ����� ����� ������� ������ � ������
    *   ���������� ������� ������ ��������� ���, ����� ��� ����� �������� �����
        ������� ������ (� �������� �����������) � �� ������ (��� ����� �����������)
*/

int main()
{
    /*����� ������� ������*/
    int len;

    /*������� ������������ �����*/
    int max;

    /*������� ��������� ������*/
    char line[MAXLINE];

    /*����� ������� ������ �� ���������*/
    char longest[MAXLINE];

    /*��������� ������� ������*/
    for(int i = 0; i < MAXLINE; ++i) line[i] = longest[i] = 0;

    len = max = 0;
    /*���� ���� ������ � ��� ������ ����������, ��������*/
    while((len = getLine(line, MAXLINE)) > 0){
        if(len > max){
            max = len;
            copy(longest, line);
        }
    }

    /*���� ���� �������� ������ ������� ���������*/
    if(max > 0) printf("line size : %d\n%s", max, longest);
    return 0;
}

/*
    getLine: ��������� ������ � s, ���������� �� �����
    s �������� ���������� �� ������ ������� (�� ����������),
    ������� �������� s ����� �������� � �������
*/
int getLine(char s[], int lim){
    int c, i, j;

    /*
        c - ������
        j - ������ ������� �������� ������ � ������ MAXLINE (��� ������)
        i - ������ ������� �������� ������ ��� ����� MAXLINE (����� ������� �������� ������)
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
    copy: �������� ������ 'from' � 'to'; ����� to ��������� �����������
*/
void copy(char to[], char from[]){
    int index;
    index = 0;

    while((to[index] = from[index]) != '\0') ++index;
}
