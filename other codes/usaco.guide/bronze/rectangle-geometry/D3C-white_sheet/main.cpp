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


int xa,ya,xb,yb;cin>>xa>>ya>>xb>>yb;
int xc,yc,xd,yd;cin>>xc>>yc>>xd>>yd;
int xe,ye,xf,yf;cin>>xe>>ye>>xf>>yf;
if(xc>xe){
    int txc=xc,tyc=yc,txd=xd,tyd=yd;
    xc=xe;yc=ye;xd=xf;yd=yf;
    xe=txc;ye=tyc;xf=txd;yf=tyd;
}
if((xc<=xa&&yc<=ya&&xd>=xb&&yd>=yb)||(xe<=xa&&ye<=ya&&xf>=xb&&yf>=yb)){
    cout<<"NO"<<endl;
}else if(xc<=xa&&yc<=ya&&yd>=yb&&xe<=xd&&xf>=xb&&ye<=ya&&yf>=yb){
    cout<<"NO"<<endl;
}else if((xc<=xa&&yc>ya&&yd>=yb&&xd>=xb&&xe<=xa&&ye<=ya&&xf>=xb&&yf>=yc)||
         (xe<=xa&&ye>ya&&yf>=yb&&xf>=xb&&xc<=xa&&yc<=ya&&xd>=xb&&yd>=ye)){
    cout<<"NO"<<endl;
}else cout<<"YES"<<endl;























}//




































int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
