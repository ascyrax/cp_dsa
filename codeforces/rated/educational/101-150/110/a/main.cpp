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


int a,b,c,d;cin>>a>>b>>c>>d;
int l1=min(a,b);
int l2=min(c,d);
int w1=max(a,b);
int w2=max(c,d);
int temp=min(w1,w2);
int l12=max(l1,l2);
if(l12>temp)cout<<"NO"<<endl;
else cout<<"YES"<<endl;














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
