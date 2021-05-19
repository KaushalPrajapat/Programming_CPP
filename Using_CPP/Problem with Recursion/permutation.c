//-----------Permutation using Recursion in C-----------//
//------By - Kaushal Prajapat -- On 16.12.2020----------//

#include<stdio.h>
#include<conio.h>
#include<string.h>
//ABC BAC BCA CAB CBA ACB
void per(char *st , int i , int s);
int swap();
int main()
{
    char *str[20];
    printf("Enter String : ");
    gets(str);;
    per(str,0,strlen(str)-1);
    getch();

}
int swap(char *x , char *y)
{
    char ch;
    ch = *x;
    *x = *y;
    *y = ch;
}
void per(char *s , int i , int n)
{
    static int count;
    int j=0;
    if(i==n)
    {
        count++;
        printf("(%d)%s\t",count,s);
    }
    else
        for(j = i ; j <= n ; j++)

        {
            swap((s+i),(s+j));
            per(s,i+1,n);
            swap((s+i),(s+j));
        }
}
