using namespace std;
#include<bits/stdc++.h>

int ** strassen(int n,int **A,int **B,int r,int c,int r1,int c1,int **res){

        int **M = new int*[n];int **N = new int*[n];
        for(int i=0;i<n;i++){
            M[i] = new int[n];
            N[i] = new int[n];
        }

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                M[i][j] = A[i+r][j+c];

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                N[i][j] = B[i+r1][j+c1];

        if(n==2)
        {
                int **C = new int*[2];
                for(int i=0;i<2;i++)
                    C[i] = new int[2];

                int p = (M[0][0] + M[1][1])*(N[0][0]+N[1][1]);
                int q = N[0][0]*(M[1][0] + M[1][1]);
                int r = M[0][0]*(N[0][1] - N[1][1]);
                int s = M[1][1]*(N[1][0] - N[0][0]);
                int t = N[1][1]*(M[0][0]+M[0][1]);
                int u = (M[1][0] - M[0][0])*(N[0][0] + N[0][1]);
                int v = (N[1][0]+N[1][1])*(M[0][1] - M[1][1]);

                C[0][0] = p+s-t+v;
                C[0][1] = r+t;
                C[1][0] = q+s;
                C[1][1] = p+r-q+u;
                //cout<<C[0][0]<<" "<<C[0][1]<<" "<<C[1][0]<<" "<<C[1][1]<<endl;
                return C;
        }

        int **temp = strassen(n/2,M,N,0,0,0,0,res);
        int **temp1 = strassen(n/2,M,N,0,n/2,n/2,0,res);

        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                res[i][j] = temp[i][j]+temp1[i][j];
            }
        }

        temp = strassen(n/2,M,N,0,0,0,n/2,res);
        temp1 = strassen(n/2,M,N,0,n/2,n/2,n/2,res);

        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                res[i][j+n/2] = temp[i][j]+temp1[i][j];
            }
        }

        temp = strassen(n/2,M,N,n/2,0,0,0,res);
        temp1 = strassen(n/2,M,N,n/2,n/2,n/2,0,res);

        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                res[i+n/2][j] = temp[i][j]+temp1[i][j];
            }
        }

        temp = strassen(n/2,M,N,n/2,0,0,n/2,res);
        temp1 = strassen(n/2,M,N,n/2,n/2,n/2,n/2,res);

        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                res[i+n/2][j+n/2] = temp[i][j]+temp1[i][j];
            }
        }
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
0
        arr2 = strassen(n,arr,arr1,0,0,0,0,arr2);

         cout<<"\nThe resultant matrix C = AXB : \n";

        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                        cout<<arr2[i][j]<<" ";
                cout<<endl;
        }
        return 0;
}
