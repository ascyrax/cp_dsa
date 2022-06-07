#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef  long long ll;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define endl "\n"
#define ioss ios::sync_with_stdio(false);cin.tie(0);
#define pb push_back
#define eb emplace_back

double startTime;
double gct()//get_current_time
{
    return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}





























void suraj2(){

int n;cin>>n;
vector<int>count(26);
vector<array<string,2>>v(n);
for(int i=0;i<n;i++){
    cin>>v[i][0]>>v[i][1];
    for(char c:v[i][0])
        count[c-'a']++;
    for(char c:v[i][1])
        count[c-'a']++;

}
for(int i=0;i<n;i++){
   // string a=v[i][0];string b=v[i][1];
    for(int j=0;j<v[i][0].size();j++){
        for(int k=0;k<v[i][1].size();k++){
            if(v[i][1][k]==v[i][0][j]){
                v[i][1].erase(k,1);
                count[v[i][0][j]-'a']--;
                break;
            }
        }
    }
}

for(int i:count)cout<<i<<endl;


}//



void suraj(){
    int n;cin>>n;
    vector<int>v(26);
    for(int i=0;i<n;i++){
        string a,b;cin>>a>>b;
        vector<int>va(26),vb(26);
        int lena=a.size();int lenb=b.size();
        for(int i=0;i<lena;i++){
            va[a[i]-'a']++;
        }
        for(int i=0;i<lenb;i++){
            vb[b[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            v[i]+=max(va[i],vb[i]);
        }
    }
for(int i:v)cout<<i<<endl;


///////////////////////////////
}




















int main()
{
    startTime=(double)clock();
    freopen("blocks.in","r",stdin);
    freopen("blocks.out","w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
