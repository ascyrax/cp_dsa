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
int ans=1e9;
vector<int>v(n);for(int &i:v)cin>>i;
for(int i=0;i<n;i++){
    int ts=0;
    for(int j=i;j<i+n;j++){
        ts+=(j-i)*v[j%n];
    }
    ans=min(ans,ts);
}
cout<<ans<<endl;




}//
























int main()
{
    startTime=(double)clock();
    freopen("cbarn.in","r",stdin);
    freopen("cbarn.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
