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
deque<int>v(n);
deque<int>a(n);
for(int i=1;i<=n;i++){
    a[i-1]=i;
}
int flag=0;
int ans=0;
for(int &i:v)cin>>i;
while(true){
    //if(v==a)break;
    if(flag==1&&v[0]==1){
        if(v==a)break;
    }
    if(v[0]==1){
        flag=1;
    }
    int a=v[0];
    int b=v[n-1];
    if(a>b){
        v.pb(a);ans++;v.pop_front();
    }else{
        ans++;v.pop_front();
        for(int j=n-2;j>=0;j--){
            if(v[j]<v[j+1]&&v[j]>a){
                ;;
            }else{
                v.insert(v.begin()+j+1,a);break;
            }
        }
    }
}


cout<<ans<<endl;



}//
























int main()
{
    startTime=(double)clock();
    freopen("sleepy.in","r",stdin);
    freopen("sleepy.out","w",stdout);
    ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
