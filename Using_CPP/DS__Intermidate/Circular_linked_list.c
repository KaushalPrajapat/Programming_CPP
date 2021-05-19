//---------------Circular Link List Operations in C-----------//
//------By - Kaushal Prajapat -- On 28.12.2020----------//
//Operations List 1. Insertion - First,Last,Any Position
//---------------2. deletion -- First,Last,Any Position
//---------------3. Searching - using Index, Using Data
//---------------4. Printing Data
//---------------5. Quit

#include<stdbool.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5

struct Node
{
    int data;
    struct Node *next;
};
struct Node *first = NULL , *last = NULL;

int list_length()
{
    struct Node *temp = first;
	int len = 0;
	{
		do
		{
			//printf("%d ",temp->data);
			temp=temp->next;
			len++ ;
		}while(temp!=first);
	}
    return len;
}
bool isEmpty()
{
    if(first == NULL)
        return true;
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
            printf("Please! , Enter Position to search data : ");
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
                printf("\nData searched at Position %d is : %d\n",x+1,temp->data);
            }
            break;
        }

        case 2:
        {

            printf("Please! , Enter Data to search Position : ");
            scanf("%d",&search);

            struct Node *temp = first ;
            while(temp->next != first && temp->data != search)
            {
                temp = temp->next;
                x++;
            }

            temp != temp->next ? printf("Data searched at Position %d , Data %d\n",x+1,temp->data) : printf("Data Not Found\n");

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
        if(!isEmpty())
        {
            while(temp->next != first)
            {
                temp = temp->next;
            }
        first = secondNode;
         temp->next = first;
            printf("DELETED at First\n");
        }
        else
            printf("Already Empty---------------------\n");
        break;
        }
    case 2:
        {
            int pos, j = 0;
            printf("Position to Delete Node <1 to Last Node %d:> ",list_length());
            scanf("%d",&pos);
            struct Node *temp = first , *nodeToDelete = first;
            if(!isEmpty())
            {
                while(j < pos - 1 )
                {
                    nodeToDelete = temp;
                    temp = temp->next;
                    j++;
                }
                nodeToDelete->next = temp->next;
    //            delete temp;
            }
            break;

        }
    case 3:
        {
            struct Node *temp = first , *secondlastNode = first;
            if(!isEmpty())
            {
                while(temp->next != first)
                {
                    secondlastNode = temp;
                    temp = temp->next;
                }
                secondlastNode->next = first;
                printf("DELETED at END\n");
            }
            else
                printf("Already Empty List\n");
            break;
        }
    }
}




void insert()
{
    struct Node *newNode , *temp1 , *currentNode = first , *prev = NULL;
    int choice , position , count = 1;
    newNode = (struct Node*)(malloc (sizeof(struct Node)));
    printf("Enter data to Insert : ");
    scanf("%d",&newNode->data);
    //newNode->link=first;
    printf("1.at beginning\t2.Any Where\t3.End");
    printf("\nEnter your choice..");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            {
                if(first == NULL)
                {
                    newNode->next = NULL;
                    first = last = newNode;
                    last->next = first;
                }
                else
                {
                    newNode->next = first;
                    first = newNode;
                    last->next = first;
                }
                break;
            }
        case 3:
            {
               newNode->next = NULL;
               last->next = newNode;
               last = newNode;
               last->next = first;
            break;
            }


        case 2:
            {
                printf("Enter Location : ");
                scanf("%d",&position);
                int len = 0;
                temp1 = first;
                do{
                    temp1 = temp1->next;
                    len++;
                }while(position > len + 1);
                if(position > len + 1)
                {
                    printf("Invalid Location\n");
                    //break;
                }
                if(position == 1)
                {
                    newNode->next = first;
                    first = newNode;
                    last->next = first;

                }
                else
                {
                    count = 1;
                    while(count < position)
                    {
                        prev = currentNode;
                        currentNode = currentNode->next;
                        count++;
                    }
                    prev->next = newNode;
                    newNode->next = currentNode;
                }
            break;
            }
    }
}

void print_list()
{

	struct Node *temp = first;
	printf("Printing Data : \n[ ");
	if(temp==NULL)
        printf("No data");

	else
	{
		do
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}while(temp!=first);
	}
	printf("]\n");
}

int main()
{
    isEmpty();
    while(true)
    {
        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
        int choice;
        printf("Press : 1.Insert\t2.Delete\t3.Search \t4.PrintList\t5.Press \'5\' for quit\n");
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
                print_list();
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong Choice... Choose again");
        }

    }
    getch();
}
