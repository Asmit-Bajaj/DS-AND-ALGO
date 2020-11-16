using namespace std;
#include<bits/stdc++.h>

int ** add(int n,int **m1,int **m2,int r1,int c1,int r2,int c2){
    int **res = new int*[n];
    for(int i=0;i<n;i++)
        res[i] = new int[n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res[i][j] = m1[i+r1][j+c1]+m2[i+r2][j+c2];
        }
    }
    return res;
}

int ** sub(int n,int **m1,int **m2,int r1,int c1,int r2,int c2){
    int **res = new int*[n];
    for(int i=0;i<n;i++)
        res[i] = new int[n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res[i][j] = m1[i+r1][j+c1]-m2[i+r2][j+c2];
        }
    }
    return res;
}

int ** get(int n,int **m1,int r1,int c1){
    int **res = new int*[n];
    for(int i=0;i<n;i++)
        res[i] = new int[n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            res[i][j] = m1[i+r1][j+c1];
    }
    return res;
}

void form(int n1,int **res,int **m2,int r1,int c1){
    for(int i=0;i<n1;i++){
        for(int j=0;j<n1;j++)
            res[i+r1][j+c1] = m2[i][j];
    }
}

int ** strassen(int n,int **A,int **B){

    if(n==1){
        int **C = new int*[1];
        C[0] = new int[1];
        C[0][0] = A[0][0]*B[0][0];
        //cout<<C[0][0]<<endl;
        return C;
    }

    int **p = strassen(n/2,add(n/2,A,A,0,0,n/2,n/2),add(n/2,B,B,0,0,n/2,n/2));
    int **q = strassen(n/2,add(n/2,A,A,n/2,0,n/2,n/2),get(n/2,B,0,0));
    int **r = strassen(n/2,get(n/2,A,0,0),sub(n/2,B,B,0,n/2,n/2,n/2));
    int **s = strassen(n/2,get(n/2,A,n/2,n/2),sub(n/2,B,B,n/2,0,0,0));
    int **t = strassen(n/2,add(n/2,A,A,0,0,0,n/2),get(n/2,B,n/2,n/2));
    int **u = strassen(n/2,sub(n/2,A,A,n/2,0,0,0),add(n/2,B,B,0,0,0,n/2));
    int **v = strassen(n/2,sub(n/2,A,A,0,n/2,n/2,n/2),add(n/2,B,B,n/2,0,n/2,n/2));

    int **res = new int*[n];
    for(int i=0;i<n;i++)
        res[i] = new int[n];

    int **temp = add(n/2,add(n/2,p,v,0,0,0,0),sub(n/2,s,t,0,0,0,0),0,0,0,0);
    form(n/2,res,temp,0,0);

    temp = add(n/2,r,t,0,0,0,0);
    form(n/2,res,temp,0,n/2);

    temp = add(n/2,q,s,0,0,0,0);
    form(n/2,res,temp,n/2,0);

    temp = add(n/2,add(n/2,p,u,0,0,0,0),sub(n/2,r,q,0,0,0,0),0,0,0,0);
    form(n/2,res,temp,n/2,n/2);

    return res;
}

int main()
{
        int n;
        cout<<"\nEnter the dimensions : ";
        cin>>n;

        int **arr = new int*[n];
        int **arr1 = new int*[n];
        int **arr2 = new int*[n];

        for(int i=0;i<n;i++){
                arr[i] = new int[n];
                 arr1[i] = new int[n];
                arr2[i] = new int[n];
        }

        cout<<"\nEnter the matrix A : \n";

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>arr[i][j];
        }

        cout<<"\nEnter the matrix B : \n";

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>arr1[i][j];
        }

        arr2 = strassen(n,arr,arr1);

         cout<<"\nThe resultant matrix C = AXB : \n"<<endl;

        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                        cout<<arr2[i][j]<<" ";
                cout<<endl;
        }
        return 0;
}
