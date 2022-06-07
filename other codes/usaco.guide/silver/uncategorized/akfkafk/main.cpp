#include<bits/stdc++.h>
using namespace std;
char c[2],d[2],a,b;
int main(){
    cin>>c>>d;
    int x=c[0]-d[0],y=c[1]-d[1];
    a=x<0?x=-x,82:76;b=y<0?y=-y,85:68;
    cout<<max(x,y)<<endl;
    while(x|y){
        if(x){cout<<a;x--;}//
        if(y){cout<<b;y--;}
        cout<<endl;
    }
}
