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
map<string,string>in;
map<string,int>ma;
for(int i=0;i<n;i++){
    string a,b;cin>>a>>b;
    in[a]=b;
    string c=a.substr(0,2)+b;
    ma[c]++;
}
int ans=0;
for(auto it=in.begin();it!=in.end();it++){
    ans+=ma[it->second+(it->first).substr(0,2)];
}

cout<<ans/2<<endl;


}//
























int main()
{
    startTime=(double)clock();
    freopen("citystate.in","r",stdin);
    freopen("citystate.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
