#include<bits/stdc++.h>
using namespace std;
struct process{
    int at;
    int bt;
    int ct;
    int id;
};

bool cmp(const struct process &a,const struct process &b){
    return a.at<b.at;
}

bool cmp1(const struct process &a,const struct process &b){
    return a.bt<b.bt;
}

bool cmp2(const struct process &a,const struct process &b){
    return a.id<b.id;
}

int main(){

    int n;
    cout<<"Enter the number of process : ";
    cin>>n;
    process *p = new process[n];
    //struct process p[n];
    int i;
    for(i=0;i<n;i++){
        cout<<endl<<"Enter the arrival time of process - "<<i+1<<" : ";
        cin>>p[i].at;
        cout<<"Enter the burst time of process - "<<i+1<<" : ";
        cin>>p[i].bt;
        p[i].id = i+1;
    }

    sort(p,p+n,cmp); //sort on the basis of at

    //for(i=0;i<n;i++){
      //  cout<<p[i].at<<" "<<p[i].bt<<endl;
    //}
    int ct = p[0].at;
    int count =0;
    int flag = 0;
    int start,last;
    while(count != n){
            //find the range of those process which arrives at present ct
        for(i=count;i<n;i++){
            if(p[i].at <= ct){
                if(flag == 0){
                    flag = 1;
                    start = i;
                    last = start+1;
                }else{
                    last++;
                }
            }
        }
        if(flag !=0){ //sort the range on the basis of bt and choose that process
            sort(p+start,p+last,cmp1);
            p[start].ct = ct+p[start].bt;
            ct = p[start].ct;
            flag = 0;
            count++;
        }else{
            int temp = p[count].at; //if no process arrived then find the smallest at from the remaining list
            for(i=count+1;i<n;i++){
                if(p[i].at < temp)
                    temp = p[i].at;
            }
            ct = temp;
        }
    }
    sort(p,p+n,cmp2); //sort on the basis of id
    double avg_wt =0;
    double avg_tat = 0;
    cout<<endl<<"PNO\tAT\tBT\tCT\tTAT\tWT\tRT"<<endl;
    int tat;
    int wt;

    for(i=0;i<n;i++){
            tat = p[i].ct-p[i].at;
            wt = tat-p[i].bt;
            cout<<p[i].id<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<tat<<"\t"<<wt<<"\t"<<wt<<endl;
            avg_wt = avg_wt+wt;
            avg_tat = avg_tat+tat;
    }

    cout<<endl<<"The average waiting time is : "<<(double)avg_wt/n;
    cout<<endl<<"The average tat is : "<<(double)avg_tat/n<<endl<<endl;
    return 0;
}
