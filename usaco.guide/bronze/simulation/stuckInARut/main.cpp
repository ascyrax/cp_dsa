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
map<pair<int,int>,int>mpi;
tuple<int,int,int,int,int,int>ti[n];
for(int i=0;i<n;i++){
    string is;int x,y,ix,iy;
    cin>>is>>ix>>iy;
    if(is=="N"){
        y=1;
        x=0;
    }else if(is=="E"){
        x=1;
        y=0;
    }
    ti[i]=(make_tuple(x,y,ix,iy,0,0));
}
//for(auto i:ti){
//    cout<<get<0>(i)<<" ";
//    cout<<get<1>(i)<<" ";
//    cout<<get<2>(i)<<" ";
//    cout<<get<3>(i)<<" ";
//    cout<<get<4>(i)<<" ";
//    cout<<get<5>(i)<<endl;
//}
int loop=1e4,sum=0;

for(int i=0;i<n;i++){
    int a=get<0>(ti[i]);
    int b=get<1>(ti[i]);
    int c=get<2>(ti[i]);
    int d=get<3>(ti[i]);
    int e=get<4>(ti[i]);
    int f=get<5>(ti[i]);
    mpi.insert(make_pair(make_pair(c,d),1));
    get<2>(ti[i])=c+a;get<3>(ti[i])=d+b;get<5>(ti[i])=f+1;

}

//for(auto i:ti){
//    cout<<get<0>(i)<<" ";
//    cout<<get<1>(i)<<" ";
//    cout<<get<2>(i)<<" ";
//    cout<<get<3>(i)<<" ";
//    cout<<get<4>(i)<<" ";
//    cout<<get<5>(i)<<endl;
//}

while(loop--){
    vector<pair<pair<int,int>,int>>temp;
    for(int i=0;i<n;i++){
        int a=get<0>(ti[i]);
        int b=get<1>(ti[i]);
        int c=get<2>(ti[i]);
        int d=get<3>(ti[i]);
        int e=get<4>(ti[i]);
        int f=get<5>(ti[i]);
        if(e==1)continue;// cow has already stopped
//        get<5>(ti[i])=f+1;


//        sum+=mpi.count(make_pair(a+c,b+d));

        if(mpi.count(make_pair(c,d))==1){
//            cout<<"count"<<endl;sum++;
            get<4>(ti[i])=1;continue;
        }else{
//            cout<<"yo"<<c<<" "<<d<<endl;
            temp.pb((make_pair(make_pair(c,d),1)));
             get<2>(ti[i])=c+a;get<3>(ti[i])=d+b;get<5>(ti[i])=f+1;
        }
    }
    for(auto i:temp)mpi.insert(i);
}
//for(auto it=mpi.begin();it!=mpi.end();it++){
//    cout<<it->first.first<<" "<<it->first.second<<endl;
//}

//for(auto i:ti){
//    cout<<get<0>(i)<<" ";
//    cout<<get<1>(i)<<" ";
//    cout<<get<2>(i)<<" ";
//    cout<<get<3>(i)<<" ";
//    cout<<get<4>(i)<<" ";
//    cout<<get<5>(i)<<endl;
//}

for(int i=0;i<n;i++){
    int ans=get<5>(ti[i]);
    if(ans>=1e4)cout<<"Infinity"<<endl;
    else cout<<ans<<endl;
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
