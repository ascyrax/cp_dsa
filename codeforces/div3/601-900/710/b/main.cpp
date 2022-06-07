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


int n,k;cin>>n>>k;
string s;cin>>s;
int ans=0;
vector<int>vindAsterix;// 1 2 4 5 6
for(int i=0;i<n;i++){
    if(s[i]=='*'){
        vindAsterix.pb(i);
    }
}
int first=vindAsterix[0];
int last=vindAsterix[int(vindAsterix.size())-1];

if(int(vindAsterix.size())<=2){
    cout<<int(vindAsterix.size())<<endl;return;
}else if(last-first<=k){
    ans=2;return;
}else{
    ans=2;
    int current =first;
    while(true){
        //else
        auto next=lower_bound(vindAsterix.begin(),vindAsterix.end(),current+k);
        if(next==vindAsterix.end()){
            break;
        }
        else if(*next>=last-k){
            ans++;break;
        }else{
            current=*next;ans++;
        }
    }

    cout<<ans<<endl;
}










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
