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
if(n%2==0){
    int a=(n-2)/2;
    if(a%2==1){
        cout<<n/2<<" "<<n/4<<" "<<n/4<<endl;
    }else{
        cout<<2<<" "<<(n-2)/2<<" "<<(n-2)/2<<endl;
    }
}else{
    cout<<1<<" "<<(n-1)/2<<" "<<(n-1)/2<<endl;
}














}////////////////////////////




























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}