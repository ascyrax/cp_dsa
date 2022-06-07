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
vector<int>v(n),a(n);for(int &i:v)cin>>i;
a=v;int ia=0,icorrect=0;
sort(a.begin(),a.end());
for(int i=0;i<n;i++){
    //if(v[i]>v[i+1]){
    //    ia=i;ib=i+1;
    //}
    if(a[i]!=v[i]){
        if(v[i+1]==a[i]){
            ia=v[i];
        }else ia=a[i];
        break;
    }
}
int icurrent=0;
for(int i=0;i<n;i++){
    if(ia==a[i]){
        icorrect=i;
    }
    if(ia==v[i])
        icurrent=i;
}
//id se ib jaana hai
int icnt=0;
if(icurrent<icorrect){
  for(int i=icurrent+1;i<=icorrect;i++){
      if(v[i]!=v[i+1])icnt++;
  }
}else{
for(int i=min(icurrent,icorrect);i<max(icurrent,icorrect);i++){
    if(v[i]!=ia&&v[i]!=v[i+1]){
        icnt++;
    }
}}




cout<<icnt<<endl;

















}//




































int main()
{
    startTime=(double)clock();
    freopen("outofplace.in","r",stdin);
    freopen("outofplace.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
