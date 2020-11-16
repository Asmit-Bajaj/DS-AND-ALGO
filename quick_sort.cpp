using namespace std;
#include<bits/stdc++.h>

int partition(int arr[],int l,int r)
{
        int x = arr[l];
        int i=l;

        for(int j=l+1;j<=r;j++)
        {
                if(arr[j] <=x)
                {
                        i++;
                        swap(arr[i],arr[j]);
                }
        }
        swap(arr[l],arr[i]);
        return i;
}

int random_partition(int arr[],int l,int r)
{
	int p = (l+r)/2;
	swap(arr[l],arr[p]);
	return partition(arr,l,r);
}
	

void quick_sort(int arr[],int l,int r)
{
        if(l<r)
        {
                int part = random_partition(arr,l,r);
                quick_sort(arr,l,part-1);
                quick_sort(arr,part+1,r);
        }
}

int main()
{
        cout<<endl<<"Enter the no of elements : ";
        int n;
        cin>>n;
        int arr[n];
        cout<<endl<<"Enter the array elements : ";

        for(int i=0;i<n;i++)
                cin>>arr[i];

        cout<<endl<<"After sorting : ";
        quick_sort(arr,0,n-1);

 	for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";

        return 0;
}
