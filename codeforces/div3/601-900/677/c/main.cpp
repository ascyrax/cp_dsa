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
int biggest=0;vector<int>ans;
int n;cin>>n;
vector<int>v(n);for(int &i:v)cin>>i;
for(int i=0;i<n;i++){
    if(v[i]>biggest){
        biggest=v[i];
    }
}int res=0;
for(int i=0;i<n;i++){
    if(v[i]==biggest)ans.pb(i);
}
//for(int i:ans)cout<<i<<" ";cout<<endl;
for(int i:ans){
        if(i==0){
            if(v[i+1]<biggest){
                res=i;break;
            }
        }else if(i==n-1){
            if(v[i-1]<biggest){
                res=i;break;
            }
        }else{
            if(v[i-1]<biggest||v[i+1]<biggest){
                res=i;break;
            }
        }
}
int flag=0;
for(int i=0;i<n-1;i++){
    if(v[i]!=v[i+1]){
        flag=1;break;
    }
}
if(flag==0){
    cout<<-1<<endl;
}else{
    cout<<res+1<<endl;
}






















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
