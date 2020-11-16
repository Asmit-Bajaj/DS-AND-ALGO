using namespace std;
#include<bits/stdc++.h>

void insertion_sort(int arr[],int n)
{
        for(int i=1;i<=n;i++)
        {
                int key = arr[i];
                int j=i-1;

                while(j>=0 && arr[j]>key)
                {
                        arr[j+1] = arr[j];
                        j--;
                }

                arr[j+1] = key;
        }
}

int main()
{
        int n;
        cout<<"Enter the number of elemnts : ";
        cin>>n;

        int arr[n];

        cout<<endl<<"Enter the array elements : ";

        for(int i=0;i<n;i++)
                cin>>arr[i];

        insertion_sort(arr,n);

        cout<<endl<<"After the sorting : "<<endl;

        for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";

        return 0;
}
