void insert(Node **head,int val)
{
    Node *temp=new Node;
    temp->data=val;
    temp->next= *head;
    *head=temp;
}
void reverse(Node **head,int k)
{
    Node *cur=*head;
    Node *prev=NULL;
    Node *next=NULL;
    Node *temp;
    int i=0;
    Node *temp2;
    Node *temp3;
    while(cur!=NULL)
    {
        prev=NULL;
        next=NULL;
        temp=NULL;
        temp2=NULL;
      if(cur==*head)
       {
        while(i<k)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            i++;
        }
         (*head)->next=cur;
         (*head)=prev;
       }
        else
        {

            i=0;
                while(i<k&&cur!=NULL)
                {
                    temp2=cur;
                    cur=cur->next;


                    i++;
                }



                next=NULL;
                prev=NULL;

            i=0;
                while(i<k&&cur!=NULL)
                {
                   next=cur->next;
                   cur->next=prev;
                    prev=cur;
                    cur=next;
                    i++;
                }
                if(temp2!=NULL)
                {
                    temp2->next=prev;
                }
            temp3=prev;
            while(temp3->next!=NULL)
            {
                temp3=temp3->next;
            }
            temp3->next=cur;
                }


    }

}
void print(Node **head)
{
   Node *temp=*head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Node *head=NULL;
    int n,val,k;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        insert(&head,val);
    }
    cin>>k;
    reverse(&head,k);
    print(&head);
    return 0;
}
