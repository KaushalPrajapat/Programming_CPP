//---------------Queue OPrations Push Pop in C-----------//
//------By - Kaushal Prajapat -- On 21.12.2020----------//
#include<stdbool.h>
#include<stdio.h>
#include<conio.h>
#define MAX 5
int rear = -1 , front = 0 , top = 0;
int queue[MAX] = {};
void enQueue();
int deQueue();
bool isFull();
bool isEmpty();
void print_queue();
int peek();
int main()
{
    printf("//---------------Queue Oprations Push Pop in C-----------//\n");
    printf("//------By - Kaushal Prajapat -- On 21.12.2020----------//\n\n\n");
    int choice;
    while(true)
    {
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("Press : 1.EnQueue\t2.DeQueue\t3.Peek\t4.PrintQueue\t5.Press \'5\' for quit\n");
    printf("Enter Your Choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            int value;
            printf("Enter Value to Insert : ");
            scanf("%d",&value);
            enQueue(value);
            break;
        }
        case 2:
            deQueue();
            break;
        case 3:
            peek();
            break;
        case 4:
            print_queue();
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong Choice... Choose again");
    }

    }
    getch();
}
int deQueue()
{
    int j = 0 , data = queue[front - 1] ;
    if(!isEmpty())
    {
        while(j < front )
        {
            queue[j-1] = queue[j];
            j++;
        }
        front-- ;
        printf("Removed Data is : %d\n",data);
    }
    else
        printf("Empty Queue\n");
    }
void enQueue(int data)
{
    if(!isFull())
    {
        queue[front++] = data;
    }
    else
        printf("Queue Full\n");
}
int peek()
{
    if(front == 0)
    {
        printf("Empty Queue\n");
    }
    else
        printf("Value at Peek : %d\n",queue[front-1]);
}
bool isFull()
{
    if(front == MAX)
        return true;
    else
        return false;
}
bool isEmpty()
{
    if(front == 0)
        return true;
    else
        return false;
}
void print_queue()
{
    if(front == 0)
        printf("Nothing to Print\n");
    else
    {
        printf("Printing Queue : ");
        for ( int x = 0 ; x < front ; x++)
        {
            printf("%d ",queue[x]);
        }
        printf("\n");
    }
}
