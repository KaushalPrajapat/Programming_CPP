//---------------Binary Search Tree Operations in C-----------//
//------By - Kaushal Prajapat -- On 07.01.2021----------//
//Operations List 1. Insertion
//---------------2. deletion -- Leaf , One child
//---------------3. Searching - Using Data
//---------------4. Printing Data - INORDER , PREORDER , POSTOREDR
//---------------5. Quit

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//Created a Structure with one data field and two pointer fields

struct Node
{
    int data;
    struct Node *leftNode , *rightNode;
};

struct Node *root  = NULL, *current = NULL , *parent = NULL;
//Insertion of data
void insert(int data)
{
    struct Node *newNode;   //NewNode to Insert
    newNode = (struct Node*)(malloc (sizeof(struct Node))); //Assigning memory for NewNode
    newNode->leftNode = newNode->rightNode = NULL;  //Assigning NULL to left and right pointer of newNode
    newNode->data = data; //Assigning data to data field of newNode
    if(root == NULL)        //Condition to check root=NULL or Not
    {
        root = newNode;     //If root == NULL assign newNode to root
    }
    else
    {
        current = root;
        parent = NULL;
        while(1)            //Traverse to get leaf Node where
        {
            parent = current;
            if(data < parent->data)     //If data to insert is less than root data
            {
                current = current->leftNode;
                if(current == NULL)
                {
                    parent->leftNode = newNode;
                    return ;
                }
            }
            else        //If data to insert is less than root data
            {
                current = current->rightNode;
                if(current == NULL)
                {
                    parent->rightNode = newNode;
                    return;

                }
            }
        }
    }
}
//Recursive Approach to search in a tree
struct Node* search_in_tree(struct Node* root , int data)
{
    current = root;     //Assign root in a temp variable
    if(data == current->data)   //IS data Found
    {
        printf("%d, is available in Tree.\n",data);         //print data
    }
    else    //traverse either right sub-tree or left-subtree
    {
        if(current->leftNode == NULL && current->rightNode == NULL)     //if reached at end of tree
            printf("%d ! is Not available in Tree.\n",data);            //Element not found
        else if(data > current->data)
        {
            search_in_tree(current->rightNode , data);                  //Search data is higher thank data in root
        }
        else
        {
            search_in_tree(current->leftNode , data);                   //Less than search data
        }
    }
}

//Finding minimum Value in a tree

int minValueNode(struct Node *node)
{
    struct Node *current = node;
    while(current && current->leftNode != NULL)
        current = current->leftNode;
    return current;
}

//Recursive approach to delete a Node from a tree
struct Node* delete_Node(struct Node* root , int data)
{
    current = root;
    //printf("delete a Node\n");
    //Base root == NULL
    if(root == NULL)    //If empty tree
        return root;
    if(data < root->data)   //IF data lies in left subtree
    {
        root->leftNode= delete_Node(root->leftNode , data);     //Recall using left sub tree
    }
    else if(data > root->data)
    {
        root->rightNode = delete_Node(root->rightNode , data);  //Recall using left sub tree
    }
    else
    {
        if(root->leftNode == NULL)              //Single child in right
        {
            struct Node *temp = root->rightNode;
            free(root);
            return temp;
        }
        else if(root->rightNode == NULL)        //Single child in left
        {
            struct Node *temp = root->leftNode;
            free(root);
            return temp;
        }
        //Condition then node having two child
        struct Node* temp = minValueNode(root->rightNode);      //Search minimum value in right subtree of tree
        root->data = temp->data;                                //Assign minimum of right to root->data
        root->rightNode = delete_Node(root->rightNode,temp->data);  //Now delete minimum data from right sub-tree
    }
}

//Printing algorithm using recursion
void print_pre_Order(struct Node* node)
{
    //NODE , LEFT , RIGHT
    if(node != NULL)
    {
        printf("%d ",node->data);
        print_pre_Order(node->leftNode);
        print_pre_Order(node->rightNode);
    }
}

void print_post_Order(struct Node* node)
{
    //LEFT , RIGHT , NODE
    if(node != NULL)
    {
        print_post_Order(node->leftNode);
        print_post_Order(node->rightNode);
        printf("%d ",node->data);
    }
}

void print_in_Order(struct Node* node)
{
    //LEFT , NODE , RIGHT
    if(node != NULL)
    {
        print_in_Order(node->leftNode);
        printf("%d ",node->data);
        print_in_Order(node->rightNode);
    }
}


int main()
{
    printf("//---------------Binary Search Tree in C------------------//\n");
    printf("//------By - Kaushal Prajapat -- On 07.01.2021----------//\n\n");
    //printf("%d",list_length());
    while(1)
    {
        int choice , print_choice;;
        printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
        printf("Press : 1.Insert\t2.Delete\t3.Search \t4.Print_In_Order\t5.print_Pre_Order\t6.print_Post_Order\t7.Press \'5\' for quit\n");


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
                delete_Node(root,data);
                break;
            }
            case 3:
            {
                printf("Enter Data to Search : ");
                int data;
                scanf("%d",&data);
                search_in_tree(root , data);
                break;
            }
            case 4:
                printf("Printing in In Order : ");
                print_in_Order(root);
                break;
            case 5:
                printf("Printing in Pre Order : ");
                print_pre_Order(root);
                break;
            case 6:
                printf("Printing in Post Order : ");
                print_post_Order(root);
                break;

            case 7:
                exit(0);
            default:
                printf("Wrong Choice... Choose again");
        }

    }
    getch();
}
