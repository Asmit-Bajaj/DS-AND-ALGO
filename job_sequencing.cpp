#include<bits/stdc++.h>
using namespace std;

struct job{
	int profit;
	int deadline;
	int no;
};

bool cmp(const struct job a,const struct job b)
{
	return a.profit > b.profit;
}

int main()
{
	int n;
	cout<<endl<<endl<<"Enter the number of jobs : ";
	cin>>n;
	int max,i;

	job *j = new struct job[n];
	
	for(i=0;i<n;i++){
		cout<<endl<<"Enter the profit : ";
		cin>>j[i].profit;
		cout<<"Enter the deadline : ";
		cin>>j[i].deadline;
		j[i].no = i+1;
		if(i==0)
			max = j[i].deadline;
		else{
			if(j[i].deadline > max)
				max = j[i].deadline;
		}
	}
	cout<<max;
	
	int *timeslot = new int[max];
	sort(j,j+n,cmp);

	for(i=0;i<max;i++){
		timeslot[i] = 0;
		//cout<<j[i].profit<<" ";
	}

	int k;
	int max_profit = 0; 
	for(i=0;i<n;i++)
	{
		k = min(max,j[i].deadline);
		
		while(k>=1)
		{
			if(timeslot[k-1] == 0){
				timeslot[k-1]=j[i].no;
				//cout<<k<<" ";
				//cout<<timeslot[k]<<" ";
				max_profit = max_profit+j[i].profit;	
				break;
			}
			k--;
			
		}
	}
	

	cout<<endl<<"Max profit : "<<max_profit;
	cout<<endl<<endl<<"The choosen jobs are : "<<endl<<endl;
	for(i=0;i<max;i++){
		if(timeslot[i] != 0)
		cout<<timeslot[i]<<" ";
	}

	return 0;
}