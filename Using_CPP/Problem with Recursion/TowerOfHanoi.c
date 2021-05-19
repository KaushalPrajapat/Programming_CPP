//-----------Tower of Hanoi using Recursion in C-----------//
//------By - Kaushal Prajapat -- On 18.12.2020----------//

#include<stdio.h>
#include<conio.h>
int TOH(int, char, char, char);
int main()
{
    char A = 'A' ,B = 'B' ,C = 'C';
    TOH(4,A,B,C);
    getch();
}
int TOH(int n, char B, char M, char E)
{
    if(n > 0)
    {   int static count = 1;
        TOH((n-1) , B , E ,M );
        printf("%d-%C to %c\n",count++,B,E);
        TOH((n-1) , M , B , E);
    }
}
