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


int n;cin>>n;
vector<pair<int,int>>vp;
for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;
    vp.pb(make_pair(a,b));
}
int ans=0;
int diffy=0;int diffx=0;
for(int i=0;i<n;i++){
    int x=vp[i].first;
    int y=vp[i].second;
    int j=0;int tj=0;
    for(j=0;j<n;j++){
           if(vp[j].first==x){
               if(diffy<abs(vp[j].second-vp[i].second)){
                   tj=j;diffy=abs(vp[j].second-vp[i].second);
               }
           }
    }
    for(j=0;j<n;j++){
            if(vp[j].second==vp[i].second){
                if(diffx<abs(vp[j].first-vp[i].first)){
                    diffx=abs(vp[j].first-vp[i].first);
                }
            }
        }
    ans=max(ans,diffx*diffy);
    diffx=0;diffy=0;
}
//cout<<diffx<<" "<<diffy<<endl;
cout<<ans<<endl;




}//
























int main()
{
    startTime=(double)clock();
    freopen("triangles.in","r",stdin);
    freopen("triangles.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
