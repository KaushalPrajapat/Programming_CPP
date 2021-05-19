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
struct Node *first = NULL , *last = NULL, *lastfinal =NULL;


int list_length()
{
   int len = 0;
   struct Node *temp = first;

   do
   {
       temp = temp->next;
       len++;
   }while(temp != first);
   return len;

}
bool isEmpty()
{
    if(first == NULL)
        return true;
}
//Search in List working properly at 9.30AM 02.01.2021
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
            while(temp != first && temp->data != search)
            {
                temp = temp->next;
                x++;
            }

            temp != first ? printf("Data searched at Position %d , Data %d\n",x+1,temp->data) : printf("Data Not Found\n");

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
            struct Node *temp = first , *secondNode;
            secondNode = first->next;
            if(temp->next == first)
                printf("Already Empty---------------------\n");
            else
            {
                while(temp->next != first)
                {
                    temp = temp->next;
                }
             first = secondNode;
             temp->next = first;
             first->prev = temp;
                printf("DELETED at First\n");
            }
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
            struct Node *temp = first , *secondlastNode = first;
            if(temp->next == first)
                printf("Already Empty List\n");
            else
            {
                while(temp->next != first)
                {
                    secondlastNode = temp;
                    temp = temp->next;
                }
                secondlastNode->next = first;
                first->prev = secondlastNode;
                printf("DELETED at END\n");
            }


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
            last->next = last->prev = first;
            break;
        }
        else
        {
            newNode->prev = last;
            first->prev = newNode;
            newNode->next = first;
            first = newNode;
            last->next = first;
            break;
        }
        //break;
    }
   case 2:
        {
            //A small glitch
            int pos, j = 0;
            printf("Position to Enter Node <1 to Last Node %d:> ",list_length());
            scanf("%d",&pos);
            struct Node *temp = first , *nextToTemp;
            if(pos >= list_length() - 1 || list_length() >= 1)
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
            if(temp == first)
            {
                while(temp->next != first)
                {
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
                newNode->prev = temp;
                last = newNode;
                break;
            }
            else
                printf("Empty List, Please! Enter at First Position\n");

        }
    }
}

void print_list_backward()
{
struct Node *temp = first, *lastNode;
	printf("Printing Data : \n[ ");
	if(temp == first)
    {
		do
		{
            lastNode = temp;
			//printf("%d ",temp->data);
			temp=temp->next;

		}while(temp!=first);
		do
        {
            printf("%d ",lastNode->data);
            lastNode = lastNode->prev;
        }while(lastNode != first);
        if(list_length() > 1)
            printf("%d ",temp->data);

	}
	else
        printf("No data");
	printf("]\n");

}


void print_list_forward()
{
	struct Node *temp = first;
	printf("Printing Data : \n[ ");
	if(temp == first)
    {
		do
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}while(temp!=first);
	}
	else
        printf("No data");
	printf("]\n");
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
