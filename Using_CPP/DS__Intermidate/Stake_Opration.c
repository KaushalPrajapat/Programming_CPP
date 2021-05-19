//---------------Stake OPrations Push Pop in C-----------//
//------By - Kaushal Prajapat -- On 21.12.2020----------//
#include<stdbool.h>
#include<stdio.h>
#include<conio.h>
#define MAX 5
int top = -1;
int stake[MAX] = {};
void push();
int pop();
bool isFull();
bool isEmpty();
void print_stake();
int peek();
int main()
{
    printf("//---------------Stake Oprations Push Pop in C-----------//\n");
    printf("//------By - Kaushal Prajapat -- On 21.12.2020----------//\n\n\n");

    print_stake();
//    isFull();
//    pop();
    push(10);
    push(20);
    push(30);
    printf("Peeked : %d\n",peek());
    printf("\nPopped Element : %d\n",pop());
    //push(12);
    print_stake();
    getch();
}
int peek()
{
    return stake[top];
}
int pop()
{
    int data;
    if(!isEmpty())
    {
        data = stake[top];
        top = top-1;}
    else
    {
        printf("Empty Stake");
    }
    return data;
}
void push(int val)
{
    if(!isFull())
    {
        stake[++top] = val;
        //top++;
    }
    else
        printf("Stake is Full, Can't Load more element");
}
bool isFull()
{
    if(top == MAX)
        return true;
    else
        return false;
}
bool isEmpty()
{
    if(top == 0)
        return true;
    else
        return false;
}
void print_stake()
{
    printf("Printing Stake :\n");
    for ( int x =0 ; x <= top ; x++)
    {
        printf("%d ",stake[x]);
    }
}
