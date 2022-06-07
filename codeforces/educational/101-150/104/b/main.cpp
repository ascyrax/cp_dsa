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















//even n............even odd..never
//even n............even even/odd odd...1
//odd n.............odd odd/even even...infinite
//odd n.............even odd.....infinite9v6










void suraj(){


int n,k;cin>>n>>k;
int nmoves=k-1;
if(n%2==0){
    int finalpos=(nmoves)%(n)+1;
    cout<<finalpos<<endl;
}else{
    int bshift=(nmoves)/(n/2);
    int finalpos=(nmoves)%(n)+1;//without b shift
    finalpos+=(bshift%n);//including no of collisions leading to bshift
    if(finalpos>n)cout<<finalpos-n<<endl;
    else cout<<finalpos<<endl;
}



}//




































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
