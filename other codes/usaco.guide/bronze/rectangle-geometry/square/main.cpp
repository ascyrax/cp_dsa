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
    int a=10,b=10,c=0,d=0;
int xa,ya,xb,yb;
for(int i=0;i<2;i++){
    cin>>xa>>ya>>xb>>yb;
    a=min(a,xa);
    b=min(b,ya);
    c=max(c,xb);
    d=max(d,yb);
}
//cout<<a<<b<<c<<d<<endl;
int hor=c-a;
int ver=d-b;
int side=max(hor,ver);
cout<<side*side<<endl;





}//
























int main()
{
    startTime=(double)clock();
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
