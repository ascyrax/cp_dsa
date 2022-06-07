/*
ID: ascyrax1
TASK: test
LANG: C++14
*/
/* LANG can be C++11 or C++14 for those more recent releases */
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
void suraj();
int main()
{
    startTime=(double)clock();
    //freopen("balancing.in","r",stdin);freopen("balancing.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}












// har x ke x-1 aur x+1 pe ..similar for y too.












void suraj(){


int n,b;cin>>n>>b;
vector<int>x(n),y(n);vector<pair<int,int>>xy(n);

for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;
    x[i]=a;y[i]=b;xy[i]=make_pair(a,b);

}
sort(x.begin(),x.end());sort(y.begin(),y.end());
sort(xy.begin(),xy.end());
for(int i=0;i<n-1;i++){
    int left=i+1;
    int right=n-left;
    int ver=x[i]+1;
    for(int j=0;j<n-1;j++){
        int hor=y[j]+1;
        int bottom=j+1;
        int top=n-bottom;
        int tr=
    }
}








}//
