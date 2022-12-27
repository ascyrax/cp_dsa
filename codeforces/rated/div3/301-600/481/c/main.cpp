#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef  long long ll;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

int n,m;cin>>n>>m;
vector<ll>a(n);for(ll &i:a)cin>>i;
vector<ll>b(m);for(ll &i:b)cin>>i;
for(int i=1;i<n;i++){
    a[i]+=a[i-1];
}
//for(ll i:a)cout<<i<<" ";cout<<endl;
for(int i=0;i<m;i++){
    ll c=b[i];
    auto lb=lower_bound(a.begin(),a.end(),c);
    if(*lb==c){
        if(lb!=a.begin())
        cout<<lb-a.begin()+1<<" "<<*lb-(*(lb-1))<<endl;
        else
            cout<<lb-a.begin()+1<<" "<<(*lb)-0<<endl;
    }
    else{
        if(lb!=a.begin())
        cout<<(lb)-a.begin()+1<<" "<<c-(*(lb-1))<<endl;
        else
            cout<<lb-a.begin()+1<<" "<<c-0<<endl;
    }
}




}//
























int main()
{
    startTime=(double)clock();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt,"w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
