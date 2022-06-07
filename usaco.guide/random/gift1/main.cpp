/*
ID: ascyrax1
TASK: gift1
LANG: C++14
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef  long long ll;
typedef long double ld;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
void suraj();
int main()
{
    startTime=(double)clock();
    freopen("gift1.in","r",stdin);freopen("gift1.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}

























void suraj(){
int n;cin>>n;
map<string,int>m;
vector<string>vnames;
for(int i=0;i<n;i++){
    string a;cin>>a;vnames.pb(a);
    m[a]=0;
}

//for(auto i:m)
//    cout<<i.first<<" "<<i.second<<endl;


for(int i=0;i<n;i++){//cout<<"hi"<<endl;
    string giver;cin>>giver;/*cin.ignore();*/
    int tot,ntaker;cin>>tot>>ntaker;//cout<<tot<<" "<<ntaker<<endl;
    if(ntaker==0)continue;
    int rem=tot%ntaker;
    int quo=tot/ntaker;
    m[giver]-=tot;
    m[giver]+=rem;//cout<<"a "<<m[giver]<<endl;
    for(int j=0;j<ntaker;j++){
        string taker;cin>>taker;
        m[taker]+=quo;//cout<<"b "<<m[taker]<<endl;
    }
}

//for(auto i:m)
//    cout<<i.first<<" "<<i.second<<endl;
for(string i:vnames){
    cout<<i<<" "<<m[i]<<endl;
}






















}//
