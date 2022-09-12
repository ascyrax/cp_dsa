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
void print(string s,vector<int>v){
    cout<<s<<endl;
    for(auto el:v)cout<<el<<" ";cout<<endl;
}
//.....................................

void suraj(){
    int n;cin>>n;
    vector<int>a(n), b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

int ans=0;

    // step 1
    map<int,int> ma,mb;
    for(auto el:a)ma[el]++;
    for(auto el:b)mb[el]++;



    for(int i=0;i<n;i++){
        if(mb.count(a[i])==0 || mb[a[i]]==0){
            if(a[i]<10)continue;
            ans++;
            ma[a[i]]--;
            // find len of the a[i]
            int len = 0;
            int ai_copy = a[i];
            while(ai_copy){len++;ai_copy/=10;}
            a[i] = len;
            ma[len]++;
        }else{
            mb[a[i]]--;
        }
    }

    for(int i=0;i<n;i++){
        if(ma.count(b[i])==0 || ma[b[i]]==0){
            if(b[i]<10)continue;
            ans++;
            mb[b[i]]--;
            // find len of b[i]
            int len  = 0;
            int bi_copy = b[i];
            while(bi_copy){len++;bi_copy/=10;}
            b[i] = len;
            mb[len]++;
        }else{
            ma[b[i]]--;
        }
    }
sort(a.begin(),a.end());
sort(b.begin(),b.end());
//     print("a",a);
//     print("b",b);
// cout<<"ans: "<<ans<<endl;
    // step 2
ma.clear();
mb.clear();
    for(auto el:a)ma[el]++;
    for(auto el:b)mb[el]++;
for(int i=0;i<n;i++){
    // cout<<"a[i]: "<<a[i]<<endl;
    
        if(mb.count(a[i])==0 || mb[a[i]]==0){
            // cout<<mb[a[i]]<<endl;
            // cout<<"if"<<endl;
            if(a[i]==1)continue;
            ans++;
            ma[a[i]]--;
            // find len of the a[i]
            int len = 0;
            int ai_copy = a[i];
            while(ai_copy){len++;ai_copy/=10;}
            a[i] = len;
            ma[len]++;
        }else{
            // cout<<"else"<<endl;
            // cout<<mb[a[i]]<<endl;
            mb[a[i]]--;
        }
    }
// cout<<"ans 3/4 : "<<ans<<endl;
    for(int i=0;i<n;i++){
        if(ma.count(b[i])==0 || ma[b[i]]==0){
            if(b[i]==1)continue;
            ans++;
            mb[b[i]]--;
            // find len of b[i]
            int len  = 0;
            int bi_copy = b[i];
            while(bi_copy){len++;bi_copy/=10;}
            b[i] = len;
            mb[len]++;
        }else{
            ma[b[i]]--;
        }
    }




    cout<<ans<<endl;
}
