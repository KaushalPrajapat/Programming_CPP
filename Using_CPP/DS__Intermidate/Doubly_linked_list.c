//---------------Doubly Link List Operations in C-----------//
//------By - Kaushal Prajapat -- On 30.12.2020----------//
//Operations List 1. Insertion - First,Last,Any Position
//---------------2. deletion -- First,Last,Any Position
//---------------3. Searching - using Index, Using Data
//---------------4. Printing Data - Backward and Forward
//---------------5. Quit

#include<stdbool.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5

struct Node
{
    int data;
    struct Node *next , *prev;
};
struct Node *first = NULL , *last = NULL;


int list_length()
{
   int len = 0;
   struct Node *temp = first;
   while(temp != NULL)
   {
       temp = temp->next;
       len++;
   }
   return len;

}

int search_in_list()
{
    printf("Search Function \n");
    int search , choice , x = 0;
    struct Node *temp = first;
    printf("Press :  1.With Index \t2.With Data : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        {
            printf("Please! , Enter Index to search data : ");
            scanf("%d",&search);
            if(list_length() < search)
            {
                printf("Position is higher than List Len\n");
            }
            else
            {
                while(x < search - 1 )
                {
                    temp = temp->next;
                    x++;
                }
                printf("Data searched at Position %d is : %d\n",x+1,temp->data);
            }
            break;
        }
        case 2:
        {

            printf("Please! , Enter Data to search Index : ");
            scanf("%d",&search);

            struct Node *temp = first ;
            while(temp != NULL && temp->data != search)
            {
                temp = temp->next;
                x++;
            }

            temp != NULL ? printf("Data searched at Position %d , Data %d\n",x+1,temp->data) : printf("Data Not Found\n");

            break;
        }
        default :
            printf("Wrong Choice\n");
    }
}


void delete()
{
    int choice;
    printf("Press :  1.Initial Position\t2.Specific Position\t3.End Position : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        {
            first = first->next;
            break;
        }
    case 2:
        {
            int pos, j = 0;
            printf("Position to Delete Node <1 to Last Node %d:> ",list_length());
            scanf("%d",&pos);
            struct Node *temp = first , *nodeToDelete;
            while(j < pos - 1 )
            {
                nodeToDelete = temp;
                temp = temp->next;
                j++;
            }

            nodeToDelete->next = temp->next;
            //nodeToDetete->prev = temp;
            temp->prev = temp;
//            delete temp;
            break;

        }
    case 3:
        {
            struct Node *temp = first , *lastNode;
            while(temp->next != NULL)
            {
                lastNode = temp;
                temp = temp->next;
            }
            lastNode->next = NULL;
            //printf("DELETED at END\n");
            break;
        }
    }
}




void insert()
{
    int val,choice;
    printf("Please! Enter Data to Enter : ");
    scanf("%d",&val);
    struct Node *newNode = (struct Node*)malloc(sizeof(struct  Node));
    newNode->data = val;

    printf("Press :  1.Initial Position\t2.Specific Position\t3.End Position : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
    {
        if(first == NULL)
        {
            first = last = newNode;
            newNode->prev = NULL;
            newNode->next = NULL;
            break;
        }
        else
        {
            newNode->prev = NULL;
            first->prev = newNode;
            newNode->next = first;
            first = newNode;
            break;
        }
        //break;
    }
   case 2:
        {
            int pos, j = 0;
            printf("Position to Enter Node <1 to Last Node %d:> ",list_length());
            scanf("%d",&pos);
            struct Node *temp = first , *nextToTemp;
            if(list_length() < pos)
            {
                printf("Position is higher than List Len\n");
            }
            else
            {
                while(j < pos -2 )
                {
                    temp = temp->next;
                    j++;
                }
                nextToTemp = temp->next;
                newNode->next = temp->next;
                temp->next = newNode;
                newNode->prev = temp;
                nextToTemp->prev = newNode;
            }

            break;
        }
    case 3:
        {
            struct Node *temp = first;
            if(temp == NULL)
                printf("Empty List, Please! Enter at First Position\n");
            else
            {
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->prev = temp;
                newNode->next = NULL;
                //printf("Inserted at END\n");
                break;
            }
        }
    }
}

void print_list_backward()
{


    if(first == NULL)
        printf("Nothing to print\n");
    else
    {
        struct Node *temp = first , *lastNode;
        printf("Printing Element :\n[ ");
        while(temp != NULL)
        {
            //printf("%d - ",temp->data);
            lastNode = temp;
            temp = temp->next;
        }
        //printf("\t\t\t%d",temp->data);


        while(lastNode != NULL)
        {
            printf("%d - ",lastNode->data);
            lastNode = lastNode->prev;
        }
        printf("]\n");
    }
}


void print_list_forward()
{


    if(first == NULL)
        printf("Nothing to print\n");
    else
    {
        struct Node *temp = first;
        printf("Printing Element :\n[ ");
        while(temp != NULL)
        {
            printf("%d - ",temp->data);
            temp = temp->next;
        }

        printf("]\n");
    }


}

int main()
{
    while(true)
    {
        //printf("%d",list_length());

        //list_length();
        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
        int choice;
        printf("Press : 1.Insert\t2.Delete\t3.Search \t4.PrintList\t6.print Backward\t5.Press \'5\' for quit\n");
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                insert();
                break;
            }
            case 2:
            {
                delete();
                break;
            }
            case 3:
                search_in_list();
                break;
            case 4:
                print_list_forward();
                break;
            case 6:
                print_list_backward();
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong Choice... Choose again");
        }

    }
    getch();
}
