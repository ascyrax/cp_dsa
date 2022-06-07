/*
ID: ascyrax1
TASK: test
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define endl "\n"
#define ioss ios::sync_with_stdio(false);cin.tie(0);
#define pb push_back

double startTime;
double gct()//get_current_time
{
    return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}
void suraj();




































void suraj(){///////////////////////
int n;cin>>n;
vector<int>v(n);for(int &i:v)cin>>i;
int sum=0;
//for(int i:v)cout<<i<<" ";cout<<endl;
for(int i=1;i<n;i++){
    auto loc=find(v.begin(),v.end(),i);
//    cout<<"loc "<<loc-v.begin()<<endl;
    sum+=(loc-(v.begin()+i-1))+1;
    if(loc!=v.end())loc++;
    reverse(v.begin()+i-1,loc);
//    for(int i:v)cout<<i<<" ";cout<<endl;
}
cout<<sum<<endl;














}////////////////////////////




























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;for(int i=1;i<=t;i++){cout<<"Case #"<<i<<": ";
    suraj();
    }
    return 0;
}
