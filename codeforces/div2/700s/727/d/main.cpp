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












// @author: ascyrax




























//...............................



void suraj(){

ll n;cin>>n;
vector<pair<ll,ll>>items(n);
for(ll i=0;i<n;i++){
    items[i].second>>items[i].first;
}

sort(items.begin(),items.end());

ll sum=0;

ll ptrtop=0,ptrbottom=n-1;
ll ncopy=n;
ll bought=0ll,left=n;
while(left>0){
    if(items[ptrtop].first<=left){
        sum+=2*items[ptrtop].first;
        left-=items[ptrtop].first;
        sum+=1*items[ptrtop].second;
        ptrtop++;
    }else{
        if(items[ptrtop].first>bought){
            ll diff=bought-items[ptrtop].first;
        }else{
            sum+=1*items[ptrtop].second;
        }
    }
}












}


//................................
