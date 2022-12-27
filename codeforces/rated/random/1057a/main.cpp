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
vector<int>ans;
vector<int>input;
int n;cin>>n;
input.pb(1);input.pb(1);
for(int i=0;i<n-1;i++){
    int a;cin>>a;input.pb(a);
}
int ptr=n;
vector<int>v[n];// 0 se n-1 tak
for(int i=n;i>=0;i--){
    int a=input[i];
  //  cout<<a<<endl;
    if(i==ptr){
        ans.pb(i);
        ptr=a;
    }
}
sort(ans.begin(),ans.end());
for(int i:ans)cout<<i<<" ";cout<<endl;




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
