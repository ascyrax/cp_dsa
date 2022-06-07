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
int n;cin>>n;int m;cin>>m;

vector<string>spotty(n),plain(n);
for(auto &i:spotty)cin>>i;
for(auto &i:plain)cin>>i;

set<char>s[m],p[m];
for(int i=0;i<n;i++){
    string a=spotty[i];
    string b=plain[i];
    for(int j=0;j<m;j++){
        s[j].insert(a[j]);
        p[j].insert(b[j]);
    }
}

//for(auto a:s){
//    for(auto b:a){
//        cout<<b<<" ";
//    }cout<<endl;
//}
//for(auto a:p){
//    for(auto b:a){
//        cout<<b<<" ";
//    }cout<<endl;
//}


//vector<char>vs[m],vp[m];
int ans=0;

for(int i=0;i<=m-3;i++){
    for(int j=i+1;j<=m-2;j++){
        for(int k=j+1;k<=m-1;k++){set<char>a,b;
              for(auto i:s[i])a.insert(i);
              for(auto i:s[j])a.insert(i);
              for(auto i:s[k])a.insert(i);
              for(auto i:p[i])b.insert(i);
              for(auto i:p[j])b.insert(i);
              for(auto i:p[k])b.insert(i);
//              for(auto i:a)cout<<i<<" ";cout<<endl;
//              for(auto i:b)cout<<i<<" ";cout<<endl;
              if(a==b){
                  ans++;
              }
        }
    }
}






cout<<ans<<endl;










}//




































int main()
{
    startTime=(double)clock();
    freopen("cownomics.in","r",stdin);
    freopen("cownomics.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
