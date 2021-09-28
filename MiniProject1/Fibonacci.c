/*
Jyotishka Bhattacharjee
Scholar ID: 2012025
MiniProject-1
CS 201, 
Data Structures, 
Department of Computer Science and Engineering, 
National Institute of Technology Silchar
*/

#include <stdio.h>

#define MAXIMUM 4500

void copy2ndTo1st(char number_1[], char number_2[]);

void addition(char number_1[], char number_2[], char final[]);

char fib1[MAXIMUM];
char fib2[MAXIMUM];
char final[MAXIMUM];

int main()
{

    for (int i = 0; i < MAXIMUM; i++)
    {
        fib1[i] = fib2[i] = final[i] = '0';
    }
    fib2[MAXIMUM - 1] = '1';

    int n;
    scanf("%d", &n);

    if (n == 0 || n == 1)
    {
        printf("%c", n + '0');
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            addition(fib1, fib2, final);
            copy2ndTo1st(fib1, fib2);
            copy2ndTo1st(fib2, final);
        }

        int startingNum = 0;
        for (int i = 0; i < MAXIMUM; i++)
        {
            if (startingNum == 0 && final[i] == '0')
                continue;

            if (startingNum == 0 && final[i] != '0')
                startingNum = 1;
            printf("%c", final[i]);
        }
        printf("\n");
    }
    return 0;
}

void addition(char number_1[], char number_2[], char final[])
{
    int carry = 0;
    for (int i = MAXIMUM - 1; i >= 0; i--)
    {
        int digit = (number_1[i] - '0') + (number_2[i] - '0') + carry;
        final[i] = (digit % 10) + '0';
        carry = digit / 10;
    }
}

void copy2ndTo1st(char number_1[], char number_2[])
{
    for (int i = MAXIMUM - 1; i >= 0; i--)
        number_1[i] = number_2[i];
}
