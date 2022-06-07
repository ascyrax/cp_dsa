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

ll x1,x2,x3,x4,x5,x6,y1,y2,y3,y4,y5,y6;cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5>>x6>>y6;
//if((x3<=x1&&y3<=y1&&x4>=x2&&y4>=y2)||(x5<=x1&&y5<=y1&&x6>=x2&&y6>=y2)){
//    cout<<"NO"<<endl;
//}else if(){//one diagonal cover
//    cout<<"YES"<<endl;
//}else if(){//two diagonal but still yes
//    cout<<"YES"<<endl;
//}else{
//    cout<<"NO"<<endl;
//}
ll awhite=(x2-x1)*(y2-y1);
ll ablack1=(x4-x3)*(y4-y3);
ll ablack2=(x6-x5)*(y6-y5);
ll wb1=0,wb2=0,inter=0;
wb1=ll(abs(min(x2,x4)-max(x1,x3)))*ll(abs(max(y1,y3)-min(y2,y4)));
wb2=ll(abs(min(x2,x6)-max(x1,x5)))*ll(abs(min(y2,y6)-max(y1,y5)));
if(x3>=x2||y3>=y2)wb1=0;
if(x5>=x2||y5>=y2)wb2=0;
int xa=max(x1,x3);int xb=min(x2,x4);int ya=max(y1,y3);int yb=min(y2,y4);
int xc=max(x1,x5);int xd=min(x2,x6);int yc=max(y1,y5);int yd=min(y2,y6);
inter=ll(abs(min(xd,xb)-max(xa,xc)))*ll(abs(min(yd,yb)-max(ya,yc)));
if(xc>=xb||yc>=yb)inter=0;
ll total=wb1+wb2-inter;
//cout<<awhite<<" "<<ablack1<<" "<<ablack2<<" "<<wb1<<" "<<wb2<<" "<<inter<<" "<<total<<endl;
if(total==awhite){
    cout<<"NO"<<endl;
}else{
    cout<<"YES"<<endl;
}
//cout<<total<<" "<<awhite<<endl;
//if(total==awhite)cout<<"yippeee"<<endl;


















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
