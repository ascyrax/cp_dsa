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



























int ans=0;

void suraj(){
int a,b;cin>>a>>b;
deque<int>v(a);for(int &i:v)cin>>i;
while(!v.empty()){
    if(v[0]<=b){
        ans++;
        v.pop_front();
    }
    else if(v[v.size()-1]<=b){
        ans++;v.pop_back();
    }
    else{
        break;
    }
}
cout<<ans<<endl;





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
