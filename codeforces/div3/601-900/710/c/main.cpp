/*
ID: ascyrax1
TASK: test
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define endl "\n"
#define ioss ios::sync_with_stdio(false);cin.tie(0);
#define pb push_back

double startTime;
double gct()//get_current_time
{
    return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}
void suraj();




































void suraj(){///////////////////////

string p,q;cin>>p>>q;
int lenp=int(p.size());
int lenq=int(q.size());
int a=0,b=0,c=0,d=0;
int ans=lenp+lenq;
for(a=0;a<lenp;a++){
    for(b=0;b<lenp-a;b++){
        for(c=0;c<lenq;c++){
            for(d=0;d<lenq-c;d++){
                string sab=p.substr(a,lenp-(a+b));
                string scd=q.substr(c,lenq-(c+d));
                if(sab==scd){
//                    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                    ans=min(ans,a+b+c+d);
                }
            }
        }
    }
}

cout<<ans<<endl;













}////////////////////////////




























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
