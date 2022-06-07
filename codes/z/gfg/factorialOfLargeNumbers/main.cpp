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















string magic(int i,string s){
//    cout<<endl<<"magic "<<i<<" "<<s<<" ";
    int carry=0;int a=0,b=0;
    string str;
    for(int j=int(s.size()-1);j>=0;j--){
        a=s[j]-48;
        b=a*i+carry;

        if(b>9){
            carry=b/10;b-=carry*10;
        }else{
            carry=0;
        }
        str.pb(b+48);
    }
//    cout<<"carry"<<" "<<carry<<endl;
    if(carry>=1){
        string temp="";
        while(carry>0){
            temp.pb(carry%10+48);
            carry/=10;
        }
        for(char c:temp){
            str.pb(c);
        }
    }
    reverse(str.begin(),str.end());
//    cout<<str<<endl;

    return str;
}











void suraj(){




//    int n;cin>>n;
    for(int n=5;n<=50;n++){
        string dps[n+1];
        dps[0]="1";
        for(int i=1;i<=n;i++){
            dps[i]=magic(i,dps[i-1]);
        }
         cout<<dps[n]<<endl;
    //    for(int i=0;i<=n;i++)cout<<dps[i]<<" ";cout<<endl;

    }




















}//




































int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
//    ioss
//    int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
