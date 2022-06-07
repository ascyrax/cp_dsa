#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef  long long ll;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define all(x) begin(x), end(x)
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

int n,a,b,c;cin>>n>>a>>b>>c;
if(n==1){
    if(a==1&&b==1&&c==1)cout<<1<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
    return;
}else if(n==2){
    if(c==2){
        if(a==2&&b==2)cout<<2<<" "<<2<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }else if(c==1){
        if(a==1&&b==2)cout<<2<<" "<<1<<endl;
        else if(a==2&&b==1)cout<<1<<" "<<2<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }
    return;
}
deque<int>v(c);
//a=a-c;b=b-c;
for(int i=0;i<c;i++){
    v[i]=3;
}
//cout<<"HI ";for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;
int rem=n-c-(a-c)-(b-c);//cout<<"rem"<<" "<<rem<<endl;
if(rem>0){v.erase(v.begin());
    for(int i=0;i<rem;i++){
        v.push_front(1);
    }v.push_front(3);
    /*if(a-c>0){
        for(int i=0;i<rem;i++){
            v.push_front(1);
        }
    }else if(b-c>0){
        for(int i=0;i<rem;i++){
            v.push_back(1);
        }
    }else{
        cout<<"IMPOSSIBLE"<<endl;return;
    }*/
}else if(rem<0){
    cout<<"IMPOSSIBLE"<<endl;return;
}
//cout<<"HI ";for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;
for(int i=0;i<a-c;i++){
    v.push_front(2);
}
for(int i=0;i<b-c;i++){
    v.pb(2);
}
//cout<<"HI ";for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;

int ca=0,cb=0;int ma=v[0],mb=v[v.size()-1];
for(int i=0;i<v.size();i++){
    if(v[i]>=ma)ca++;
    ma=max(ma,v[i]);
}
for(int i=v.size()-1;i>=0;i--){
    if(v[i]>=mb)cb++;
    mb=max(mb,v[i]);
}
if(ca==a&&cb==b){
    for(int i:v)cout<<i<<" ";cout<<endl;
}else cout<<"IMPOSSIBLE"<<endl;
}//
























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;for(int i=1;i<=t;i++){cout<<"Case #"<<i<<": ";
    suraj();
    }
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
