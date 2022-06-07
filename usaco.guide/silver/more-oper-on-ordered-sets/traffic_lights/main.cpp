#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef  long long ll;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define all(x)  x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
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


int x,n;cin>>x>>n;
set<int>v;
int t;cin>>t;
v.insert(t);
int ans=t;
ans=max(ans,x-t);
cout<<ans<<" ";
for(int i=1;i<n;i++){
    int ta;cin>>ta;
    v.insert(ta);
    ans=*v.begin()-0;
    auto tb=v.end();tb--;
    ans=max(ans,x-*tb);
    auto tc=v.lower_bound(ta);
    auto td=v.begin();auto te=v.end();
    if(tc==v.begin()){
        ans=max(ans,*(++td)-ta);
    }else if(tc==(--te)){
        ans=max(ans,x-ta);
    }else{
        ans=max(ans,ta-*(--tc));tc++;tc++;
        ans=max(ans,*tc-ta);
    }


    cout<<ans<<" ";
}
cout<<endl;


}//
























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++){cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
