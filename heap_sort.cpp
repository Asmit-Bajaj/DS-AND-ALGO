using namespace std;
#include<bits/stdc++.h>

struct heap
{
	int *arr;
	int size;
	int cap;
};

int left(struct heap *h,int i)
{
	if( h->cap == 0 || 2*i+1 >= h->size)
		return -1;

	return 2*i+1;
}

int right(struct heap *h,int i)
{
        if( h->cap == 0 || 2*i+2 >= h->size)
                return -1;

        return 2*i+2;
}

void heapify(struct heap *h,int i)
{
	int l = left(h,i);
	int r = right(h,i);
	int largest;
	if(l!=-1 && h->arr[l] > h->arr[i])
		largest = l;
	else
		largest = i;

	if(r!=-1 && h->arr[r] > h->arr[l])
                largest = r;
        
	
	if(largest!=i)
	{
		int temp = h->arr[i];
		h->arr[i] = h->arr[largest];
		h->arr[largest] = temp;
	}
	else
		return;

	heapify(h,largest);
}

void insert_heap(struct heap *h,int data)
{
    h->size++;
    int i = h->size-1;

    while(i>0 && data > h->arr[(i-1)/2])
    {
        h->arr[i] = h->arr[(i-1)/2];
        i = (i-1)/2;
    }

    h->arr[i] = data;
}

void heap_sort(struct heap *h)
{
	int old_size = h->size;
	for(int i=old_size-1;i>0;i--)
	{
		int temp = h->arr[0];
		h->arr[0] = h->arr[i];
		h->arr[i] = temp;
		h->size--;
		heapify(h,0);
	}
	h->size = old_size;
}

int main()
{
	struct heap *h = new struct heap();
	cout<<"Enter the heap capacity : ";
	int n;
	cin>>n;

	h->cap = n;
	h->size = 0;
	h->arr = new int[n];

	cout<<"Enter the array : ";

	int temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		insert_heap(h,temp);
	}
	
	 for(int i=0;i<n;i++)
                cout<<h->arr[i]<<" ";

	heap_sort(h);
	
	cout<<endl<<"after performing heap sort : ";

	for(int i=0;i<n;i++)
		cout<<h->arr[i]<<" ";

	return 0;
}	