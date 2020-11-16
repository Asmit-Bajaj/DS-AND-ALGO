using namespace std;
#include<iostream>

int fib(int n)
{
        if(n<=1)
                return 1;
        else
                return fib(n-1)+fib(n-2);
}

int main()
{
        int n;
        cout<<endl<<endl<<"Enter the no of terms : ";
        cin>>n;

        for(int i=0;i<n;i++)
        {
                cout<<fib(i)<<" ";
        }
        return 0;
}
