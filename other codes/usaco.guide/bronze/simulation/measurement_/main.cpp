/*
ID: ascyrax1
TASK: test
LANG: C++14
*/
/* LANG can be C++11 or C++14 for those more recent releases */
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
void suraj();
int main()
{
    startTime=(double)clock();
    freopen("measurement.in","r",stdin);freopen("measurement.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}

























void suraj(){



int n;cin>>n;
vector<pair<int,int>>vday;
vector<string>vcow,vdel;
for(int i=0;i<n;i++){
    int day;string cow;string del;
    cin>>day>>cow>>del;
    vday.pb(make_pair(day,i));vcow.pb(cow);vdel.pb(del);
}
sort(vday.begin(),vday.end());

int ans=0;

vector<int>prev={0,1,2},latest;
map<string,int>m;
m["Bessie"]=7;
m["Elsie"]=7;
m["Mildred"]=7;
for(int i=0;i<n;i++){
    int index=vday[i].second;
    string cow=vcow[index];
    string del=vdel[index];
    if(del[0]=='-'){
        m[cow]-=stoi(del.substr(1));
    }else{
        m[cow]+=stoi(del.substr(1));
    }
    vector<int>temp;
//    temp.pb(m["Bessie"]);temp.pb(m["Elsie"]);temp.pb(m["Mildred"]);
    int b=m["Bessie"];int e=m["Elsie"];int mi=m["Mildred"];
//    cout<<b<<" "<<e<<" "<<mi<<endl;
    int maxmilk=max(max(b,mi),e);
    if(maxmilk==b)temp.pb(0);
    if(maxmilk==e)temp.pb(1);
    if(maxmilk==mi)temp.pb(2);
    if(temp!=prev)ans++;
//    for(int i:temp)cout<<i<<" ";cout<<endl;for(int i:prev)cout<<i<<" ";cout<<endl;cout<<ans<<endl;
    prev=temp;
}







cout<<ans<<endl;









}//
