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
int n;cin>>n;
string s;cin>>s;
if(n==2){
    if(s[0]=='-'||s[1]=='-'){
        cout<<2<<endl;
    }else if(s[0]=='>'&&s[1]=='>'){
        cout<<2<<endl;
    }else if(s[0]=='<'&&s[1]=='<'){
        cout<<2<<endl;
    }else cout<<0<<endl;
    return;
}
vector<int>v(n);
int g=0,l=0,e=0;
for(int i=0;i<n;i++){
    if(s[i]=='>')g++;
    else if(s[i]=='<')l++;
    else e++;
}int flag=0;
if(e==n){
    cout<<n<<endl;return;
}
if(g>0&&l>0){
    flag=2;
}else if(g==0||l==0){
    cout<<n<<endl;return;
}




for(int i=0;i<n;i++){
    char a=s[i];
    if(a=='-'){
        v[i]=1;v[(i+1)%n]=1;
    }else if(a=='>'){
        if(flag==2)continue;
        else v[i]=1;
    }else{
        if(flag==2)continue;
        else v[(i+1)%n]=1;
    }
}


int cnt=0;
for(int i:v)if(i==1)cnt++;
cout<<cnt<<endl;


}//










/*else if(a=='>'){
        int flag=0;
        int tcnt=1;
        for(int j=i+1;;j++,tcnt++){
            if(s[j%n]=='<'){
                flag=1;break;
            }
            //if(j%n==i-1)break;
            if(tcnt==n)break;
        }
        if(flag==0)v[i]=1;
    }else if(a=='<'){int flag=0;int tcnt=1;
        for(int j=i-1;;j--,tcnt++){
            if(s[(j+n)%n]=='>'){
                flag=1;break;
            }
            if(tcnt==n)break;

        }
        if(flag==0)v[i+1]=1;
    }*/













int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);
    //freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
