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
int n,m;cin>>n>>m;
vector<int>nodes[n+1];
//nodes[2] contain the node's adjacent nodes.
for(int i=0;i<m;i++){
    int na,nb;cin>>na>>nb;
    nodes[na].pb(nb);nodes[nb].pb(na);
}
vector<int>color(n+1);
color[1]=1;
for(int i=2;i<=n;i++){
    set<int>used;//cout<<"I "<<i<<"   ";
        for(int j:nodes[i]){
            if(j>i){
                ;
            }else{
                used.insert(color[j]);
            }
        }
        //for(auto i:used)cout<<i<<" ";cout<<endl;
        for(int col=1;col<=4;col++){
            //cout<<"USED.count "<<used.count(col)<<endl;
            if(used.count(col)==0){
                color[i]=col;break;
            }
        }


}
for(int i=1;i<=n;i++)
    cout<<color[i];cout<<endl;





}//
























int main()
{
    startTime=(double)clock();
    freopen("revegetate.in","r",stdin);
    freopen("revegetate.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
