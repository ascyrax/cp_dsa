#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,j=1;
    int c[3],m[3];
    for (int i=0;i<3;i++){
  cin>>a>>b;
  c[i]=a;
  m[i]=b;
    }
cout<<m[0]<<" "<<m[1]<<" "<<m[2]<<endl;
    if ((m[0]+m[1])<=c[1]){
        m[0]=0;
        m[1]=m[0]+m[1];
    }
    else if ((m[0]+m[1])>c[1]){
        m[0]=(m[0]+m[1])-c[1];
        m[1]=c[1];
    }
   cout<<m[0]<<endl<<m[1]<<endl<<m[2]<<endl;
    if ((m[1]+m[2])<=c[2]){
        m[1]=0;
        m[2]=m[1]+m[2];
    }
    else if ((m[1]+m[2])>c[2]){
        m[1]=(m[1]+m[2])-c[2];
        m[2]=c[2];
    }
    cout<<m[0]<<endl<<m[1]<<endl<<m[2]<<endl;
    if ((m[2]+m[0])<=c[0]){
        m[2]=0;
        m[0]=m[2]+m[0];
    }
    else if ((m[2]+m[0])>c[0]){
        m[2]=(m[2]+m[0])-c[0];
        m[0]=c[0];
    }


   cout<<m[0]<<endl<<m[1]<<endl<<m[2]<<endl;
}
