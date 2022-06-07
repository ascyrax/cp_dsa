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
vector<vector<int>>v;
for(int i=0;i<n;i++){
    string a;cin>>a;
    vector<int>b;
    for(int j=0;j<n;j++){
        b.pb(a[j]-'0');
    }
    v.pb(b);
}
int ans=0;
//cout<<"hey"<<endl;
for(int i=n-1;i>=0;i--){
    for(int j=n-1;j>=0;j--){
        if(v[i][j]==1){
            ans++;
            for(int k=0;k<=i;k++){
                for(int l=0;l<=j;l++){
                    if(v[k][l]==1)v[k][l]=0;
                    else v[k][l]=1;
                }
            }
        }
    }
  //  cout<<"hi"<<endl;
}

cout<<ans<<endl;


}//
























int main()
{
    startTime=(double)clock();
    freopen("cowtip.in","r",stdin);
    freopen("cowtip.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
