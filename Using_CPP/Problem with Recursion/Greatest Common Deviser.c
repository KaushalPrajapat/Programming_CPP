//-----------Greatest Common Factor using Recursion in C-----------//
//------By - Kaushal Prajapat -- On 17.12.2020----------//

#include<stdio.h>
#include<conio.h>
int GCD(int , int);
int main()
{
    int number1 = 8, number2 = 16;
    printf("Greatest Common Deviser is : %d",GCD(number1,number2));
    printf("\nLeast Common Deviser is : %d", number1*number2/GCD(number1,number2));
    getch();
}
int GCD(int num1, int num2)
{
    if(num1==num2)
        return num1;
    else if(num1%num2 == 0)
        return num2;
        //GCM(num1%num2,num2);
    else if(num2%num1 == 0)
        return num1;
        //GCM(num1,num2%num1);
    else if(num1>num2)
        return GCD(num1%num2,num2);
    else
        return GCD(num1,num2%num1);
}
