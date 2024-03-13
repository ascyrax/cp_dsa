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
int t;cin>>t;
for(int e=1;e<=t;e++){
int n;cin>>n;
vector<int>p(n),h(n);
for(int i=0;i<n;i++){
    cin>>p[i]>>h[i];
}
vector<array<int,2>>dp;
dp[0][0]=h[0];
dp[0][1]=h[0];
for(int i=1;;i++){
    dp[i][0]
}



    cout<<"Case #"<<e<<": ";
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
