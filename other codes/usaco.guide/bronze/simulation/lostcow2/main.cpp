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
int a,b;cin>>a>>b;
int x=1;
int cur=a;
int next=a+x;
int ans=0;
if(b>0){
while(next<b){
    ans=ans+abs(next-cur);
    cur=next;
    x*=-2;
    next=a+x;
}
ans=ans+b-cur;
}else{
    while(next>b){
        ans+=abs(next-cur);
        cur=next;
        x*=-2;
        next=a+x;
    }
    ans+=abs(b-cur);

}
cout<<ans<<endl;



}//
























int main()
{
    startTime=(double)clock();
    freopen("lostcow.in","r",stdin);
    freopen("lostcow.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
