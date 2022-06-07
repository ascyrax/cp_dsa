/*
ID: ascyrax1
TASK: test
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define endl "\n"
#define ioss ios::sync_with_stdio(false);cin.tie(0);
#define pb push_back

double startTime;
double gct()//get_current_time
{
    return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}
void suraj();




































void suraj(){///////////////////////
cout<<"..............................................."<<endl;
    int n;cin>>n;
string s;cin>>s;
vector<int>v;
vector<int>ps(n+1);//ps => prefix sum
for(auto el:s){
    v.pb(el-'0');
}
//for(int i:v)cout<<i<<" ";cout<<endl;
for(int i=0;i<n;i++){
    ps[i+1]=ps[i]+v[i];
}
//ps[i] => sum of first i elements of vector v

//ps[r]-ps[l-1]=r-l+1........ps[r]-ps[l]=r-l;....ps[r]-r=ps[l]-l
for(int i:ps)cout<<i<<" ";cout<<endl;
for(int i=1;i<=n;i++){
    ps[i]-=i;
}
for(int i:ps)cout<<i<<" ";cout<<endl;
ps[0]=-1111111;
sort(ps.begin(),ps.end());
for(int i:ps)cout<<i<<" ";cout<<endl;
ll ans=0;
int count=1;
for(int i=1;i<n;i++){
    if(ps[i+1]==ps[i]){
        count++;
    }else{cout<<i<<" "<<ps[i]<<" "<<ps[i+1]<<count<<endl;
        ans+=(count*(count-1))/2;
        count=1;
    }
}
//if last two value are same
ans+=(count*(count-1))/2;
count=1;
cout<<ans<<endl;









}////////////////////////////




























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
