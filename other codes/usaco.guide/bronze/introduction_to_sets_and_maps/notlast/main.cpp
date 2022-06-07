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
map<string,int>m;
for(int i=0;i<n;i++){
   string s;cin>>s;int a;cin>>a;
   m[s]+=a;
}
vector<int>v;
for(auto it=m.begin();it!=m.end();it++){
    v.pb(it->second);
}
sort(v.begin(),v.end());
if(v.size()<7){
    if(v.size()>1&&v[0]==v[1]){
        cout<<"Tie"<<endl;
    }else if(v.size()==1||(v.size()>1&&v[0]!=v[1])){
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second==v[0]){
                cout<<it->first<<endl;return;
            }
        }
    }
}else{
    for(int i=0;i<v.size()-1;i++){
        if(i==v.size()-2){
            if(v[i]==v[i+1]){
                v.clear();break;
            }else{
                v.erase(v.begin());break;
            }
        }
        if(v[i]==v[i+1]){
            v.erase(v.begin()+i);
            i--;
        }else{
            v.erase(v.begin()+i);break;
        }
    }
    //unique(v.begin(),v.end());
    if(v.empty()){
        cout<<"Tie"<<endl;return;
    }
    else if(v.size()>1&&v[0]==v[1]){
        cout<<"Tie"<<endl;
    }else if(v.size()==1||(v.size()>1&&v[0]!=v[1])){
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second==v[0]){
                cout<<it->first<<endl;return;
            }
        }
    }
}



}//
























int main()
{
    startTime=(double)clock();
    freopen("notlast.in","r",stdin);
    freopen("notlast.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
