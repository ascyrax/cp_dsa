#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef  long long ll;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
vector<pair<int,int>>v;
for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;
    v.pb(make_pair(a,b));
}
//assuming cows get in a queue as soon as they arrive and the order of the queue is not altered
sort(v.begin(),v.end());
int ans=0;
for(auto i:v){
    ans=max(ans,i.first)+i.second;
}
cout<<ans<<endl;


}//
























int main()
{
    startTime=(double)clock();
    freopen("cowqueue.in","r",stdin);
    freopen("cowqueue.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
