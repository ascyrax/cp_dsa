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



int a,b,c,d;cin>>a>>b>>c>>d;
int ans=0;
if(b==c)ans=d-a;
else if(b<c)ans=d-c+b-a;
else if(b>=c&&b<=d)ans=d-min(a,c);
else if(b>=d&&a<=d)ans=b-min(a,c);
else ans=b-a+d-c;
cout<<ans<<endl;



















}//




































int main()
{
    startTime=(double)clock();
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
