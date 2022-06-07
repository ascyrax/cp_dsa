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



int n;cin>>n;
vector<int>v(n);

int inQueue=0;

for(int i=0;i<n;i++){
    cin>>v[i];
    if(v[i]>=n-1){
        inQueue++;
    }
}

sort(v.begin(),v.end());
for(int i=0;i<n;i++){
    if(v[i]>=n-1)break;
    else{
        if(v[i]>=inQueue){
            inQueue++;
        }
    }
}

cout<<inQueue<<endl;






}////////////////////////////




























int main()
{
    startTime=(double)clock();
    freopen("lemonade.in","r",stdin);freopen("lemonade.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
