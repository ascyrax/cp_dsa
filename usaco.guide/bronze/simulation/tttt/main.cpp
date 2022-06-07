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


string a,b,c;cin>>a>>b>>c;

set<set<char>>v;
vector<string>vs;vs.pb(a);vs.pb(b);vs.pb(c);
string va="";va+=a[0];va+=b[0];va+=c[0];vs.pb(va);
string vb="";vb=vb+a[1]+b[1]+c[1];vs.pb(vb);
string vc="";vc=vc+a[2]+b[2]+c[2];vs.pb(vc);
string dm="";dm=dm+a[0]+b[1]+c[2];vs.pb(dm);
string dn="";dn=dn+a[2]+b[1]+c[0];vs.pb(dn);
for(string temp:vs){
    //cout<<"string"<<temp<<endl;
    set<char>s;
    for(char i:temp)s.insert(i);
    v.insert(s);
}
vector<int>tv;
for(auto i:v){
    tv.pb(i.size());
}
sort(tv.begin(),tv.end());
int cnta=0,cntb=0;
for(int i=0;i<tv.size();i++){
    //cout<<"HI"<<tv[i]<<endl;
    if(tv[i]==1)cnta++;
    else if(tv[i]==2)cntb++;
}
cout<<cnta<<endl;cout<<cntb<<endl;
}//
























int main()
{
        startTime=(double)clock();
        freopen("tttt.in","r",stdin);
        freopen("tttt.out","w",stdout);
        //ioss
        //int t;cin>>t;while(t--)
        suraj();
        //suraj2();
        //suraj3();
        //suraj4();
        return 0;
}
