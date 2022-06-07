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
vector<string>a(n),b(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n;i++){
    cin>>b[i];
}
int ans=0;
set<char>sa,sb;
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        sa.insert(a[j][i]);
        sb.insert(b[j][i]);
    }
    int flag=0;
    //for(auto i=sa.begin();i!=sa.end();i++)cout<<*i<<" ";cout<<endl;
    //for(auto i=sb.begin();i!=sb.end();i++)cout<<*i<<" ";cout<<endl;
    for(auto i=sa.begin();i!=sa.end();i++){
        for(auto j=sb.begin();j!=sb.end();j++){
            if(*i==*j){
                flag=1;break;
            }
        }if(flag==1)break;
    }
    if(flag==0)ans++;
    sa.clear();sb.clear();
}

cout<<ans<<endl;

}//
























int main()
{
    startTime=(double)clock();
    freopen("cownomics.in","r",stdin);
    freopen("cownomics.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
