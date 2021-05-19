
//---------------Adelson Velski Landis Binary Search Tree Operations in C-----------//
//---------------By - Kaushal Prajapat -- On 11.01.2021-----------------------------//
//Operations List 1. Insertion
//----------------2. deletion -- Leaf , One child
//----------------3. Searching - Using Data
//----------------4. Printing Data - PREORDER
//----------------0. Quit

/*
Functionality required
node *insert(node *,int);
node *Delete(node *,int);
    void preorder(node *);      //done
    void inorder(node *);       //done
    int height( node *);
    node *rotateright(node *);
    node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int BF(node *);
*/
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct node {
    struct node *left;
    int data;
    int height;
    struct node *right;

};

class AVL
{
private:

public:
    struct node *root , *current;
    AVL(){
        this->root = NULL;

    }

    int calheight(struct node *p){

            if(p->left && p->right){
            if (p->left->height < p->right->height)
                return p->right->height + 1;
            else return  p->left->height + 1;
            }
            else if(p->left && p->right == NULL){
               return p->left->height + 1;
            }
            else if(p->left ==NULL && p->right){
               return p->right->height + 1;
            }
            return 0;

    }

    int bf(struct node *n){
            if(n->left && n->right){
                return n->left->height - n->right->height;
            }
            else if(n->left && n->right == NULL){
                return n->left->height;
            }
            else if(n->left== NULL && n->right ){
                return -n->right->height;
            }
    }

    struct node * llrotation(struct node *n){
        struct node *p;
        struct node *tp;
        p = n;
        tp = p->left;

        p->left = tp->right;
        tp->right = p;

        return tp;
    }


    struct node * rrrotation(struct node *n){
        struct node *p;
        struct node *tp;
        p = n;
        tp = p->right;

        p->right = tp->left;
        tp->left = p;

        return tp;
    }


    struct node * rlrotation(struct node *n){
        struct node *p;
        struct node *tp;
        struct node *tp2;
        p = n;
        tp = p->right;
        tp2 =p->right->left;

        p -> right = tp2->left;
        tp ->left = tp2->right;
        tp2 ->left = p;
        tp2->right = tp;

        return tp2;
    }

    struct node * lrrotation(struct node *n){
        struct node *p;
        struct node *tp;
        struct node *tp2;
        p = n;
        tp = p->left;
        tp2 =p->left->right;

        p -> left = tp2->right;
        tp ->right = tp2->left;
        tp2 ->right = p;
        tp2->left = tp;

        return tp2;
    }

    struct node* search_in_tree(struct node* root , int data)
    {
        current = root;     //Assign root in a temp variable
        if(data == current->data)   //IS data Found
        {
            printf("%d, is available in Tree.\n",data);         //print data
        }
        else    //traverse either right sub-tree or left-subtree
        {
            if(current->left == NULL && current->right == NULL)     //if reached at end of tree
                printf("%d ! is Not available in Tree.\n",data);            //Element not found
            else if(data > current->data)
            {
                search_in_tree(current->right , data);                  //Search data is higher thank data in root
            }
            else
            {
                search_in_tree(current->left , data);                   //Less than search data
            }
        }
    }



    struct node* insert(struct node *r,int data){

        if(r==NULL){
            struct node *n;
            n = new struct node;
            n->data = data;
            r = n;
            r->left = r->right = NULL;
            r->height = 1;
            return r;
        }
        else{
            if(data < r->data)
            r->left = insert(r->left,data);
            else
            r->right = insert(r->right,data);
        }

        r->height = calheight(r);

        if(bf(r)==2 && bf(r->left)==1){
            r = llrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==-1){
            r = rrrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==1){
            r = rlrotation(r);
        }
        else if(bf(r)==2 && bf(r->left)==-1){
            r = lrrotation(r);
        }

        return r;

        }

    struct node * deleteNode(struct node *p,int data){

        if(p->left == NULL && p->right == NULL){
                if(p==this->root)
                    this->root = NULL;
            delete p;
            return NULL;
        }

        struct node *t;
        struct node *q;
        if(p->data < data){
            p->right = deleteNode(p->right,data);
        }
        else if(p->data > data){
            p->left = deleteNode(p->left,data);
        }
        else{
            if(p->left != NULL){
                q = inpre(p->left);
                p->data = q->data;
                p->left=deleteNode(p->left,q->data);
            }
            else{
                q = insuc(p->right);
                p->data = q->data;
                p->right = deleteNode(p->right,q->data);
            }
        }

        if(bf(p)==2 && bf(p->left)==1){ p = llrotation(p); }
        else if(bf(p)==2 && bf(p->left)==-1){ p = lrrotation(p); }
        else if(bf(p)==2 && bf(p->left)==0){ p = llrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==-1){ p = rrrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==1){ p = rlrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==0){ p = llrotation(p); }


        return p;
    }

     struct node* inpre(struct node* p){
        while(p->right!=NULL)
            p = p->right;
        return p;
    }

    struct node* insuc(struct node* p){
        while(p->left!=NULL)
            p = p->left;

        return p;
    }

    void print_pre_Order(struct node* node)
{
    //NODE , LEFT , RIGHT
    if(node != NULL)
    {
        printf("%d ",node->data);
        print_pre_Order(node->left);
        print_pre_Order(node->right);
    }
}




    ~AVL(){

    }
};


int main(){
    printf("//---------------Adelson Velski Landis in C------------------//\n");
    printf("//------By - Kaushal Prajapat -- On 11.01.2021----------//\n\n\n");

    AVL b;
    int c,data;

    do{
        cout<<"1.Insert\t2.Delete\t3.Searching Element\t4.Print_Pre_Order\t5.Exit\nChoice : ";
        cin>>c;
        switch (c)
        {
        case 4:
            cout<<"Printing PreOrder : ";
            b.print_pre_Order(b.root);
            cout<<"\n";
            break;

        case 1:
            cout<<"Enter data ";
            cin>>data;
            b.root = b.insert(b.root,data);
            break;

        case 2:
            cout<<"What to delete? ";
            cin>>data;
            b.root = b.deleteNode(b.root,data);
            break;

        case 3:
            cout<<"Enter to Search? ";
            cin>>data;
            b.search_in_tree(b.root,data);
            break;

        case 5:
            break;
        default :
            cout<<"Wrong Choice !\n";
        }

     } while(c!=5);

}

