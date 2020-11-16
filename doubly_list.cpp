using namespace std;
#include<bits/stdc++.h>

struct node
{
        int data;
        struct node *next;
	struct node *prev;
};

int i=0;

void insert_at_end(struct node **head)
{
        struct node *p;
        p = new node();

        cout<<endl<<"Enter the data of the node : ";
        int x;
        cin>>x;
        p->data = x;
        p->next = p->prev = NULL;

        if((*head) == NULL)
        {
                *head = p;
                (*head)->next = NULL;
                cout<<"node added successfully"<<endl;
                i++;
                return;
        }

        struct node *q;
        q = *head;

        while(q->next != NULL)
                q = q->next;

        q->next = p;
	p->prev = q;
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
        p->next = p->prev = NULL;

        if((*head) == NULL)
        {
                *head = p;cout<<"Node added successfully"<<endl;
                i++;
                return;
        }

	p->next = *head;
	(*head)->prev = p;
	*head = p;
	i++;
        cout<<"Node added successfully"<<endl;

}

void insert_at_pos(struct node **head,int x)
{
        int k=1,d;
        struct node *p = new node();
        cout<<"Enter the data of the node : ";
        cin>>d;
        p->next = NULL;
	p->prev = NULL;
        p->data = d;

        struct node *q = *head;
        struct node *a = q;

        while(q->next!= NULL && k<x)
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

        a->next = p;
	p->prev = a;
	q->prev = p;
	p->next = q;

        i++;
        cout<<endl<<"Node added successfully"<<endl;
}

void delete_at_front(struct node **head)
{
        struct node *p;

        if((*head) == NULL)
        {
                cout<<endl<<"List is empty"<<endl;
                return;
        }

        if((*head)->next == NULL)
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

        *head = (*head)->next;
        delete p;
        p = NULL;
        i--;
        cout<<"Node deleted successfully"<<endl;

}

void display(struct node *head)
{
        struct node *p = head;
        cout<<endl<<"The list is as follows : "<<endl;
        if(head == NULL)
        {
		cout<<endl<<"List is empty"<<endl;
		return;
	}
               
        while(p != NULL)
        {
        cout<<endl<<p->data;
        p = p->next;
        }

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
        while(p->next!= NULL && k<x)
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
	p->next->prev = q;
        delete p;
        p = NULL;
        i--;
        cout<<endl<<"Node delete successfully"<<endl;
}

void delete_at_end(struct node **head)
{
        struct node *p;

        if(*head == NULL)
        {
                cout<<endl<<"List is empty"<<endl;
                return;
        }

        if((*head)->next == NULL)
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

        while(p->next != NULL)
        {
                p = p->next;
        }

        p->prev->next = NULL;
        delete p;
	p = NULL;
        i--;
        cout<<"Node deleted successfully"<<endl;

}

int main()
{
        struct node *head = new node();
        head = NULL;
        int x = 1;
        cout<<endl<<"WELCOME TO Doubly LINKED LIST "<<endl<<endl;
        while(x!=8)
        {
        cout<<endl<<"WHAT DO YOU WANT TO DO?"<<endl<<endl;
        cout<<"1.Insert_at_end\n2.Insert_at_front\n3.Delete_at_end\n4.Delete_at_front\n5.Display\n";
        cout<<"6.delete_from_specified\n7.insert_at_position\n8.exit\n\n";
        cout<<"Enter the choice : ";
        cin>>x;

        switch(x)
        {
                case 1 : insert_at_end(&head);break;
                case 2 : insert_at_front(&head);break;
                case 3 : delete_at_end(&head);break;
                case 4 : delete_at_front(&head);break;
                case 5 : display(head);break;
                case 6 : int a;cout<<"Enter the position : ";cin>>a;
                        if(a==1)
                        delete_at_front(&head);
                        else
                        delete_at_pos(&head,a);break;
                case 7 : int x;cout<<"Enter the position : ";cin>>x;
                        if(x==1)
                        insert_at_front(&head);
                        else if(i == (x-1))
                        insert_at_end(&head);
                        else
                        insert_at_pos(&head,x);break;
               
          }
	}
	return 0;
}