using namespace std;

#include<iostream>

class cir_queue
{
        int q[5],front,rear,c;

public :
        cir_queue(){front=0;rear=0;c=0;}

        void enqueue();
        void dequeue();
        void display();
};

void cir_queue :: enqueue()
{
        int a;
        if(rear == 6 || (rear == front && rear != 0)) 
        {
                cout<<"Queue is full no more elements can be added "<<endl<<endl;
        }
        else
        {
                cout<<endl<<"Enter the element to add to queue : ";
                cin>>a;
                q[rear] = a;
		c++;
                rear++;
		if(rear == 5 && front == 0)
			rear++;
		else
		{
			rear  = (rear%5);
		}
        }
}

void cir_queue :: dequeue()
{
	if(c == 0)
        {
                cout<<"Queue is empty You cannot delete element from queue "<<endl<<endl;
                front = rear = 0;
        }
        else
        {
                cout<<"Element "<<q[front]<<" is deleted "<<endl<<endl;
		c--;
		if(rear == 6)
		rear = (rear-1)%5;
                front = (front + 1)%5;
        }
}

void cir_queue :: display()
{
        cout<<endl<<endl<<"Elements of queue are as follows : "<<endl<<endl;
	int i = front;
	int j = c;

	while(j--)
	{
		cout<<q[i]<<endl;
		i = (i+1)%5;
	}
}

int main()
{
        cir_queue my_q;
        int ch=1;

        cout<<"\t\tWELCOME TO QUEUE STRUCTURE : ";

        while(ch != 4)
        {
                cout<<endl<<endl<<"WHAT DO YOU WANT TO DO WITH CIRCULAR QUEUE?"<<endl;
                cout<<"1.Insertion\n2.deletion\n3.show\n4.exit"<<endl<<endl;
                cout<<"Enter your choice : ";
                cin>>ch;

                switch(ch)
                {
                        case 1 : my_q.enqueue();
                                 break;

                        case 2 : my_q.dequeue();
                                break;

                        case 3 : my_q.display();
                                 break;
 }
        }

        return 0;
}
