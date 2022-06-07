#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef  long long ll;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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


























void comp(tuple<int,int,int>a,tuple<int,int,int>b){
    if()
}


void suraj(){
int n;cin>>n;
vector<tuple<int,int,int>>va;
for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;
    va.pb(make_tuple(a-b,a,b));
}
sort(va.begin(),va.end(),comp);
int rmax=get<1>(va[0])+get<2>(va[0]);
int cannot=0;
for(int i=1;i<n;i++){

    int ta=get<1>(va[i])+get<2>(va[i]);
    int tb=get<0>(va[i]);
    if(tb==get<0>(va[i-1])){
        if(get<1>(va[i-1])+get<2>(va[i-1])==rmax)
            cannot++;
        else
            if(ta<=rmax)cannot++;
    }else{
    if(ta>rmax){
        rmax=ta;
    }else if(ta==rmax){
        cannot++;
    }
    else{
        cannot++;
    }
    }
}
cout<<n-cannot<<endl;




}//
























int main()
{
    startTime=(double)clock();
    freopen("mountains.in","r",stdin);
    freopen("mountains.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++){cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
