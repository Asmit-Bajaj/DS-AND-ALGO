using namespace std;
#include<bits/stdc++.h>

bool cmp(const pair<float,pair<float,float> > &a,const pair<float,pair<float,float> > &b)
{
        return a.first>b.first;
}

void knapsack(float weight[],int n,float profit[],int cap)
{
        vector<pair<float,pair<float,float> > >v;

        for(int i=0;i<n;i++)
        {
                v.push_back(make_pair(profit[i]/weight[i],make_pair(weight[i],profit[i])));
        }

        sort(v.begin(),v.end(),cmp);

        float max_profit = 0;

        for(int i = 0;i<v.size();i++){
                if(cap - v[i].second.first == 0)
                {
                        max_profit+=v[i].second.second;
                        break;
                }
                else if(cap - v[i].second.first < 0){
                        max_profit=max_profit+((cap/v[i].second.first)*v[i].second.second);
                        break;
                }

                max_profit+= v[i].second.second;
                cout<<max_profit<<endl;
                cap-=v[i].second.first;
        }

        cout<<"The maximum profit is : "<<max_profit<<endl;
}

int main()
{
        float m;
        cout<<endl<<endl<<"Enter the knapsack capacity : ";
        cin>>m;

        int n;
        cout<<endl<<"Enter the no of objects : ";
        cin>>n;

        cout<<"Enter the profits : ";
        float profit[n];

        for(int i=0;i<n;i++)
                cin>>profit[i];

        cout<<"Enter the weights : ";
        float weight[n];

        for(int i=0;i<n;i++)
                cin>>weight[i];

        knapsack(weight,n,profit,m);

        return 0;
}
