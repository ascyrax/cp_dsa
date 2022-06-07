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
map<int,int>v;
int ans=0;
for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;
    if(v.count(a)>0){
        if(v[a]!=b){
            ans++;
            v[a]=b;
        }
    }else{
        v[a]=b;
    }
}
cout<<ans<<endl;





}//
























int main()
{
    startTime=(double)clock();
    freopen("crossroad.in","r",stdin);
    freopen("crossroad.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
