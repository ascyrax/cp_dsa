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
int ans=0;int tans=0;
// i wins over i+1 and i looses to i-1
for(auto j:v){
    int f=j.first;
    int s=j.second;
    if(f==3)f=1;
    else if(f==2)f=3;
    else if(f==1)f=2;
    if(f==s){
        //cout<<j.first<<" "<<j.second<<endl;
        tans++;
    }

}
ans=max(ans,tans);
tans=0;
//i looses to i+1 and wins over i-1
for(auto j:v){
    int f=j.first;
    int s=j.second;
    if(f==3)f=2;
    else if(f==2)f=1;
    else if(f==1)f=3;
    if(f==s){
        tans++;
    }

}
ans=max(ans,tans);
cout<<ans<<endl;


}//
























int main()
{
    startTime=(double)clock();
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
