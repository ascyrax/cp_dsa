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

cout<<"----------------------------------------"<<endl;
vector<int>v={22,33,11,6,7,33,44,77,22};
sort(v.begin(),v.end());
for(int i:v)cout<<i<<" "<<endl;
cout<<"protoss vs terran"<<endl;
cout<<*(v.begin()+5)<<endl;
cout<<lower_bound(v.begin(),v.end(),7)-v.begin()<<endl;
cout<<"----------------------------------------"<<endl;


map<int,int>m;
m[2]=22;
m[3]=33;
m[5]=55;
m[1]=11;
m[4]=44;
m[0]=0;
for(auto el:m)cout<<el.first<<" "<<el.second<<endl;
cout<<"terran vs zerg"<<endl;
auto itm=m.begin();
for(int i=1;i<5;i++)itm++;
cout<<(itm)->first<<" "<<(itm)->second<<endl;
cout<<m.lower_bound(11)-m.begin()<<endl;
cout<<"----------------------------------------"<<endl;


set<int>s;
s.insert(4);s.insert(33);s.insert(8);s.insert(1);s.insert(55);s.insert(77);s.insert(6);s.insert(2);
for(auto el:s)cout<<el<<endl;
cout<<"zerg vs protoss"<<endl;
auto its=s.begin();
for(int i=1;i<4;i++)its++;
cout<<*(its)<<endl;

cout<<s.lower_bound(33)-s.begin()<<endl;
cout<<"----------------------------------------"<<endl;










}////////////////////////////




























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
