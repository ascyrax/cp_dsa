/*
ID: ascyrax1
TASK: test
LANG: C++14
*/
/* LANG can be C++11 or C++14 for those more recent releases */
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
void suraj();
int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
























vector<int>ss;vector<vector<int>>allss;
void search(int k){
    if(k==4){
        allss.pb(ss);//phi //3 //2 //2 3//1 3//1 2//1 2 3//0// 0 3
    }else{
        search(k+1);
        ss.pb(k);//3
        search(k+1);
        ss.pop_back();
    }
}










void suraj(){
    vector<int>v={0,1,2,3};
    search(0);

    for(auto i:allss){
        for(auto j:i)cout<<j<<" ";cout<<endl;
    }



    cout<<"protos"<<endl<<"terran"<<endl<<"zerg"<<endl;
    sort(allss.begin(),allss.end());
    for(auto i:allss){
        for(auto j:i)cout<<j<<" ";cout<<endl;
    }








}//
