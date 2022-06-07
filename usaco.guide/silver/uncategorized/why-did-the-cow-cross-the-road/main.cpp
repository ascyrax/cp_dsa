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



























bool customcows(pair<int,int>a,pair<int,int>b){
    if(b.second<a.second){
        return false;
    }else if(b.second==a.second){
        return a.first<b.first;
    }else return true;
}








void suraj(){///////////////////////


int c,n;cin>>c>>n;

vector<int>chicks(c);for(int &i:chicks)cin>>i;
vector<pair<int,int>>cows(n);for(auto &i:cows)cin>>i.first>>i.second;


sort(cows.begin(),cows.end(),customcows);
sort(chicks.begin(),chicks.end());



//for(auto i:cows)cout<<i.first<<" "<<i.second<<endl;

vector<bool>cowsWithChicks(n);
//for(auto i:cowsWithChicks)cout<<i<<" ";cout<<endl;
int pointerCow=0;
for(int chick:chicks){
//    cout<<"chick "<<chick<<endl;
    for(int i=pointerCow;i<n;i++){
        if(cowsWithChicks[i]==true)continue;
//        cout<<"blah "<<cows[i].first<<" "<<cows[i].second<<endl;
        if(chick<=cows[i].second&&chick>=cows[i].first){
//            cout<<"partner found"<<cows[i].first<<" "<<cows[i].second<<endl;
            cowsWithChicks[i]=true;
            pointerCow=++i;
            break;
        }
        if(chick<cows[pointerCow].first)break;
    }
}
int ans=0;
for(auto i:cowsWithChicks)
    if(i==true)ans++;

cout<<ans<<endl;





}////////////////////////////




























int main()
{
    startTime=(double)clock();
    freopen("helpcross.in","r",stdin);freopen("helpcross.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
