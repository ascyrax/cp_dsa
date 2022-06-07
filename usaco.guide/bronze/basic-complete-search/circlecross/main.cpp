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



string s;cin>>s;
vector<int>v[26];
for(int i=0;i<=51;i++){
    v[s[i]-65].pb(i);
}
// now all the 26 vectors have 2 ints in them..beginning and end index of each alphabet respectively
//for(auto i:v){
//    for(auto j:i)cout<<j<<" ";cout<<endl;
//}
for(int i=0;i<=25;i++){
    set<int>st;
    int beg=v[i][0],end=v[i][1];
    for(int j=beg+1;j<end;j++){
        st.insert(s[j]-65);
    }
    for(auto j:st)v[i].pb(j);
}
//for(auto i:v){
//    for(auto j:i)cout<<j<<" ";cout<<endl;
//}
vector<int>vnew[26];
for(int i=0;i<=25;i++){
    for(int j=2;j<int(v[i].size());j++){
        vnew[i].pb(v[i][j]);
    }
}
//for(auto i:vnew){
//    for(auto j:i)cout<<j<<" ";cout<<endl;
//}
int arr[26][26]={0};
for(int i=0;i<=25;i++){
    for(int j=0;j<int(vnew[i].size());j++){
        arr[i][vnew[i][j]]=1;
    }
}
//for(int i=0;i<=25;i++){
//    for(int j=0;j<=25;j++){
//        cout<<arr[i][j]<<" ";
//    }cout<<endl;
//}

for(int i=0;i<=25;i++){
    for(int j=0;j<=25;j++){
        arr[i][j]*=arr[j][i];
        arr[j][i]*=arr[i][j];
    }
}
int ans=0;
for(int i=0;i<=25;i++){
    for(int j=0;j<=25;j++){
        if(arr[i][j]==1)ans++;
    }
}
cout<<ans/2<<endl;














}//




































int main()
{
    startTime=(double)clock();
    freopen("circlecross.in","r",stdin);
    freopen("circlecross.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
