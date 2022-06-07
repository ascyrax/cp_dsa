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
int ans=0;
int n;cin>>n;
vector<int>milk(3,7);
//b e m
vector<pair<int,pair<string,string>>>v;
for(int i=0;i<n;i++){
    int day;cin>>day;
    string cow,diff;cin>>cow>>diff;
    v.pb(make_pair(day,make_pair(cow,diff)));
}
sort(v.begin(),v.end());
for(int i=0;i<n;i++){
    auto t=v[i];
    string a=t.second.first;
    string b=t.second.second;
    if(a[0]=='B'){
        if(b.substr(0,1)=="-"){
            milk[0]-=stoi(b.substr(1));
        }
        else{
            milk[0]+=stoi(b.substr(1));
        }
    }else if(a[0]=='E'){
        if(b.substr(0,1)=="-"){
            milk[1]-=stoi(b.substr(1));
        }
        else{
            milk[1]+=stoi(b.substr(1));
        }

    }else if(a[0]=='M'){
        if(b.substr(0,1)=="-"){
            milk[2]-=stoi(b.substr(1));
        }
        else{
            milk[2]+=stoi(b.substr(1));
        }

    }
}


}//
























int main()
{
    startTime=(double)clock();
    //freopen("measurement.in","r",stdin);
    //freopen("measurement.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
