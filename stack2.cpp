#include<iostream>
using namespace std;
struct node
{
  char data;
  node *next;
};
void push(node **root,int data)
{
   node *temp=new node;
   if(*root==NULL)
   {
     temp->data=data;
     temp->next=*root;
     *root=temp;
   }
   else
   {
     temp->data=data;
     temp->next=*root;
     *root=temp;
   }
}
bool isempty(node *root)
{
  if(root==NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}
int pop(node **root)
{
  if(*root==NULL)
  {
    cout<<"stack underflow"<<endl;
    return 0;
  }
  node *temp=*root;
  (*root)=(*root)->next;
  return temp->data;
}
int top(node **root)
{
  if(*root==NULL)
  {
    return -1;
  }
  else
  {
  return (*root)->data;
  }
}
void display(node *root)
{
  while(root!=NULL)
  {
    cout<<root->data<<endl;
    root=root->next;
  }
}
int prec(char a)
{
  switch (a) {
    case '^':
    {
      return 3;
    }
    case '*':
    case '/':
    {
      return 2;
    }
    case '+':
    case '-':
    {
      return 1;
    }
  }
}
int main()
{
    string s,os;
    cin>>s;
    char c;
    node *root=NULL;
    int i;
    int l=s.length();
    for(i=0;i<l;i++)
    {
      if(s[i]>='a' && s[i]<='z')
      {
        os=os+s[i];
      }
      else if(s[i]>='A' && s[i]<='Z')
      {
        os=os+s[i];
      }
      else if(s[i]=='(')
      {
        push(&root,s[i]);
      }
      else if(s[i]==')')
      {
        while(top(&root)!='('&&(!isempty(root)))
        {
          c=pop(&root);
          os=os+c;
        }
        if(top(&root)=='(')
        {
          pop(&root);
        }
      }
      else
      {
        while((!isempty(root)) && prec(s[i])<=prec(top(&root)))
        {
          c=pop(&root);
          os=os+c;
        }
        push(&root,s[i]);
      }
    }
    while(!isempty(root))
    {
      c=pop(&root);
      os=os+c;
    }

    cout<<os<<endl;
}
