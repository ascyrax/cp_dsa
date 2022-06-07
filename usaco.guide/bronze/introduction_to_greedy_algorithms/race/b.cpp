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
int k,n;cin>>k>>n;vector<int>vx(n);for(int &i:vx)cin>>i;
//for(int i:vx)cout<<i<<endl;
int sum=0;
for(int i=0;i<n;i++){cout<<"hi"<<endl;
    int x=vx[i];
    int sum1=(x*(x+1))/2;
    if(sum1>k){
        int a=sqrt(2*k);
        for(int j=a;j>=0;j--){
            int sum2=(j*(j+1))/2;
            if(sum2<k){
                cout<<j+1<<endl;break;
            }else if(sum2==k){
                cout<<j<<endl;break;
            }
        }
    }else if(sum1==k){
        cout<<x<<endl;continue;
    }else{
        int diff1=k-sum1;
        diff1/=2;diff1+=sum1;
        int a=sqrt(2*diff1);
        for(int j=a;j>=0;j--){
            int sum2=(a*(a+1))/2+(a*(a+1))/2-((x-1)*(x-1+1))/2;
            if(sum2>k){
                continue;
            }else if(sum2==k){
                cout<<a+a-(x)<<endl;break;
            }else{
                cout<<a+a-x+1<<endl;break;
            }
        }

    }
}
























}//




































int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
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
