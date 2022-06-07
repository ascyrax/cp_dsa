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

int ans=0;
int n;cin>>n;int k;cin>>k;
vector<int>v(n);for(int &i:v)cin>>i;
sort(v.begin(),v.end());
for(int i=1;i<=10000-k;i++){
    auto left=lower_bound(v.begin(),v.end(),i);
    auto right=upper_bound(v.begin(),v.end(),i+k);
    int a=right-left;
    ans=max(ans,a);
}
cout<<ans<<endl;

}//
























int main()
{
    startTime=(double)clock();
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
