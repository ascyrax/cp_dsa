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
int k;cin>>k;
vector<pair<int,pair<int,int>>>ans;
for(int i=0;i<k;i++){
    int len;cin>>len;
    int sum=0;
    vector<int>v(len);for(int &i:v){
        cin>>i;sum+=i;
    }
    for(int j=0;j<len;j++){
       // cout<<"HI"<<endl;
        ans.pb(make_pair(sum-v[j],make_pair(i+1,j+1)));
    }
}
sort(ans.begin(),ans.end());
for(int i=1;i<ans.size();i++){
    //cout<<ans[i].first<<" "<<ans[i].second.first<<endl;
    if(ans[i].first==ans[i-1].first&&(ans[i].second.first!=ans[i-1].second.first)){
        cout<<"YES"<<endl;
        cout<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
        cout<<ans[i-1].second.first<<" "<<ans[i-1].second.second<<endl;
        return;
    }
}

cout<<"NO"<<endl;



}//
























int main()
{
    startTime=(double)clock();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt,"w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
