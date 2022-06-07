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

ll a,b,c;cin>>a>>b>>c;
ll m;cin>>m;
map<string,ll>count;
vector<ll>vusb,vps2;
for(ll i=0;i<m;i++){
    ll price;cin>>price;
    string type;cin>>type;
    if(type=="USB"){
        vusb.pb(price);
         count["usb"]++;
    }else{
        count["ps2"]++;
        vps2.pb(price);
    }
}

sort(vusb.begin(),vusb.end());
sort(vps2.begin(),vps2.end());

ll totalCost=0;
ll mousesBought=0;
vector<ll>remaining;

//cout<<count["usb"]<<" "<<count["ps2"]<<endl;
if(count["usb"]>=a){
    mousesBought+=a;
    for(ll i=0;i<a;i++){
        totalCost+=vusb[i];
    }
    for(ll i=a;i<vusb.size();i++){
        remaining.pb(vusb[i]);
    }
}else{
    mousesBought+=count["usb"];
    for(ll i=0;i<count["usb"];i++){
        totalCost+=vusb[i];
    }
}
//cout<<"totalCost "<<totalCost<<endl;
//for(ll i:remaining)cout<<i<<" ";cout<<endl;
//cout<<"remaining ";for(ll i:remaining)cout<<i<<" ";cout<<endl;
if(count["ps2"]>=b){
    mousesBought+=b;
    for(ll i=0;i<b;i++){
        totalCost+=vps2[i];
    }
    for(ll i=b;i<vps2.size();i++){
        remaining.pb(vps2[i]);
    }
}else{
    mousesBought+=count["ps2"];
    for(ll i:vps2)totalCost+=i;
}

//cout<<"remaining ";for(ll i:remaining)cout<<i<<" ";cout<<endl;
//cout<<"totalCost "<<totalCost<<endl;
sort(remaining.begin(),remaining.end());

//for(ll i:vusb)cout<<i<<" ";cout<<endl;
//for(ll i:vps2)cout<<i<<" ";cout<<endl;
//for(ll i:remaining)cout<<i<<" ";cout<<endl;

for(ll i=0;i<min(ll(remaining.size()),c);i++){
    totalCost+=remaining[i];mousesBought++;
//    cout<<"Hi"<<endl;
}


cout<<mousesBought<<" "<<totalCost<<endl;








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
