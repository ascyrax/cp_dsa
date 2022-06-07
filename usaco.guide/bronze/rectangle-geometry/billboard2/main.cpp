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
int xa,ya,xc,yc;cin>>xa>>ya>>xc>>yc;
int xb,yb,xd,yd;cin>>xb>>yb>>xd>>yd;
int area1=(yc-ya)*(xc-xa);
int area2=0;//area of intersection
int a=max(xa,xb);
int b=min(xc,xd);
int len=b-a;
int c=min(yc,yd);
int d=max(ya,yb);
int br=c-d;
area2=len*br;

//cout<<area1<<" "<<area2<<endl;

if(((xb>xa&&xb<xc)&&(yb>ya&&yb<yc))||((xd>xa&&xd<xc)&&(yd>ya&&yd<yc))||
        ((xb>xa&&xb<xc)&&(yd>ya&&yd<yc))||((xd>xa&&xd<xc)&&(yb>ya&&yb<yc))){
    cout<<area1<<endl;//1 corners covered
}else if(xb>=xc||xd<=xa||yb>=yc||yd<=ya){//0 corners covered
    cout<<area1<<endl;
}else if(xb<=xa&&yb<=ya&&xd>=xc&&yd>=yc){//all 4 corners covered
    cout<<0<<endl;
}else{//2 corners covered
cout<<area1-area2<<endl;
}




}//
























int main()
{
    startTime=(double)clock();
    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
