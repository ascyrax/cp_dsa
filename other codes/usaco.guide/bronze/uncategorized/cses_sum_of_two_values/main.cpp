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

int n,x;cin>>n>>x;
vector<int>v(n);
vector<pair<int,int>>t;
for(int i=0;i<n;i++){
   cin>>v[i];
   t.pb(make_pair(v[i],i+1));
}
sort(t.begin(),t.end());

for(int i=x-1;i>=1;i--){
    auto ita=lower_bound(t.begin(),t.end(),i)-t.begin();
    if(t[ita].first==i){
        //cout<<i<<" "<<*ita<<endl;
        //cout<<ita-v.begin()<<endl;
        auto itb=lower_bound(t.begin(),t.end(),x-i)-t.begin();
        if(ita!=itb&&t[itb].first==x-i){
            cout<<t[itb].second<<" "<<t[ita].second<<endl;
            return;
        }
    }
}

cout<<"IMPOSSIBLE"<<endl;

}//
























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
