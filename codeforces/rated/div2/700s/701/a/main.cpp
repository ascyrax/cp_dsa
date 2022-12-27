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
int ans=0;
ll a,b,bclone;cin>>a>>b;

if(a==b){
    cout<<2<<endl;return;
}else if(a<b){
    cout<<1<<endl;return;
}


if(b==1){
    bclone=2;
}else{
    bclone=b;
}

int minans=1e9;
//cout<<log(a)<<" "<<log(b)<<endl;
for(int j=bclone;j<=31;j++){
//    cout<<"hello "<<j<<" "<<minans<<" "<<endl;
    ans=int(log2(a)/log2(j))+j-b+1;
//    cout<<ans<<" ";


    if(ans<=minans){
        minans=ans;
    }else{
        break;
    }
}
cout<<minans<<endl;//
























}//




































int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
