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
int n;cin>>n;
vector<pair<int,string>>v;
for(int i=0;i<n;i++){
    string s;cin>>s;int lens=s.size();
    v.eb(make_pair(lens,s));
}
vector<string>ans;
sort(v.begin(),v.end());
for(int i=0;i<n;i++){
    string a=v[i].second;
    if(i==n-1)ans.pb(a);
    for(int j=i+1;j<n;j++){
        string b=v[j].second;
        if((b.find(a)>=0)&&((v[j].second).find(a)<=b.size())){
            ans.pb(a);break;
        }
        else{
            cout<<"NO"<<endl;return;
        }
    }
}
cout<<"YES"<<endl;for(string j:ans)cout<<j<<endl;


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
