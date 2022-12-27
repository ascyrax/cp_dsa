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
vector<int>height(n);for(int &i:height)cin>>i;


sort(height.begin(),height.end());
int diffmin=2e9;
int left=-2,right=-1;
for(int i=0;i<n-1;i++){
    int diff=height[i+1]-height[i];
    if(diff<diffmin){
        diffmin=diff;
        left=i;right=i+1;
    }
}
if(n==2){
    cout<<height[0]<<" "<<height[1]<<endl;
    return;
}
for(int i=right;i<n;i++)cout<<height[i]<<" ";
for(int i=0;i<=left;i++)cout<<height[i]<<" ";cout<<endl;














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
