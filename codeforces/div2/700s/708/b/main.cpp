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

int n,m;cin>>n>>m;
vector<bool>visited(m);
map<int,int>mp;
set<int>s;
for(int i=0;i<n;i++){
    int a;cin>>a;
    mp[a%m]++;
    s.insert(a%m);
}

//for(auto el:visited){
//    if(el==false)cout<<"queens"<<endl;
//}

int ans=0;
//el.first belongs from 0 to m-1;

for(auto el:mp){//cout<<"for "<<visited[el.first]<<" "<<el.first<<" "<<el.second<<endl;
    int a=el.first;
    int cnta=el.second;
//    cout<<a<<" "<<cnta<<endl;cout<<"ans "<<ans<<endl;
    if(cnta==0)continue;
//    cout<<a<<" "<<cnta<<endl;
    int b=m-a;int cntb=0;
    if(visited[a])continue;
    if(a==0){//cout<<"if"<<endl;
        ans++;visited[0]=true;continue;
    }else if(m%2==0&&a==m/2){//cout<<"else if"<<endl;
        visited[a]=true;ans++;continue;
    }else{//cout<<"else"<<endl;
        visited[a]=true;
        cntb=mp[b];
        if(cntb>0){
            visited[b]=true;
            int diff=abs(cntb-cnta);
            if(diff==0||diff==1){
                ans++;
            }else{
                ans+=diff;
            }
        }else{
            ans+=cnta;visited[b]=true;
        }
    }


}



cout<<ans<<endl;
//cout<<"-----------------------"<<endl;


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
