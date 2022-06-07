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
map<string,vector<string>>start,code;
set<string>st;
vector<pair<string,string>>vp;
for(int i=0;i<n;i++){
    string a,b;cin>>a>>b;
    string two=a.substr(0,2);
//    cout<<two<<endl;
//      if(st.find(two)==st.end()){
//          st.insert(two);
//      }else{}
//    start[two]=a;
//    code[a]=b;
    st.insert(two);
    vp.pb(make_pair(a,b));
}
//for(auto i:vp)cout<<i.first<<" "<<i.second<<endl;
//for(auto i:st)cout<<i<<" ";cout<<endl;
vector<string>vs(st.size());
copy(st.begin(),st.end(),vs.begin());
//for(auto i:vs)cout<<i<<" ";cout<<endl;
int ans=0;
for(string s:vs){
   ;
}




//for(int i=0;i<n;i++){
//    string first=vp[i].first;string first_code=vp[i].second;
//    string second=start[first_code];
//    string second_code=code[second];
////    cout<<first<<" "<<first_code<<" "<<second<<" "<<second_code<<endl;
//    if(start[second_code]==first)ans++;
//}
//cout<<ans/2<<endl;























}//




































int main()
{
    startTime=(double)clock();
//    freopen("citystate.in","r",stdin);
//    freopen("citystate.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
