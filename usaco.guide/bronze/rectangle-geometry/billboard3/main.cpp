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
int blx,bly,brx,bry;cin>>blx>>bly>>brx>>bry;
int flx,fly,frx,fry;cin>>flx>>fly>>frx>>fry;
//all ans=0
int ans=0;
bool flag=true;
if(flx<=blx&&fly<=bly&&frx<brx&&fry>=bry&&frx>blx){
    ans=(brx-frx)*(bry-bly);
}else if(frx>=brx&&fry>=bry&&flx<brx&&flx>blx&&fly<=bly){
    ans=(bry-bly)*(flx-blx);
}else if(flx<=blx&&fly<=bly&&frx>=brx&&fry<bry&&fry>bly){
    ans=(brx-blx)*(bry-fry);
}else if(flx<=blx&&fry>=bry&&frx>=brx&&fly<bry&&fly>bly){
    ans=(brx-blx)*(fly-bly);
}else flag=false;

if(flx<=blx&&fly<=bly&&frx>=brx&&fry>=bry){//all 4 covered
    cout<<0<<endl;
}else if(flag==true){//any two covered
    cout<<ans<<endl;
}else{//0 and 1 corner covered case
    cout<<(brx-blx)*(bry-bly)<<endl;
}
//none ans=area billboard full

//some 1 corner area billboard full

//some 2 adjacent corner area remaining

//some 0 corner covered  area billboard full


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
