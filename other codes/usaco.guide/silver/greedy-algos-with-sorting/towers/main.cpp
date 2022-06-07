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

int n;cin>>n;
multiset<int>vs;
int firstcube;cin>>firstcube;
vs.insert(firstcube);
//for(int i:vs)cout<<i<<" ";cout<<endl;
for(int i=1;i<n;i++){
    int cube;cin>>cube;
    if(cube>=*(--vs.end())){
        vs.insert(cube);//for(int i:vs)cout<<i<<" ";cout<<endl;
        continue;
    }
    auto it=vs.upper_bound(cube);
    if(it==vs.begin()){
        vs.erase(it);
        vs.insert(cube);
    }else{
        vs.erase(it);
        vs.insert(cube);
    }
//    for(int i:vs)cout<<i<<" ";cout<<endl;
}
cout<<vs.size()<<endl;














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
