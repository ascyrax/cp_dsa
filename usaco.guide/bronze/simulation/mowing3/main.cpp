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
int n;cin >>n;
int cx=0;int cy=0;
int delx=0;int dely=0;
int t=0;
set<int>ans;
map<pair<int,int>,int>m;//(x,y),t
m[make_pair(cx,cy)]=t;
for(int i=0;i<n;i++){
    string s;cin>>s;int len;cin>>len;
    if(s=="W"){
        delx=-1;dely=0;
    }else if(s=="E"){
        delx=1;dely=0;
    }else if(s=="N"){
        delx=0;dely=1;
    }else{
        delx=0;dely=-1;
    }
    for(int j=0;j<len;j++){
        t++;
        if(m.count(make_pair(cx+delx,cy+dely))>0){
            ans.insert(t-(m[make_pair(cx+delx,cy+dely)]));
            m[make_pair(cx+delx,cy+dely)]=t;

        }else
            m[make_pair(cx+delx,cy+dely)]=t;
        cx=cx+delx;cy=cy+dely;
    }

}
if(ans.size()==0)cout<<-1<<endl;
else
cout<<*ans.begin()<<endl;




}//
























int main()
{
    startTime=(double)clock();
    freopen("mowing.in","r",stdin);
    freopen("mowing.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
