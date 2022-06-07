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




































void suraj(){


vector<int>v(9);
for(int i:v)cout<<i<<" ";cout<<endl;
iota(v.begin(),v.end(),1);
for(int i:v)cout<<i<<" ";cout<<endl;
ll iter=0;
map<int,int>m;
do{
    iter++;
    int sumt=v[0]+v[1]+v[2];
    int sumr=v[2]+v[5]+v[8];
    int sumb=v[6]+v[7]+v[8];
    int suml=v[0]+v[3]+v[6];
    int sumd=v[2]+v[4]+v[6];
    if(sumt==sumr&&suml==sumb&&sumr==suml&&suml==sumd){
        m[suml]++;
//        cout<<iter<<": "<<sumt<<" ";
//        for(int i=0;i<9;i++){
//            if(i%3==0)cout<<endl;
//            cout<<v[i]<<" ";
//        }cout<<endl;
    }

}while(next_permutation(v.begin(),v.end()));
cout<<iter<<endl;



for(auto i:m)
    cout<<i.first<<" "<<i.second<<endl;







}//




























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
