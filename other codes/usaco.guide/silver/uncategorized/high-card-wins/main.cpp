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




int n;cin>>n;
vector<int>elsie(n);for(int &i:elsie)cin>>i;
sort(elsie.begin(),elsie.end());
vector<int>bessie;
int temp=0;
for(int i=1;i<=2*n;i++){
    if(elsie[temp]!=i){
        bessie.pb(i);
    }else temp++;
}

sort(bessie.rbegin(),bessie.rend());
sort(elsie.rbegin(),elsie.rend());

int bessieWins=0;
int left=0,right=n-1;
for(int i=0;i<n;i++){
    if(bessie[left]>elsie[i]){
        bessieWins++;left++;
    }
}


cout<<bessieWins<<endl;








}////////////////////////////




























int main()
{
    startTime=(double)clock();
    freopen("highcard.in","r",stdin);freopen("highcard.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
