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
int ans=0;
int n;cin>>n;
vector<int>va,vd,vdiff,vdelay;
for(int i=0;i<n;i++){
    int a,d;cin>>a>>d;
//    int diff=d-a;
    va.pb(a);vd.pb(d);//vdiff.pb(diff);
}
for(int i=0;i<n;i++){
    int delay;cin>>delay;
    vdelay.pb(delay);
}
vector<int>time;
time.pb(va[0]);
for(int i=1;i<n;i++){
    int temp=va[i]-vd[i-1];
    time.pb(temp);
}
int arrive=0;
int depart=0;
int del=0;
for(int i=0;i<n;i++){
    arrive=depart+time[i]+vdelay[i];//cout<<"arrive "<<arrive<<endl;
    del=ceil((vd[i]-va[i])/2.0);
    if((arrive+del)>vd[i]){
        depart=arrive+del;
    }else{
        depart=vd[i];
    }//cout<<"depart "<<depart<<endl;
}


cout<<arrive<<endl;




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
