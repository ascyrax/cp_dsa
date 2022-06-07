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
vector<int>v(n);for(int &i:v)cin>>i;
//for(int i:v)cout<<i<<" ";cout<<endl;
for(int i=0;i<n-1;i++){
    //int b=(n-1)-i;
    //if(b==0)break;
    //int c=log2(b);
    //int d=pow(2,0)+i;
    //v[d]+=v[i];
    //for(int i:v)cout<<i<<" ";cout<<endl;
    cout<<v[i]<<endl;
    v[i+1]+=v[i];
}





}//
























int main()
{
    startTime=(double)clock();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt,"w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
