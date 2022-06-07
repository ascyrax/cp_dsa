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


int n,q;cin>>n>>q;
vector<string>forest;
for(int i=0;i<n;i++){
    string temp;cin>>temp;
    forest.pb(temp);
}
//for(int i=0;i<n;i++){
//    for(int j=0;j<n;j++)
//        cout<<forest[i][j]<<" ";
//    cout<<endl;
//}
vector<int>trees[n];
for(int i=0;i<n;i++){
    vector<int>temp(n);
    trees[i]=temp;
}
//for(int i=0;i<n;i++){
//    for(int j=0;j<n;j++){
//        cout<<trees[i][j]<<" ";
//    }cout<<endl;
//}
if(forest[0][0]=='*')
    trees[0][0]=1;
for(int row=0;row<n;row++){
    for(int col=0;col<n;col++){
        if(row==0&&col==0)continue;
        else if(row==0){
            trees[row][col]=trees[row][col-1];
        }else if(col==0){
            trees[row][col]=trees[row-1][col];
        }else
            trees[row][col]=trees[row-1][col]+trees[row][col-1]-trees[row-1][col-1];
        if(forest[row][col]=='*')
            trees[row][col]++;
    }
}
//for(int i=0;i<n;i++){
//    for(int j=0;j<n;j++){
//        cout<<trees[i][j]<<" ";
//    }cout<<endl;
//}
for(int i=0;i<q;i++){
    int ra,ca,rb,cb;cin>>ra>>ca>>rb>>cb;ra--;ca--;rb--;cb--;
    int ans=trees[rb][cb];//-trees[ra-1][cb]-trees[rb][ca-1]+trees[ra-1][ca-1];
    if(ra-1>=0){
        ans-=trees[ra-1][cb];
    }
    if(ca-1>=0){
        ans-=trees[rb][ca-1];
    }
    if((ra-1>=0)&&(ca-1>=0)){
        ans+=trees[ra-1][ca-1];
    }
    cout<<ans<<endl;
}























}//




































int main()
{
    startTime=(double)clock();
//    freopen("shell.in","r",stdin);
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
