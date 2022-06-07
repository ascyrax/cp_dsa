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



























void suraj(){



int n;cin>>n;
vector<string>is,s;
vector<int>ilow,low,ihigh,high;
for(int i=0;i<n;i++){
    string a;int b,c;
    cin>>a>>b>>c;
    is.pb(a);ilow.pb(b);ihigh.pb(c);
}
s.pb(is[0]);low.pb(ilow[0]);high.pb(ihigh[0]);
for(int i=1;i<n;i++){
    int lens=int(s.size());
    if(is[i]==s[lens-1]){
        if(is[i]=="on"||is[i]=="off"){
            low[lens-1]+=ilow[i];
            high[lens-1]+=ihigh[i];
//            s[lens-1]=is[i];
        }else if(is[i]=="none"){
            low[lens-1]=max(low[lens-1],ilow[i]);
            high[lens-1]=min(high[lens-1],ihigh[i]);
//            s[lens-1]=is[i];
        }
    }else{
        s.pb(is[i]);low.pb(ilow[i]);high.pb(ihigh[i]);
    }
}
//for(int i=0;i<s.size();i++)
//    cout<<s[i]<<" "<<low[i]<<" "<<high[i]<<endl;

int lowa,higha,lown,highn;
int tempa,tempb;
int a=0,b=0;
int ptra=0;
for(int i=0;i<int(s.size());i++){
    if(s[i]=="none"){
        ptra=i;break;
    }
}
lowa=low[ptra];higha=high[ptra];
for(int i=ptra-1;i>=0;i--){
    if(s[i]=="on"){
        lowa-=high[i];higha-=low[i];
        lowa=max(0,lowa);higha=max(0,higha);
    }else{
        lowa+=low[i];higha+=high[i];
    }
}
cout<<lowa<<" "<<higha<<endl;
//for(int i=0;i<int(s.size());i++){
//    if(s[i]=="on"){
//        a+=low[i];b+=high[i];
//    }else if(s[i]=="off"){
//        a-=high[i];b-=low[i];
////        a=max(0,a);b=max(0,b);
//    }else{
//        lowa=low[i]-b;
//        higha=high[i]-a;
//        break;
//    }
//}
//cout<<max(0,lowa)<<" "<<max(0,higha)<<endl;
int ptr=0;
for(int i=s.size()-1;i>=0;i--){
    if(s[i]=="none"){
        ptr=i;break;
    }
}
lown=low[ptr];highn=high[ptr];
for(int i=ptr+1;i<s.size();i++){
    if(s[i]=="on"){
        lown+=low[i];highn+=high[i];
    }else{//off
        lown-=high[i];highn-=low[i];
        lown=max(0,lown);highn=max(0,highn);
    }
}
cout<<max(0,lown)<<" "<<max(0,highn)<<endl;

















}//




































int main()
{
    startTime=(double)clock();
    freopen("traffic.in","r",stdin);
    freopen("traffic.out","w",stdout);
    ioss
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
//#include <iostream>
//#include <fstream>
//using namespace std;

//int main(void)
//{
//  int N, A[100], B[100];
//  string T[100];

//  ifstream fin ("traffic.in");
//  fin >> N;
//  for (int i=0; i<N; i++) fin >> T[i] >> A[i] >> B[i];

//  ofstream fout ("traffic.out");

//  int a = -999999999, b = 999999999;
//  for (int i=N-1; i>=0; i--) {
//    if (T[i] == "none") { a = max(a, A[i]); b = min(b, B[i]); }
//    if (T[i] == "off") { a += A[i]; b += B[i]; }
//    if (T[i] == "on") { a -= B[i]; b -= A[i]; a = max(0,a); }
//  }
//  fout << a << " " << b << "\n";

//  a = -999999999, b = 999999999;
//  for (int i=0; i<N; i++) {
//    if (T[i] == "none") { a = max(a, A[i]); b = min(b, B[i]); }
//    if (T[i] == "on") { a += A[i]; b += B[i]; }
//    if (T[i] == "off") { a -= B[i]; b -= A[i]; a = max(0,a); }
//  }
//  fout << a << " " << b << "\n";

//  return 0;
//}
