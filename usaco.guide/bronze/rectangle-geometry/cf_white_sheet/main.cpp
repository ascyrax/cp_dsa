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
int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
int x3,x4,y3,y4;cin>>x3>>y3>>x4>>y4;
int x5,y5,x6,y6;cin>>x5>>y5>>x6>>y6;
int h=y2-y1;
int w=x2-x1;
int ah,bh,aw,bw;
int hx3,hx4,hx5,hx6,hy3,hy4,hy5,hy6;
int wx3,wx4,wx5,wx6,wy3,wy4,wy5,wy6;


if(y6>y4){
    hy6=y6;hy5=y5;hx5=x5;hx6=x6;hx3=x3;hx4=x4;hy3=y3;hy4=y4;
    ah=y2-y5;bh=y4-y1;
}else{
    hx3=x5;hx4=x6;hy3=y5;hy4=y6;hx5=x3;hx6=x4;hy5=y3;hy6=y4;
    ah=y2-y3;bh=y6-y1;
}
if(x6>x4){
    wx3=x3;wx4=x4;wx5=x5;wx6=x6;wy3=y5;wy4=y6;wy5=y3;wy6=y4;
    aw=x2-x5;bw=x4-x1;
}else{
    wx3=x5;wx4=x6;wx5=x3;wx6=x4;wy3=y3;wy4=y6;wy5=y3;wy6=y4;
    aw=x2-x3;bw=x6-x1;
}
if((x3<=x1&&y3<=y1&&x4>=x2&&y4>=y2)||(x5<=x1&&x6>=x2&&y5<=y1&&y6>=y2)){
    cout<<"NO"<<endl;
}else if((hx5<=x1&&hy5<=y1&&hx6>=x2)&&(hx4>=x2&&hy4>=y2&&hx3<=x1)&&(ah+bh>=h)){
    cout<<"NOh"<<endl;
}else if((wx6>=x2&&wy6>=y2&&wy5<=y1&&wx5<=x2)&&(wx3<=x1&&wx4>=x1&&wx4<=x2&&wy3<=y1&&y4>=y2)&&(aw+bw>=w)){
 cout<<"NO"<<endl;
}else{
    cout<<"YES"<<endl;
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
