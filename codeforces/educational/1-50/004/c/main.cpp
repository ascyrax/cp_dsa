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

string s;cin>>s;
stack<char>st;
if(s.empty()){
    cout<<0<<endl;return;
}
int lens=s.size();
int ans=0;
for(int i=0;i<lens;i++){
    if(s[i]=='<'||s[i]=='{'||s[i]=='['||s[i]=='('){
        st.push(s[i]);
    }
    else{
        if(st.empty()){
            cout<<"Impossible"<<endl;return;
        }
        else{
            if(s[i]==')'&&st.top()=='(')st.pop();
            //else if(st.top()+'2'==s[i]+'0')st.pop();
            else if(s[i]=='}'&&st.top()=='{')st.pop();
            else if(s[i]==']'&&st.top()=='[')st.pop();
           else if(s[i]=='>'&&st.top()=='<')st.pop();
            else{
                st.pop();ans++;
            }
        }
    }
}
if(st.empty())
cout<<ans<<endl;
else cout<<"Impossible"<<endl;



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
