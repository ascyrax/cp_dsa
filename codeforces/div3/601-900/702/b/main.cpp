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
int n;cin>>n;
vector<int>v(n);for(int &i:v)cin>>i;

int a=0,b=0,c=0;
for(int i=0;i<n;i++){
    if(v[i]%3==0)a++;
    else if(v[i]%3==1)b++;
    else c++;
}

int ans=0;
int each=n/3;
//cout<<"each "<<each<<endl;
//cout<<a<<" "<<b<<" "<<c<<endl;
a-=each;
b-=each;
c-=each;
//cout<<a<<" "<<b<<" "<<c<<endl;
int cnt=2;
while(cnt--){//!(a==0&&b==0)&&c==0){
//    cout<<"while "<<a<<" "<<b<<" "<<c<<" "<<ans<<endl;
    if(a>0){
        ans+=a;
        b+=a;
        a=0;
    }
    if(b>0){
        ans+=b;
        c+=b;
        b=0;
    }
    if(c>0){
        ans+=c;
        a+=c;
        c=0;
    }

}
cout<<ans<<endl;















}//




































int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
