#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef  long long ll;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define endl "\n"
#define ioss ios::sync_with_stdio(false);cin.tie(0);
#define pb push_back
#define eb emplace_back

double startTime;
double gct()//get_current_time
{
    return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}





























void suraj(){

int n;cin>>n;
vector<int>va;
for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b;
    va.pb(a);
}
sort(va.begin(),va.end());

for(int i=0;i<sz(va)-1;i++){
    if(va[i]==va[i+1]){//becz there is only one "sink" and if there are two outgoing conveyors
        //from a factory then it violates the case of only one "sink" cz the structure is a tree and there
        //are no cycles in a tree.
        cout<<-1<<endl;return;
    }
}
for(int i=0;i<sz(va);i++){
    if(va[i]!=i+1){
        cout<<i+1<<endl;return;
    }
}
//cout<<"YES"<<endl;
}//
























int main()
{
    startTime=(double)clock();
    freopen("factory.in","r",stdin);
    freopen("factory.out","w",stdout);
    ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
