#include<bits/stdc++.h>
using namespace std;
int sum=0;

struct node{
        int fre;
        char code;
        struct node *left;
        struct node *right;
        node(int f,char c):fre(f),code(c){}
};


struct myComparator{

        bool operator()(node const *a,node const *b){
                return a->fre>b->fre;
        }
};


struct node* optimal_merge(priority_queue <node*, vector<node*>, myComparator > pq1,int n)
{
        struct node *n1;
        while(pq1.size()!=1)
        {
                n1 = new node(0,0);
                n1->left = pq1.top();
                pq1.pop();
                n1->right = pq1.top();
                pq1.pop();
                n1->fre = n1->left->fre + n1->right->fre;
                
                pq1.push(n1);
             
                
        }

        return pq1.top();
}

void traversal(struct node *root)
{
        if(root->code != 0)
        {       
                return;
        }else{
		sum= sum+root->fre;
	}

        traversal(root->left);
        traversal(root->right);
}

int main()
{
        priority_queue <node*, vector<node*>, myComparator > pq;
        int n;
        cout<<endl<<"Enter the no of files : ";
        cin>>n;

        cout<<endl<<"Enter the files along with size : "<<endl;
        char ch;
        int fre;

        for(int i=0;i<n;i++)
        {
                cin>>ws;
                cin>>ch>>fre;
                pq.push(new node(fre,ch));
        }
       
        struct node *p = optimal_merge(pq,n);
        cout<<endl<<"TOTAL NUMBER OF MOVEMENTS : "; 

        traversal(p);
	cout<<sum<<endl;

        cout<<endl<<endl;
        return 0;
}
