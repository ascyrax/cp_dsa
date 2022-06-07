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
























int count(vector<int>v){
    sort(v.rbegin(),v.rend());
    int cnt=1;
    if(v[0]==v[1]&&v[1]==v[2])cnt=3;
    else if(v[0]==v[1])cnt=2;
    else cnt=1;
    return cnt;
}




void suraj(){
int n;cin>>n;
set<pair<int,pair<int,int>>>p;
for(int i=0;i<n;i++){
    int d;cin>>d;
    string cow;cin>>cow;
    int temp=0;
    if(cow=="Bessie")temp=0;
    else if(cow=="Elsie")temp=1;
    else if(cow=="Mildred")temp=2;
    //else temp=74;
    string del;cin>>del;
    p.insert(make_pair(d,make_pair(temp,stoi(del))));
}
vector<int>v;v.pb(7);v.pb(7);v.pb(7);
//for(int i:v)cout<<i;cout<<endl;
int ans=0;
int prev_winners=3;
int prev_highest=7;
for(auto it=p.begin();it!=p.end();it++){
    //cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<endl;
    int del=it->second.second;
    v[it->second.first]+=del;
    int new_highest=max(max(v[0],v[1]),v[2]);
    int new_winners=count(v);
    if(new_highest!=prev_highest){
        prev_highest=new_highest;ans++;
        prev_winners=1;
    }
    else if(new_winners!=prev_winners){
        ans++;prev_winners=new_winners;
    }
   //for(int i:v)cout<<i<<" ";cout<<endl;
   //cout<<"hey"<<new_winners<<" "<<ans<<endl;
}
cout<<ans<<endl;

}//
























int main()
{
    startTime=(double)clock();
    freopen("measurement.in","r",stdin);
    freopen("measurement.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
