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


int n,k;cin>>n>>k;
vector<int>vl(n+1),vr(n+1),v(n);
for(int i=0;i<k;i++){
    int a,b;cin>>a>>b;
    vl[a-1]+=1;vr[b]+=-1;
}
//vector<int>va(n);
//for(int i=0;i<k;i++){
//    va[vl[i]-1]+=1;
//}
//int left=0;
////for(int i:va)cout<<i<<" ";cout<<endl;
//for(int i=0;i<n;i++){
//    va[i]+=left;
//    if(va[i]>0){
//        left=va[i];
//    }
//}
//int right=0;
//vector<int>vb(n);
//for(int i=0;i<k;i++){
//    vb[vr[i]-1]+=-1;
//}
//for(int i=0;i<n;i++){
//    vb[i]+=right;
//    if(vb[i]<0){
//        right=vb[i];
//    }
//}
////for(int i:va)cout<<i<<" ";cout<<endl;

//for(int i=0;i<n;i++){
//    va[i]+=vb[i];
//}
////for(int i:vb)cout<<i<<" ";cout<<endl;
////for(int i:va)cout<<i<<" ";cout<<endl;
//sort(va.begin(),va.end());
//cout<<va[n/2]<<endl;
//for(int i:vl)cout<<i<<" ";cout<<endl;
//for(int i:vr)cout<<i<<" ";cout<<endl;

for(int i=1;i<n;i++){
    vl[i]+=vl[i-1];
    vr[i]+=vr[i-1];
}
//for(int i:vl)cout<<i<<" ";cout<<endl;
//for(int i:vr)cout<<i<<" ";cout<<endl;
for(int i=0;i<n;i++){
    v[i]=vl[i]+vr[i];
}
//for(int i:v)cout<<i<<" ";cout<<endl;

sort(v.begin(),v.end());
//for(int i:v)cout<<i<<" ";cout<<endl;
cout<<v[n/2]<<endl;










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
