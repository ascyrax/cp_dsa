/*
ID: ascyrax1
TASK: test
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define endl "\n"
#define ioss ios::sync_with_stdio(false);cin.tie(0);
#define pb push_back

double startTime;
double gct()//get_current_time
{
    return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}
void suraj();




































void suraj(){///////////////////////


ll nb,ng;cin>>nb>>ng;
//cout<<"hi"<<endl;
vector<ll>eachboymin(nb);
for(ll &i:eachboymin)cin>>i;
vector<ll>eachgirlmax(ng);
for(ll &i:eachgirlmax)cin>>i;


sort(eachgirlmax.begin(),eachgirlmax.end());
sort(eachboymin.begin(),eachboymin.end());



// max among eachboymin should be > min among eachgirlmax
//otherwise ans=-1;
if(eachboymin[nb-1]<=eachgirlmax[0]){//cout<<"if"<<endl;
    ll ans=0;
    ll maxboy=eachboymin[nb-1];
    // biggest element of eachboymin will be providing eachboymin[nb-1] sweets
    // to the first girl(because it has to provide its min value to atleast one
    // girl for it to be called as his min value)and the max value(that the
    // girl receives) to the other girls
    ans+=maxboy;
    for(ll i=1;i<ng;i++){
        ans+=(eachgirlmax[i]);
    }//cout<<"ans "<<ans<<endl;
    // all other boys give their min value to all the girls
    // except the 2nd largest value waala boy will be giving eachgirlmax[0] gifts
    // to the first girl becz maxboy didn't give her eachgirlmax[0] gifts
    for(ll i=0;i<nb-1;i++){
        ans+=ng*eachboymin[i];
    }
//    cout<<"ans "<<ans<<endl;
//    ans-=eachboymin[nb-1];
    if(eachboymin[nb-1]!=eachgirlmax[0]){
        ans-=eachboymin[nb-2];
//        cout<<"ans "<<ans<<endl;
        ans+=eachgirlmax[0];
    }
    cout<<ans<<endl;

}else{
//    cout<<"else"<<endl;
    cout<<-1<<endl;
}










}////////////////////////////




























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
