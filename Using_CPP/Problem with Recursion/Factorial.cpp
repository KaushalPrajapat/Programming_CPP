//-----------Factorial using Recursion in C-----------//
//------By - Kaushal Prajapat -- On 17.12.2020----------//

#include<stdio.h>
#include<conio.h>
int fact(int );
int main()
{
    int num;
    printf("Please! Enter a number for factorial : ");
    scanf("%d",&num);
    printf("%d",fact(num));
}
int fact(int nm)
{
    if (nm <= 0)
    {
        return 1;
    }
    else
    {
        //printf("%d\t",nm*fact(nm-1));
        return nm*fact(nm-1);
    }
}
