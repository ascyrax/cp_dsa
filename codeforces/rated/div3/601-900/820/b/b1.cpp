// @author: ascyrax
#include <bits/stdc++.h>
using namespace std;
typedef  		  long long ll;
typedef 		  long double ld;
#define endl 		  "\n"
#define ioss 		  ios::sync_with_stdio(false);cin.tie(0);
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front

double startTime;

double gct()//get_current_time
{
    return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}

void suraj();

signed main()
{

    ioss

    //startTime=(double)clock();

    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

    //cout << setprecision(15) << fixed;

    int t = 1;

    cin>>t;

    for(int i=1;i<=t;i++)
    {

        //cout<<"Case #"<<i<<": ";

        suraj();
    }

    return 0;

}

int inf=1e18;
//.....................................

//.....................................

//.....................................

//.....................................

void suraj(){
int n;cin>>n;
string t;cin>>t;
vector<char>ans;
for(int i=n-1;i>=0;i--){
    if(t[i]=='0'){
      if(t[i-1]=='0'){
        if(t[i-2]=='1')
            ans.pb('j');
        else if(t[i-2]=='2')
          ans.pb('t');
      }else{
        // t[i-1] != '0'
        int val = 10*(t[i-2]-'0') + t[i-1]-'0';
        ans.pb('a'+val-1); 
      }
      i-=2;
    }else{
      ans.pb('a'+(t[i]-'1'));
    }
  // cout<<"ans: "<<endl;
  // for(auto el:ans)cout<<el;cout<<endl;
}
reverse(ans.begin(),ans.end());
for(auto el:ans)cout<<el;
cout<<endl;

}
