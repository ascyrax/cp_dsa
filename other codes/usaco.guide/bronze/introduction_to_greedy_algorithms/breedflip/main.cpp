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
string a,b;cin>>a>>b;
int ptr=0;int ans=0;
for(int i=0;i<n;i++){
    if(b[i]=='H'&&a[i]=='G'){
        ptr++;
    }else if(b[i]=='G'&&a[i]=='H'){
        ptr++;
    }else{
        if(ptr>0){
        ans++;ptr=0;
        }
    }
}
if(ptr>0)ans++;
cout<<ans<<endl;






}//
























int main()
{
    startTime=(double)clock();
    freopen("breedflip.in","r",stdin);
    freopen("breedflip.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
