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
int n;cin>>n;
vector<pair<int,ll>>p;
for(ll i,j=0;j<n;j++){
    cin>>i;
    int three=0;
    ll copy=i;
    while(copy>0){
        if(copy%3==0){
            three++;copy/=3;
        }
        else break;
    }
    p.pb(make_pair(-three,i));
}

sort(p.begin(),p.end());
for(auto i:p){
    cout<<i.second<<" ";
}
cout<<endl;






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
