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
int n,t;cin>>n>>t;
string current;cin>>current;
vector<pair<int,pair<int,int>>>v;
for(int i=0;i<n;i++){
    int a,b,c;cin>>a>>b>>c;
    v.pb(make_pair(a,make_pair(b,c)));
}
sort(v.begin(),v.end());
set<int>suspects;
for(int i=0;i<n;i++){
    int time=v[i].first;
    int cowa=v[i].second.first;
    int cowb=v[i].second.second;
    if(current[cowa-1]=='1'&&current[cowb-1]=='1'){
        suspects.insert(cowa);suspects.insert(cowb);
    }else if(current[cowa-1]=='1'){
        suspects.insert(cowa);
    }else if(current[cowb-1]=='1'){
        suspects.insert(cowb);
    }else if
}





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
