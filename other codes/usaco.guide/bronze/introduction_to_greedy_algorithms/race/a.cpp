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

int k,n;cin>>k>>n;
vector<int>v(n);
for(int &i:v)cin>>i;
//check 1
for(int i:v){
    int ans=0;
    int sum=0;
    for(int j=0;j<=i;j++){
        sum+=j;
        if(sum>=k){
            cout<<j<<endl;return;
        }
    }
    //check 2
    sum=0;
    for(int )

    cout<<ans<<endl;
}





}//
























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
