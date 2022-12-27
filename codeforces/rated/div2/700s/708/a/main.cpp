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
vector<int>v(n);
set<int>s;
map<int,int>m;
for(int i=0;i<n;i++){
    int a;cin>>a;
    v[i]=a;
    s.insert(a);
    m[a]++;
}



for(auto i:s)cout<<i<<" ";
for(auto i:m){
    if(i.second>1){
        for(int j=i.second;j>1;j--){
            cout<<i.first<<" ";
        }
    }
}cout<<endl;










}////////////////////////////




























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
