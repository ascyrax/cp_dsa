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



























void suraj(){


int sum=0;
int n,m,k;cin>>n>>m>>k;
vector<vector<int>>vv(n);
for(int i=0;i<n;i++){
    vector<int>temp(m);
    for(int &j:temp)cin>>j;
    sort(temp.rbegin(),temp.rend());
    for(int j=0;j<m/2;j++){
        sum+=temp[j];
    }
    vv[i]=temp;
}
int rem=sum%k;
vector<int>diff;
if(rem==0){
    cout<<sum<<endl;
}else{
    for(auto v:vv){
        for(int i=0;i<m/2;i++){
            for(int j=m/2;j<m;j++){
                int ta=v[i]-v[j];
                diff.pb(ta);
            }
        }
    }
    sort(diff.begin(),diff.end());
    for(int i:diff){
        if(i==rem){
            cout<<sum-rem<<endl;return;
        }
    }
}


















}//




































int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
