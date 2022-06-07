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
    freopen("cownomics.in","r",stdin);freopen("cownomics.out","w",stdout);
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


int ans=0;

int n,m;cin>>n>>m;
vector<string>spotty(n),plain(n);
for(string &s:spotty)cin>>s;for(string &s:plain)cin>>s;
int cnt=0;
for(int i=0;i<=m-3;i++){
    for(int j=i+1;j<=m-2;j++){
        for(int k=j+1;k<=m-1;k++){cnt++;
//            vector<string>vtemp;
            map<string,int>m;
            for(int a=0;a<n;a++){
                string stemp;
                stemp.pb(spotty[a][i]);
                stemp.pb(spotty[a][j]);
                stemp.pb(spotty[a][k]);
//                vtemp.pb(stemp);
                m[stemp]++;
            }int flag=0;
            for(int a=0;a<n;a++){
                string stemp;
                stemp.pb(plain[a][i]);
                stemp.pb(plain[a][j]);
                stemp.pb(plain[a][k]);
//                if(find(vtemp.begin(),vtemp.end(),stemp)!=vtemp.end()){
//                    flag=-1;break;
//                }
                if(m[stemp]>0){
                    flag=-1;break;
                }
            }
            if(flag==0)ans++;
        }
    }
}
cout<<ans<<endl;
//cout<<cnt<<endl;





//2.5e4*500=1.25e7














}//
