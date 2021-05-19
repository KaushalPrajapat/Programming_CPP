//---------------Link List Operations Push Pop in C-----------//
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

struct Node *head = NULL;

int list_length()
{
    int len = 0;
    struct Node *link = head;
    while(link != NULL)
        {
            link = link->next;
            len++;
        }
    return len;
}

int search_in_list()
{
    printf("Search Function \n");
    int search , choice , x = 0;
    struct Node *temp = head;
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

            struct Node *temp = head ;
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
            head = head->next;
            break;
        }
    case 2:
        {
            int pos, j = 0;
            printf("Position to Delete Node <1 to Last Node %d:> ",list_length());
            scanf("%d",&pos);
            struct Node *temp = head , *nodeToDelete = head;
            while(j < pos - 1 )
            {
                nodeToDelete = temp;
                temp = temp->next;
                j++;
            }
            nodeToDelete->next = temp->next;
//            delete temp;
            break;

        }
    case 3:
        {
            struct Node *temp = head , *lastNode = head;
            while(temp->next != NULL)
            {
                lastNode = temp;
                temp = temp->next;
            }
            lastNode->next = NULL;
            printf("DELETED at END\n");
            break;
        }
    }
}


void Insert()
{
    int val;
    printf("Please! Enter Data to Enter : ");
    scanf("%d",&val);
    int choice;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct  Node));
    newNode->data = val;
    printf("Press :  1.Initial Position\t2.Specific Position\t3.End Position : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        {
            //newNode->data = val;
            newNode->next = head;
            head = newNode;
            printf("Inserted at Initial Position\n");
            break;
        }
    case 2:
        {
            int pos, j = 0;
            printf("Position to Enter Node <1 to Last Node %d:> ",list_length());
            scanf("%d",&pos);
            struct Node *temp = head;
            if(list_length() < pos)
            {
                printf("Position is higher than List Len\n");
            }
            else
            {
                while(j < pos - 2 )
                {
                    temp = temp->next;
                    j++;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }

            break;
        }
    case 3:
        {
            struct Node *temp = head;
            if(temp == NULL)
                printf("Empty List, Please! Enter at First Position\n");
            else
            {
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->next = NULL;
                printf("Inserted at END\n");
                break;
            }
        }
    }
}
//Find a Element and its Key
void print_list()
{

    struct Node *temp = head;

    if(temp == NULL)
        printf("Nothing to print\n");
    else
    {
        printf("Printing Element :\n");
        while(temp != NULL)
        {
            printf("--%d-",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    printf("%d",list_length());
    while(true)
    {
        int choice;
        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
        printf("Press : 1.Insert\t2.Delete\t3.Search \t4.PrintList\t5.Press \'5\' for quit\n");
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                Insert();
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
