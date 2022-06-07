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


vector<int>v(3);
for(int &i:v)cin>>i;

sort(v.begin(),v.end());

int left=v[1]-v[0];
int right=v[2]-v[1];
if(left==2||right==2)
    cout<<1<<endl;
else if(left+right==2){
    cout<<0<<endl;
}else
        cout<<2<<endl;

//cout<<"hi"<<endl;
left=v[1]-v[0];
right=v[2]-v[1];
int bigger=max(left,right);
int ans=1;
while(bigger>2){
//    cout<<bigger<<endl;
    ans++;
    bigger=(bigger+1)/2;
}

cout<<ans<<endl;









}//




































int main()
{
    startTime=(double)clock();
    freopen("herding.in","r",stdin);
    freopen("herding.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
