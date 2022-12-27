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
vector<int>arr(n);for(int &i:arr)cin>>i;
int k;cin>>k;
vector<pair<int,int>>q(k);for(auto &i:q)cin>>i.first>>i.second;

sort(arr.begin(),arr.end());

for(auto query:q){
    auto left=lower_bound(arr.begin(),arr.end(),query.first)-arr.begin();
    auto right=upper_bound(arr.begin(),arr.end(),query.second)-arr.begin();
    cout<<right-left<<" ";

}







}////////////////////////////




























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
