#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define endl "\n"
#define ioss ios::sync_with_stdio(false);cin.tie(0);
#define pb push_back


void suraj();



int main()
{
    freopen("cardgame.in","r",stdin);freopen("cardgame.out","w",stdout);
    ioss
    suraj();
    return 0;
}

/////////////////////////////////////////////////////////////////
void suraj(){
int n;cin>>n;
vector<bool>taken(2*n+1);// index from 0 to 2n
vector<int>elsie(n);for(int &i:elsie){
    cin>>i;taken[i]=true;
}
vector<int>bessie;
for(int i=1;i<=2*n;i++){
    if(taken[i]==false)bessie.pb(i);
}


sort(bessie.begin(),bessie.end());

int lenb=int(bessie.size());
int lene=int(elsie.size());

set<int>elsieLeft,elsieRight;
for(int i=0;i<lenb/2;i++){
    elsieLeft.insert(elsie[i]);
    elsieRight.insert(elsie[i+lenb/2]);
}

//sort(elsieLeft.begin(),elsieLeft.end());
//sort(elsieRight.begin(),elsieRight.end());
int ans=0;
for(int i=lenb/2;i<lenb;i++){
    //find best combination of a,b,c and d,e,f such that maxm nos among d,e,f are higher than a corresponding value of a,b,c;
    auto a=elsieLeft.lower_bound(bessie[i]);
    if(a!=elsieLeft.begin()){
        ans++;
        elsieLeft.erase(--a);
    }
}
for(int i=0;i<lenb/2;i++){
   auto a=elsieRight.lower_bound(bessie[i]);
   if(a!=elsieRight.end()){
       ans++;
       elsieRight.erase(a);
   }
}

cout<<ans<<endl;

}
//////////////////////////////////////////////////////


























