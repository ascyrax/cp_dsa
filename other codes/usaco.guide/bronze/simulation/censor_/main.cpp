#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef  long long ll;
typedef long double ld;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define all(x)  x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)(x).size()
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


string s,t;cin>>s>>t;
int lent=t.size();
//for(int i=s.size()-1;i>=0;i--){
//    if(s[i]==t[0]){//cout<<"match found "<<i<<endl;
//        int flag=0;
//        for(int j=0;j<lent;j++){
//            if(i+j>=s.size()){break;}
//            if(s[i+j]!=t[j]){break;
//            }else if(s[i+j]==t[j]){
//                flag++;
//            }
//        }//cout<<flag<<" "<<lent<<endl;
//        if(flag==lent){
//            s.erase(i,lent);
////            cout<<"s "<<s<<endl;
//        }
//    }
//}

//auto a=s.find(t);
//cout<<typeid(a).name()<<" "<<a<<endl;
string ans="";
for(int i=0;i<s.size();i++){
    ans.pb(s[i]);
    if(ans.size()>=lent&&(ans.substr(ans.size()-lent)).find(t)!=string::npos){
//        ans.erase(ans.size()-lent,lent);
        ans.resize(ans.size()-lent);
    }
}
cout<<ans<<endl;



















}//




































int main()
{
    startTime=(double)clock();
    freopen("censor.in","r",stdin);freopen("censor.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
