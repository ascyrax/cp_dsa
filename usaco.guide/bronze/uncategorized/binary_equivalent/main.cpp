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























int count1(int a,int n){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a&1==1){
            cnt++;
        }
        a=a>>1;
    }
    return cnt;
}
int count0(int a,int n){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(!(a&1)){
            cnt++;
        }
        a=a>>1;
    }
    return cnt;
}




void suraj(){

int ans=0;

int n;cin>>n;
vector<int>v(n);for(int &i:v)cin>>i;
int mx=0;
for(int i:v)mx=max(i,mx);
int mx_bin=0;
while(mx>0){
    mx_bin++;
    mx=mx>>1;
}
//cout<<"mx_bin"<<mx_bin<<endl;
vector<pair<int,int>>bin(n);
for(int i=0;i<n;i++){
    bin[i].first=count1(v[i],mx_bin);
    bin[i].second=count0(v[i],mx_bin);
}
//for(auto i:bin)cout<<i.first<<" "<<i.second<<endl;
int curr=0;
for(int i=1;i<(1<<n);i++){//i=0 not taken becz we r not considering empty subsets
    vector<int>temp;
    for(int j=0;j<mx_bin;j++){
        if(i&(1<<j)){
            temp.pb(j);
        }
    }
    int sum0=0;
    int sum1=0;
    for(int j:temp){
        sum1+=bin[j].first;
        sum0+=bin[j].second;
    }
  //  cout<<sum1<<" "<<sum0<<endl;
    if(sum1==sum0)ans++;

}
vector<int>bin_ans;
for(int i=mx_bin-1;i>=0;i--){
    if(ans&(1<<i)){
        bin_ans.pb(1);
    }else bin_ans.pb(0);
}
for(int i:bin_ans)cout<<i;cout<<endl;


}//
























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
