#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string cow[]={"Bessie","Elsie","Daisy","Gertie","Annabelle","Maggie","Henrietta"};
  int milk[]={0,0,0,0,0,0,0};
  cin>>n;
  for(int i = 1; i <= n; i++){
      string name;
      cin>>name;
      for(int j=0;j<7;j++){
          if(cow[j]==name){
            int x;
            cin>>x;
            milk[j]=milk[j]+x;
          }
      }


  }
   for(int j=0;j<7;j++){
   cout<<cow[j]<<' '<<milk[j]<<endl;}
}
