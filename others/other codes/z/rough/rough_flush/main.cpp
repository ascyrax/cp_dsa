#include <bits/stdc++.h>

using namespace std;




void suraj(){
    int n;cin>>n;

    vector<int>v(n);
    for(int &i:v)cin>>i;
    int sum=0;
    for(int i:v)sum+=i;
    cout<<sum<<endl;
}






int main()
{
    cout << "Hello World!" << endl;

   int t;cin>>t;
   for(int i=0;i<t;i++){
       suraj();
   }

    return 0;
}
