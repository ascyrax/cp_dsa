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
int n,k;cin>>n>>k;
vector<int>v(n);for(int &i:v)cin>>i;
sort(v.begin(),v.end());
if(k==0){
    if(v[0]>1)cout<<1<<endl;
    else cout<<-1<<endl;
    return;
}
if(k<n&&(v[k-1]==v[k]))cout<<-1<<endl;
else
cout<<v[k-1]<<endl;





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
