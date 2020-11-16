using namespace std;
#include<bits/stdc++.h>

struct node
{
        int data;
        struct node *next;
};

int i=0;

void traverse(struct node *head)
{
        if(head==NULL)
        {
                cout<<"List is empty"<<endl;
                return;
        }

        if(head->next == head)
        {
                cout<<"Address of last node : "<<&head;
                cout<<endl<<"last second node does not exist"<<endl;
                return;
        }
        struct node *p;
        p = head;
        while(p->next->next!=head)
        {
                p = p->next;
        }
        struct node *q = p;
        cout<<"Address of last node : "<<p->next;
        cout<<endl<<"Address of last second node : "<<&p;

}

void insert_at_end(struct node **head)
{
        struct node *p;
        p = new node();

        cout<<endl<<"Enter the data of the node : ";
        int x;
        cin>>x;
        p->data = x;
        p->next = *head;
        if(*head == NULL)
        {
                *head = p;
                (*head)->next = *head;
                cout<<"node added successfully"<<endl;
                i++;
                return;
        }

        struct node *q;
        q = *head;

        while(q->next != *head)
                q = q->next;

        q->next = p;
        i++;
        cout<<"node added successfully"<<endl;

}

void insert_at_front(struct node **head)
{
        struct node *p = new node();
        cout<<endl<<"Enter the data of the node : ";
        int x;
        cin>>x;
        p->data = x;
        p->next = *head;

        if(*head == NULL)
        {
                p->next = p;
                *head = p;cout<<"Node added successfully"<<endl;
                i++;
                return;
        }

        struct node *q;
        q = *head;

        while(q->next != *head)
                q = q->next;

        p->next = *head;
        *head = p;i++;
        q->next = *head;
        cout<<"Node added successfully"<<endl;

}

void insert_at_pos(struct node **head,int x)
{
        int k=1,d;
        struct node *p = new node();
        cout<<"Enter the data of the node : ";
        cin>>d;
        p->next = NULL;
        p->data = d;

        struct node *q = *head;
        struct node *a = q;

        while(q->next!= *head && k<x)
        {
                a = q;
                q = q->next;
                k++;
        }
        if(k<x)
        {
                cout<<endl<<"Position does not exist "<<endl;
                return;
        }

        p->next = q;
        a->next = p;
        i++;
        cout<<endl<<"Node added successfully"<<endl;
}

void delete_at_end(struct node **head)
{
        struct node *p;

        if(*head == NULL)
        {
                cout<<endl<<"List is empty"<<endl;
                return;
        }

        if((*head)->next == *head)
        {
                p = *head;
                delete p;
                p = NULL;
                *head = NULL;
                i--;
                cout<<"Node deleted successfully"<<endl;
                return;
        }
        p  = *head;

        while(p->next->next != *head)
        {
                p = p->next;
        }

        delete p->next;
        p->next = *head;
        i--;
        cout<<"Node deleted successfully"<<endl;

}


void delete_at_front(struct node **head)
{
        struct node *p;

        if(*head == NULL)
        {
                cout<<endl<<"List is empty"<<endl;
                return;
        }

        if((*head)->next == *head)
        {
                p = *head;
                delete p;
                p = NULL;
                *head = NULL;
                cout<<"Node deleted successfully"<<endl;
                i--;
                return;
        }

        p = *head;

        struct node *q = *head;

        while(q->next != *head)
                q = q->next;

        *head = (*head)->next;
        delete p;
        p = NULL;
        i--;
        q->next = *head;
        cout<<"Node deleted successfully"<<endl;

}

void display(struct node *head)
{
        struct node *p = head;
        cout<<endl<<"The list is as follows : "<<endl;
        if(head->next == head)
        {
                cout<<endl<<p->data;
                return;
        }
        while(p->next != head)
        {
        cout<<endl<<p->data;
        p = p->next;
        }
         cout<<endl<<p->data;
        p = p->next;

        cout<<endl<<endl;
}

void delete_at_pos(struct node **head,int x)
{
        int k=1;
        struct node *p;
        if(*head == NULL)
        {
        cout<<endl<<"List is empty "<<endl;
                return;
        }
        p = *head;
        struct node *q = p;
        while(p->next!= *head && k<x)
        {
                q = p;
                p = p->next;
                k++;
        }

        if(k<x)
        {
                cout<<endl<<"Position does not exist in list"<<endl;
                return;
        }

        q->next = p->next;
        delete p;
        p = NULL;
        i--;
        cout<<endl<<"Node delete successfully"<<endl;
}

int main()
{
        struct node *head = new node();
        head = NULL;
        int x = 1;
        cout<<endl<<"WELCOME TO CIRCULAR LINKED LIST "<<endl<<endl;
        while(x!=11)
        {
        cout<<endl<<"WHAT DO YOU WANT TO DO?"<<endl<<endl;
        cout<<"1.Traverse\n2.Insert_at_end\n3.Insert_at_front\n4.Delete_at_end\n5.Delete_at_front\n6.Display\n";
        cout<<"7.delete_from_specified\n8.insert_at_position\n9.Searching\n10.reverse\n11.exit\n\n";
        cout<<"Enter the choice : ";
        cin>>x;

        switch(x)
        {
                case 1: traverse(head);break;
                case 2 : insert_at_end(&head);break;
                case 3 : insert_at_front(&head);break;
                case 4 : delete_at_end(&head);break;
                case 5 : delete_at_front(&head);break;
                case 6 : display(head);break;
                case 7 : int a;cout<<"Enter the position : ";cin>>a;
                        if(a==1)
                        delete_at_front(&head);
                        else
                        delete_at_pos(&head,a);break;
                case 8 : int x;cout<<"Enter the position : ";cin>>x;
                        if(x==1)
                        insert_at_front(&head);
                        else if(i == (x-1))
                        insert_at_end(&head);
                        else
                        insert_at_pos(&head,x);break;
                case 9 : search(head);break;
               // case 10 :reverse(&head);break;
        }
        }
        return 0;
}

