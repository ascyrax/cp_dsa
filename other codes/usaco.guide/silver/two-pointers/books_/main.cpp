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


int n,t;cin>>n>>t;
vector<int>v(n);
for(int &i:v)cin>>i;


vector<int>ps(n+1);
for(int i=1;i<=n;i++){
    ps[i]=ps[i-1]+v[i-1];
}
//for(int i:ps)cout<<i<<" ";cout<<endl;
int l=0,r=0,ans=0;
for(int l=0;l<=n-1;l++){
    int sum=ps[r+1]-ps[l];
//    cout<<"sum"<<sum;
    if(sum>t){continue;}
    else {ans=max(ans,r-l+1);}
    while(sum<t&&r<=n-2){
        r++;
        sum=ps[r+1]-ps[l];
        if(sum==t){//cout<<"sum >=t again "<<sum<<endl;
            ans=max(ans,r-l+1);break;
        }else if(sum>t){
            break;
        }else{
//            cout<<"sum <t again "<<sum<<endl;
            ans=max(ans,r-l+1);
        }
    }
}


cout<<ans<<endl;




















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
