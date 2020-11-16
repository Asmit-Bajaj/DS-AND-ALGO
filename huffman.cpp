#include<bits/stdc++.h>
using namespace std;
int sum=0;

struct node{
	int fre;
	char code;
	struct node *left;
	struct node *right;
	//int vis = 0;
	node(int f,char c):fre(f),code(c){}
};

struct myComparator{

	bool operator()(node const *a,node const *b){

		return a->fre>b->fre;
	}
};

struct node* huffman_code(priority_queue <node*, vector<node*>, myComparator > pq1,int n)
{
	struct node *n1;
	//cout<<"HII";

	while(pq1.size()!=1)
	{
		n1 = new node(0,0);
		n1->left = pq1.top();
		pq1.pop();
		n1->right = pq1.top();
		pq1.pop();
		n1->fre = n1->left->fre + n1->right->fre;
		//cout<<n1->left->code<<" "<<n1->right->code<<" "<<endl;
		pq1.push(n1);
		//cout<<"HII"<<endl;
		//n1 = NULL;
	}

	return pq1.top();	
}

void traversal(struct node *root,string s,int i)
{
	if(root->code != 0)
	{
		cout<<root->code<<" - "<<s<<endl;
		sum = sum+(root->fre*i);
		//cout<<sum<<" "<<i<<endl;
		i--;
		//s[s.size()-1] = '\0';
		return;
	}

	s = s+"0";
	i++;
	traversal(root->left,s,i);
	 s[s.size()-1] = '\0';
	s = s+"1";
	traversal(root->right,s,i);
}

int main()
{
	priority_queue <node*, vector<node*>, myComparator > pq;
	int n;
	string s = "";
	cout<<endl<<"Enter the no of characters : ";
	cin>>n;

	cout<<endl<<"Enter the characters along with frequency : "<<endl;
	char ch;
	int fre;

	for(int i=0;i<n;i++)
	{
		cin>>ws;
		cin>>ch>>fre;
		//struct node;
		pq.push(new node(fre,ch));
	}

	/*while(pq.empty()!=true){
		cout<<pq.top()->code<<" "<<pq.top()->fre<<" "<<endl;
		pq.pop();
	}*/
	//cout<<"HII 1"<<endl;
	struct node *p = huffman_code(pq,n);
	cout<<endl<<"HUFFMAN CODES ARE AS FOLLOWS : "<<endl<<endl;
	//cout<<p->fre<<endl;
	int x = 0;
	traversal(p,s,x);
	cout<<endl<<"Total bits occupied : "<<sum<<endl;
	cout<<endl<<"Total frequency of all characters : "<<p->fre<<endl;
	cout<<"1 ch = "<<(float)sum/p->fre<<" bits"<<endl<<endl;
	
	cout<<endl<<endl;
	return 0;
}

	