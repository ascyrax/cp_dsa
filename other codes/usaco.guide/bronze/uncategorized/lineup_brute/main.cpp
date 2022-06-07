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









vector<pair<string,string>>vp;


vector<string>cows;



bool check(){
    for(auto ta:vp){
        auto tb=ta.first;
        auto tc=ta.second;
        int te,td;
        for(int i=0;i<8;i++){
            if(cows[i]==tb){
                td=i;
            }else if(cows[i]==tc)
                te=i;
        }
        if(abs(td-te)==1){
            continue;
        }else return false;

    }
    return true;
}












void suraj(){
int n;cin>>n;

for(int i=0;i<n;i++){
    string ta;
    string tb;
    string t;
    cin>>ta;cin>>t;cin>>t;cin>>t;cin>>t;cin>>tb;
    /*for(int i=0;i<ta.size();i++){
        if(ta[i]==' '){
            tb=ta.substr(0,i);
        }
    }
    string tc;
    for(int i=ta.size()-1;i>=0;i--){
        if(ta[i]==' '){
            tc=ta.substr(i+1);
        }
    }*/
    vp.pb(make_pair(ta,tb));
}

cows.pb("Beatrice");
cows.push_back("Belinda");
cows.push_back("Bella");
cows.push_back("Bessie");
cows.push_back("Betsy");
cows.push_back("Blue");
cows.push_back("Buttercup");
cows.push_back("Sue");
do{
    if(check()==true){
        for(string ta:cows)cout<<ta<<endl;
        break;
    }
}while(next_permutation(cows.begin(),cows.end()));




}//
























int main()
{
    startTime=(double)clock();
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
