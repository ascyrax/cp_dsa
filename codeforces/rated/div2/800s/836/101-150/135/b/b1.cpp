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

if((n-2)%2==0){
    for(int i=n-2;i>=1;i--)cout<<i<<" ";
    cout<<n-1<<" "<<n<<endl;
}else{
    for(int i=n-1;i>=2;i--){
        if(i==n-2)continue;
        cout<<i<<" ";
    }
    cout<<1<<" "<<n-2<<" "<<n<<endl;
}

}
