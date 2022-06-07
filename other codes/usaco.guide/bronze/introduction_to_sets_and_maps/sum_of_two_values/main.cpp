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
map<int,int>m;
int n;cin>>n;int x;cin>>x;
vector<int>v(n),c;for(int &i:v)cin>>i;
c=v;sort(c.begin(),c.end());
for(int i=0;i<n;i++){
    m[v[i]]=i+1;
}
for(int i=0;i<n;i++){
    int a=v[i];
    int b=x-v[i];
    auto it=lower_bound(c.begin(),c.end(),b);
    if(a!=b){
        if(*it==b){
        cout<<i+1<<" "<<m[b]<<endl;return;
        }
    }else{
        if(*it==*(++it)){
            cout<<i+1<<" "<<m[b]<<endl;return;
        }
    }
}
cout<<"IMPOSSIBLE"<<endl;

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
