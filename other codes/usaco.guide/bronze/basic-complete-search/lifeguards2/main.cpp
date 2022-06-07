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
vector<pair<int,int>>vp;
vector<int>count(1001);
for(int i=0;i<n;i++){
    int ta,tb;cin>>ta>>tb;
    for(int i=ta;i<tb;i++){
        count[i]++;
    }
    vp.pb(make_pair(ta,tb));
}
int thor=0;
for(auto t:vp){
    for(int i=t.first;i<t.second;i++){
        count[i]--;
    }
    int ta=0;
    for(int i=0;i<=1000;i++){
        if(count[i]>0)ta++;
    }
    thor=max(thor,ta);
    for(int i=t.first;i<t.second;i++)count[i]++;
}

cout<<thor<<endl;



}//
























int main()
{
    startTime=(double)clock();
    freopen("lifeguards.in","r",stdin);
    freopen("lifeguards.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++){cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
