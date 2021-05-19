//-----------Fibonacci Series using Recursion in C-----------//
//------By - Kaushal Prajapat -- On 16.12.2020----------//

#include<stdio.h>
#include<conio.h>
int fib(int );
int main()
{
    int num;
    int i;
    //printf("Please! Enter a number for Fibonacci Series : ");
    //scanf("%d",&num);
    for(i=1;i<=10;i++)
        printf("%d ",fib(i));
}
int fib(int nm)
{
    if(nm == 1 || nm == 2)
        return 1;
    return (fib(nm-1)+fib(nm-2));
}
