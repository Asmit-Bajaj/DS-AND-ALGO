using namespace std;
#include<bits/stdc++.h>

struct tree 
{
	int data;
	struct tree *left;
	struct tree *right;
};

void insert(struct tree **root)
{
	int x;
	struct tree *temp;
	struct tree *p = new struct tree();
	cout<<"Enter the element : ";
	cin>>x;
	p->data = x;

	p->left = p->right = NULL;

	if(*root == NULL)
	{
		*root = p;
		cout<<"element inserted hi";
		return;
	}
	struct tree *q;
	temp = *root;

	while(temp!=NULL)
	{

		q = temp;
		
		if(x > temp->data)
			temp = temp->right;
		else
			temp = temp->left;
	}

	if(x > q->data)
		q->right = p;
	else
		q->left = p;
	cout<<"element inserted"<<endl;
}

void preorder(struct tree *root)
{
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct tree *root)
{
        if(root == NULL)
                return;
        inorder(root->left);
	cout<<root->data<<" ";
        inorder(root->right);
}

void postorder(struct tree *root)
{
        if(root == NULL)
                return;
        postorder(root->left);
        postorder(root->right);
	cout<<root->data<<" ";
}

void max(struct tree *root)
{
	struct tree *q;
	q = root;
	if(root == NULL)
		cout<<endl<<"Tree is empty"<<endl;
	while(q->right!=NULL)
		q = q->right;
	
	cout<<endl<<"The max element is : "<<q->data<<endl;
}

void min(struct tree *root)
{
        struct tree *q;
        q = root;
	 if(root == NULL)
                cout<<endl<<"Tree is empty"<<endl;

        while(q->left!=NULL)
                q = q->left;

        cout<<endl<<"The min element is : "<<q->data<<endl;
}

void delete_node(struct tree *root)
{
	struct tree *temp,*q;
	cout<<"Enter the element : ";
	int x;
	cin>>x;

	temp= root;
	if(root == NULL)
	{
		cout<<"Tree is empty"<<endl;
		return ;
	}


	while(temp!=NULL)
	{
		 if(x == temp->data)
                        break;

		q = temp;
		
		if(x>temp->data)
			temp = temp->right;
		else
			temp = temp->left;
	}

	if(temp->right == NULL && temp->left == NULL)
	{
		//if(q == temp)
		//{
		//	temp = NULL;
		//}
			
		if(q->left == temp)
		{
			delete temp;
			q->left = NULL;
			temp = NULL;
		}
		else
		{
			delete temp;
			q->right = NULL;
			temp = NULL;
		}
	}
	else if(temp->left != NULL && temp->right!= NULL)
	{
		q = temp;
		q = q->left;
		struct tree *p;
	
		if(q->right == NULL)
		{
			temp->data = q->data;
			temp->left = q->left;
			delete q;
			q = NULL;
		}
		else
		{
			while(q->right != NULL)
			{
			p = q;
			 q = q->right;
			}

			temp->data = q->data;
			delete q;
			q = NULL;
			p->right = NULL;
		}
	}
	else
	{
		if(temp->right!=NULL)
		{
			if(temp == q->left)
			{
				q->left = temp->right;
				delete temp;
				temp = NULL;
			}
			else
			{
				q->right = temp->right;
				delete temp;
				temp = NULL;
			}
		}
		else
		{
			if(temp == q->left)
                        {
                                q->left = temp->left;
                                delete temp;
                                temp = NULL;
                        }
                        else
                        {
                                q->right = temp->left;
                                delete temp;
                                temp = NULL;
                        }
		}
	}
	cout<<"Element deleted successfully"<<endl;
}
	
		

int main()
{
	struct tree *root = new struct tree();
	root = NULL;

	int ch=1;

	while(ch!=8)
	{
		cout<<endl<<endl<<"WELCOME TO TREE? "<<endl<<endl;
		cout<<"WHAT DO YOU WANT TO DO?"<<endl;

		cout<<"1.insert\n2.preorder traversal\n3.inorder traversal\n4.postorder traversal\n5.max element\n6.min element\n7.delete\n8.exit\n\n";
		cout<<"enter your choice : ";
		cin>>ch;

		switch(ch)
		{
			case 1:insert(&root);break;
			case 2:cout<<"preorder is : "<<endl;preorder(root);break;
			case 3:cout<<"inorder is : "<<endl;inorder(root);break;
			case 4:cout<<"postoreder is : "<<endl;postorder(root);break;
			case 5:max(root);break;
			case 6:min(root);break;
			case 7:delete_node(root);break;
		}
	}
	return 0;
}

		