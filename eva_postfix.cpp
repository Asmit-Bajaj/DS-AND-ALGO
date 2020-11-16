using namespace std;
#include<iostream>
#include<cmath>
#include<cstring>

int main()
{
	int ch[100],top = -1,a,b,i=0,d;
	
	string c;
	cout<<endl<<"Enter the expression : ";
	cin>>c;
	
	while(c[i] != '\0')
	{
		if(c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/' || c[i] == '^')
		{
			a = ch[top--];
                        b = ch[top--];
                        switch(c[i])
			{
				case '+' : ch[++top] = b+a;break;
				case '-' : ch[++top] = b-a;break;
				case '*' : ch[++top] = b*a;break;
				case '/' : ch[++top] = b/a;break;
				case '^' : ch[++top] = pow(b,a);break;
			}

		}
		else if(c[i] > 47 && c[i] < 59)
		{
			d = c[i]-48;
			ch[++top] = d;
		}
		i++;
	}
		cout<<endl<<"The resultant is : "<<ch[0]<<endl;
	return 0;
}
			
