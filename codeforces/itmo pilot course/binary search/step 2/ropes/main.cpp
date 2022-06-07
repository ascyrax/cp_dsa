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







// @author: ascyrax




























//...............................



void suraj(){


int n,k;cin>>n>>k;
vector<int>ropes(n);for(int &i:ropes)cin>>i;

sort(ropes.rbegin(),ropes.rend());


float left=0;float right=ropes[0];

for(int i=0;i<=100;i++){
    int count=0;
    float mid=(left+right)/2;
    for(auto i:ropes){
        count+=i/mid;
    }
//    cout<<left<<" "<<right<<" "<<count<<" "<<mid<<endl;
    if(count<k){
        right=mid;
    }else{
        left=mid;
    }
}

cout<<setprecision(20)<<left<<endl;





}


//................................




























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
