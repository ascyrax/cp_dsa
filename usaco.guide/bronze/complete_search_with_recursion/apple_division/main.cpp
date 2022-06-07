/*
ID: ascyrax1
TASK: test
LANG: C++14
*/
/* LANG can be C++11 or C++14 for those more recent releases */
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
void suraj();











ll ans=1e11;//or 1e11 ie sth big

vector<ll>v;






ll n;





void call(ll a,ll b,ll c){//cout<<a<<" "<<b<<" "<<c<<endl;
    if(a==n){//cout<<"if"<<endl;
        ans=min(ans,abs(b-c));//cout<<ans<<endl;
        return;
    }else{//cout<<"else"<<endl;
        call(a+1,b+v[a],c);//cout<<"return "<<a<<" "<<b<<" "<<c<<endl;
//        b-=v[a];
        call(a+1,b,c+v[a]);
    }
}












void suraj(){
cin>>n;
for(int i=0;i<n;i++){
    int a;cin>>a;v.pb(a);
}

call(0,0,0);



cout<<ans<<endl;







}//




























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
