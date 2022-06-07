#include <bits/stdc++.h>
#include <cstdio>
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
vector<pair<int,int>>swap;
vector<int>v;
for(int i=0;i<n;i++){
    int a,b,c;cin>>a>>b>>c;
    swap.pb(make_pair(a,b));
    v.pb(c);
}
int anss=0;
for(int coin=1;coin<=3;coin++){
    int ptr=coin;
    int ans=0;
    for(int i=0;i<n;i++){
        int a=swap[i].first;
        int b=swap[i].second;
        if(a==ptr||b==ptr){
            if(a==ptr)ptr=b;
            else ptr=a;
        }
        if(v[i]==ptr)ans++;
    }
    anss=max(ans,anss);
}


cout<<anss<<endl;


}//
























int main()
{
    startTime=(double)clock();
    freopen("shell.in","r",stdin);
    freopen("shell.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
