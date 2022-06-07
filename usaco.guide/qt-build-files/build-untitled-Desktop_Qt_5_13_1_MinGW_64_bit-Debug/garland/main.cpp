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

int n;cin>>n;
string s;cin>>s;
int q;cin>>q;
vector<pair<int,char>>vp(q);
for(auto &i:vp)cin>>i.first>>i.second;
//for(auto &i:vp)cout<<i.first<<" "<<i.second<<endl;
int cnt=0,tc=0;int ans=0;
for(auto i:vp){
    int ia=i.first;char cb=i.second;
    for(int i=0;i<n;i++){
        int ic=ia;
        int j=i;
        for(;j<n||ic>=0;j++){
            //cout<<s[j]<<" "<<cb<<endl;
            if(ic==0){
                if(s[j]==cb)continue;
                else break;
            }
            if(s[j]!=cb){ic--;}
        }
        if(ic==0){
            int ie=j-i;//cout<<ie<<endl;
            ans=max(ans,ie);
        }
    }
    cout<<min(ans,n)<<endl;ans=0;
}
















}//



































/*for(auto i:vp){
    int ia=i.first;
    char cb=i.second;
    vector<int>td(n);
    for(int i=0;i<n;i++){
        if(s[i]==cb)td[i]=1;
    }
    for(int i=1;i<n;i++){
        td[i]=td[i-1]+td[i];
    }
    for(int i=0;i<=n-ia;i++){
        if(s[i]==cb){
            cnt=td[i+ia-1]-td[i]+1;
        }else{
            cnt=td[i+ia-1]-td[i];
        }
        tc=max(tc,cnt);cnt=0;
    }
    cout<<min(n,tc+ia)<<endl;
    tc=0;
}
*/


















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
