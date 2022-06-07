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


int n,m;cin>>n>>m;
vector<int>cities(n);for(int &i:cities)cin>>i;
vector<int>towers(m);for(int &i:towers)cin>>i;
int tl=0;int cl=0;
int ans=0,diff=0;
while(cl<n){
   // cout<<"a"<<endl;
    int a=cities[cl++];
    while(true){
       // cout<<"hi"<<endl;
    if(tl<=m-2){
    int diffa=abs(a-towers[tl]);
    int diffb=abs(a-towers[tl+1]);
    if(diffb<=diffa){
        tl++;
    }else{
        ans=max(ans,diffa);break;
    }
    }else{
        ans=max(ans,abs(a-towers[m-1]));break;
    }
    }
}

cout<<ans<<endl;


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
