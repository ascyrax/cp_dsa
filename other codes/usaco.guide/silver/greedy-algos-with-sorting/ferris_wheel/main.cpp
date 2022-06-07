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































vector<bool>visited(200000);




void suraj(){///////////////////////
ll n,x;cin>>n>>x;
visited.resize(n);
vector<ll>weight(n);
for(ll &i:weight){
    cin>>i;
}
sort(weight.begin(),weight.end());

int ans=0;
for(int i=n-1;i>=0;i--){
    if(visited[i])continue;
    ll boy=weight[i];
    ll partner=x-boy;
    auto it=upper_bound(weight.begin(),weight.end(),partner)-weight.begin();
    cout<<boy<<" "<<partner<<" "<<it<<" ";
    if(it==0){
        ans++;
        visited[i]=true;
    }else if(it==n){
        ans++;
        visited[i]=true;
        int j=i-1;
        while(visited[j]==true){//keep loooping
            j--;
        }
        visited[j]=true;
    }else{
        if(visited[it-1]==false){
            ans++;
            visited[i]=true;
            visited[it-1]=true;
        }else{//check for adjacent equal values
            int j=it;
            int flag=0;
            while(weight[j]==weight[it-1]){
                if(visited[j]==false){
                    visited[j]=true;
                    visited[i]=true;
                    ans++;
                    flag=1;
                    break;
                }else{
                    j++;
                }
            }
            if(flag==0){
                ans++;
                visited[i]=true;
            }
        }
    }
    cout<<ans<<endl;
}


cout<<ans<<endl;










}////////////////////////////




























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
