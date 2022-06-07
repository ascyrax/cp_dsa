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


























string word="";

void call();

set<string>ss;
int lens;

string s;

bool check[8];

void suraj(){

cin>>s;
lens=s.size();
int num=0;
call();

cout<<ss.size()<<endl;
for(auto i:ss)cout<<i<<endl;




}//





void call(){
    if(word.size()==lens){
        ss.insert(word);return;
    }else{
        for(int i=0;i<lens;i++){
             if(check[i]==true)
                 continue;
             else{
                check[i]=true;
                word.pb(s[i]);
                call();
                word.pop_back();
                check[i]=false;
             }
        }return;
    }
}





















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
