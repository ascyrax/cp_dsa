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

int n,k;cin>>n>>k;
string s;cin>>s;

int left=1;

vector<int>temp;
for(int i=0;i<int(s.size());i++){
    if(s.substr(i,left)>s.substr(0,left)){
        s=s.substr(0,i); break;
    }

}
//cout<<"s "<<s<<endl;
for(int i=0;i<int(s.size());i++){
    if(s[i]==s[0]){
        temp.pb(i);
    }
}
while(left<=int(s.size())){//cout<<"while"<<endl;cout<<left<<endl;
    for(int i:temp){
//        cout<<s.substr(i,left)<<" "<<s.substr(0,left)<<" "<<(s.substr(i,left)>s.substr(0,left))<<endl;
        if(i+left>n)break;
        if(s.substr(i,left)>s.substr(0,left)){//cout<<"if"<<endl;
            s=s.substr(0,i);
            break;
        }
    }
    left++;
}

int nconcat=k/int(s.size());
vector<char>ans;
for(int i=0;i<nconcat;i++){
    for(auto el:s)ans.pb(el);
}
for(auto el:s)ans.pb(el);

for(int i=0;i<k;i++)cout<<ans[i];cout<<endl;














}////////////////////////////




























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
//    int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
