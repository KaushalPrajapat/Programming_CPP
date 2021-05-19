//---------------------------------MIN HEAP Tree in C----------------------------//
//------------------------By - Kaushal Prajapat -- On 07.01.2021----------------//


#include<stdio.h>
#include<conio.h>
#define MAX 10
int heap[MAX],pos = -1;

void display(int size)
{
    printf("Displaying Data : ");
    for(int z = 0 ; z < size ; z++)
    {
        printf("-%d ",heap[z]);
    }
    printf("\n");
}

int searching(int item)
{
    int flag = 1;
    for (int i = 0 ; i <= pos ; i++)
    {
        if(heap[i] == item)
        {
            return i;
            flag = 0;
        }

    }
    if(flag == 1)
        return -1;
}

void insert(int data)
{
    heap[++pos] = data;
    int child = pos ,parent,temp;           // Assigning position to child
    while(child >= 1)
    {
        //printf("Child : %d\n",child);
        parent = (child - 1) / 2;               //parent is equal to half child - 1
        if(heap[parent] >= heap[child])
        {
            temp = heap[parent];
            heap[parent] = heap[child];
            heap[child] = temp;
            child = parent;
        }
        else
            return;
    }
}

void del(int data)
{
    int temp,loc = searching(data);
    if(loc == -1)
        {
            printf("Data Not in Heap\n");
            return;
        }
    heap[loc] = heap[pos];
    pos--;
    //printf("Location %d",loc);
    int leftChild = 2*loc + 1 , rightChild = 2*loc + 2;

    while(loc < pos)
    {
        int leftChild = 2*loc + 1 , rightChild = 2*loc + 2 , parent = loc/2;
        if(heap[loc] < heap[parent])
        {
            temp = heap[loc];
            heap[loc] = heap[parent];
            heap[parent] = temp;
            loc = parent;
        }
        if(heap[loc] < heap[rightChild] || heap[loc] < heap[leftChild])
        {
            if(heap[rightChild] < heap[leftChild])
            {
                temp = heap[rightChild];
                heap[rightChild] = heap[loc];
                heap[loc] = heap[rightChild];
                loc = rightChild;
            }
            else
            {
                temp = heap[leftChild];
                heap[leftChild] = heap[loc];
                heap[loc] = heap[leftChild];
                loc = leftChild;
            }
        }

    }
}

void search(int data)
{
    int flag = 1;
    for(int j = 0 ;  j <= pos ; j++)
    {
        if(heap[j] == data)
        {
            printf("Data Found at index : %d\n",j);
            flag == 0;
            return;
        }

    }
    if(flag == 1)
    {
        printf("Not Found, Data : %d\n",data);
    }
}

int main()
{
    printf("//---------------MIN HEAP Tree in C------------------//\n");
    printf("//------By - Kaushal Prajapat -- On 07.01.2021----------//\n\n");
    //printf("%d",list_length());
    while(1)
    {
        int choice , print_choice;;
        printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
        printf("Press : 1.Insert\t2.Delete\t3.Search \t4.Display\t5.Press \'5\' for quit\n");


        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter Data to Enter : ");
                int data;
                scanf("%d",&data);
                insert(data);
                break;
            }
            case 2:
            {
                printf("Enter Data to Delete : ");
                int data;
                scanf("%d",&data);
                del(data);
                break;
            }
            case 3:
            {
                printf("Enter Data to Enter : ");
                int data;
                scanf("%d",&data);
                search(data);
                break;
            }

            case 4:
            {
                display(pos+1);
                break;
            }

            case 5:
                return;
            default:
                printf("Wrong Choice... Choose again");
        }

    }
}
