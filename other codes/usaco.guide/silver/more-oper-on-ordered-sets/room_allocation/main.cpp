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

int n;cin>>n;
set<tuple<int,int,int>>a;
int nrooms=0;
multiset<pair<int,int>>sp;
vector<int>ans(n);
for(int i=0;i<n;i++){
    int ta,tb;cin>>ta>>tb;
    a.insert(make_tuple(tb,ta,i));
}
for(auto i=a.begin();i!=a.end();i++){
    auto t=*i;
    auto ta=get<1>(t);
    auto tb=get<0>(t);
    auto tc=get<2>(t);
    if(sp.empty()){//cout<<"a "<<tc<<endl;
        sp.insert(make_pair(tb,ta));ans[tc]=1;
    }else{
        if(sp.begin()->first<ta){//cout<<"b "<<tc<<" ";
            sp.erase(sp.begin());
            sp.insert(make_pair(tb,ta));ans[tc]=1;//cout<<sp.size()<<endl;
        }else{//cout<<"c "<<tc<<" ";
            sp.insert(make_pair(tb,ta));ans[tc]=int(sp.size());//cout<<sp.size()<<endl;
        }
    }
    nrooms=max(nrooms,int(sp.size()));
    //cout<<nrooms<<endl;
}
cout<<nrooms<<endl;
for(int i:ans)cout<<i<<" ";cout<<endl;



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
