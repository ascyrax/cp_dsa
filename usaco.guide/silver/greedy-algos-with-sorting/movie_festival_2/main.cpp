/*
ID: ascyrax1
TASK: test
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define endl "\n"
#define ioss ios::sync_with_stdio(false);cin.tie(0);
#define pb push_back

double startTime;
double gct()//get_current_time
{
    return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}
void suraj();




































void suraj(){///////////////////////
int n,k;cin>>n>>k;
//vector<int>start(n),end(n);
set<pair<int,int>>movie;
for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;
//    start[i]=a;end[i]=b;
    movie.insert(make_pair(b,a));
}
int ans=0;

for(int i=0;i<k;i++){/*cout<<"--------------------"<<endl;
    for(auto el:movie){
        cout<<el.first<<" "<<el.second<<endl;
    }*/
    int next=0;
//    cout<<movie.size()<<endl;
    if(movie.size()>0){
        auto copy=movie;
        for(auto el:movie){
//            cout<<el.first<<" "<<el.second<<endl;
            if(el.second>=next){
//                cout<<"zerg "<<el.first<<" "<<el.second<<endl;
                ans++;next=el.first;
                copy.erase(copy.find(el));
            }
//            cout<<"protoss "<<(*movie.find(el)).first<<" "<<(*movie.find(el)).second<<endl;
        }
        movie=copy;
    }else break;
}

cout<<ans<<endl;













}////////////////////////////




























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
