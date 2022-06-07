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


//cout<<"....................................."<<endl;

ll days,d,p,q;cin>>days>>d>>p>>q;

//p p p...d times, p+q p+q ...d times,p+nIncrease*q....nFinalRound times

ll ans=0;
if(days<=d){
    ans=p*min(days,d);
    cout<<ans<<endl;
}else{
    ll div=ceil(days/(d*1.0));//div no of rounds where each round consists of similar values eg p+xq
    ll rem=days%d;//last round will contain rem similar values
    // eg days=27 d=5 then last round contains 2 similar values ie. on day 26 and 27
    if(rem==0)rem=d;//last round will contain d similar values
//    for(int i=1;i<div;i++){
//        ans+=(p +(i-1)*q)*d;
//    }
    ans+=d*(p*(div-1)+(div-2)*(div-2+1)/2*q);
    ans+=(p+(div-1)*q)*rem;
    cout<<ans<<endl;
}


}////////////////////////////


// 1 2
// 1 1 2
// 1 1 3 3 5

























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
