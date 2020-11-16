using namespace std;
#include<bits/stdc++.h>

void merge(int arr[],int l,int mid,int r)
{
	int n1 = mid-l+1;
	int n2 = r-mid;
	
	int arr1[n1],arr2[n2];

	for(int i=0;i<n1;i++)
		arr1[i] = arr[l+i];

	for(int j=0;j<n2;j++)
		arr2[j] = arr[mid+j+1];


	int i=0,j=0,k=l;

	while(i<n1 && j<n2)
	{
		if(arr1[i] <= arr2[j])
		{
			arr[k] = arr1[i];
			i++;
		}
		else
		{
			arr[k] = arr2[j];
			j++;

		}
		k++;
	}


	while(i<n1)
	{
		arr[k] = arr1[i];
		i++;
		k++;
	}

	while(j<n2)
	{
		arr[k] = arr2[j];
		j++;
		k++;
	}
}

void merge_sort(int arr[],int l,int r)
{
        if(l<r)
        {
                int mid = (l+r)/2;

                merge_sort(arr,l,mid);
                merge_sort(arr,mid+1,r);
                merge(arr,l,mid,r);
        }
}


int main()
{
	int n;
	cout<<endl<<"Enter the no of elements : ";
	cin>>n;

	int arr[n];
	cout<<endl<<"Enter the array elements : ";
	for(int i=0;i<n;i++)
		cin>>arr[i];

	merge_sort(arr,0,n-1);

	cout<<"After sorting : "<<endl;

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	return 0;
}
  