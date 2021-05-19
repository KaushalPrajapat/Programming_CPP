//Kaushal Prajapat,En. roll. 186301041, cl roll.=43

// SOURCE CODE , CODE’S SCREESNSHOT , O/P’S SCREENSHOT :
#include<iostream>
#include<stdlib.h>
#define false 0
#define true 1
using namespace std;
int k;
struct tree
{
int data;
tree *lc,*rc;
}*root;
class btree
{
public:
btree()
{
root=NULL;
}
void push(int i)
{
tree *tmp=new tree,*p,*r;
if(tmp==NULL)
cout<<"no memory allocation";
tmp->data=i;
tmp->lc=NULL;
tmp->rc=NULL;
if(root==NULL)
{
cout<<"data added in empty tree\nroot node = "<<tmp->data<<"\n";
root=tmp;
}
else
{
p=root;
while(p!=NULL)
{
r=p;
if(p->data==i)
cout<<"data exist";
else if(p->data<i)
{
cout<<"data added to right of "<<p->data<<"\n";
p=p->rc;
}
else
{
cout<<"data added to left of "<<p->data<<"\n";
p=p->lc;
}
}
if(r->data>i)
r->lc=tmp;
else
r->rc=tmp;
}
}
void ldr(tree *p)
{
if(p==NULL)
return;
ldr(p->lc);
cout<<" "<<p->data;
ldr(p->rc);
}
void dlr(tree *p)
{
if(p==NULL)
return;
cout<<" "<<p->data;
ldr(p->lc);
ldr(p->rc);
}
void lrd(tree *p)
{
if(p==NULL)
return;
ldr(p->lc);
ldr(p->rc);
cout<<" "<<p->data;
}
};
int main()
{
	cout<<"Kaushal Prajapat,En. roll. 186301041, cl roll.=43";
btree o;
char ch;
int t=1,n,x;
while(1)
{
cout<<"\n1)insert\n";
cout<<"2)in order:ldr\n";
cout<<"3)pre order:dlr\n";
cout<<"4)post order:lrd\n";
cout<<"5)exit\n";
cout<<"choose: ";
cin>>x;
switch(x)
{
case 1:
if(root!=NULL)
root=NULL;
cout<<"enter no. of nodes: ";
cin>>k;
for(;t<=k;t++)
{
cout<<"data:";
cin>>n;
o.push(n);
}
break;
case 2:
o.ldr(root);
break;
case 3:
o.dlr(root);
break;
case 4:
o.lrd(root);
break;
case 5:
exit(0);
default:
cout<<"\n invalid choice";
}}
return 0;
}
