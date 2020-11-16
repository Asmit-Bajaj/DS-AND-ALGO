#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b,int &x,int &y){
    if(b==0){
        x = 1;
        y = 0;
        return a;
    }
    int x1,y1;
    int d = gcd(b,a%b,x1,y1);
    x = y1;
    y = x1-(y1*(int)(a/b));
    return d;
}

int lde(int a,int b,int c,int &x,int &y){
    int ans = gcd(a,b,x,y);
    x = x*c;
    y = y*c;
    cout<<x<<" "<<y<<endl;
    return 0;
}

int main(){

    cout<<lde(1,1,11,x,y);
    return 0;
}
