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
//cout<<"hi"<<endl;
int n;cin>>n;//cout<<"Hello"<<endl;
vector<int>v(n);for(int &i:v)cin>>i;
vector<int>ps(n);
ps[n-1]=v[n-1];//cout<<"Hello"<<endl;
for(int i=n-2;i>=0;i--){
    ps[i]=min(ps[i+1],v[i]);
}//cout<<"Hello"<<endl;
vector<int>psum(n+1);
for(int i=0;i<n;i++){
    psum[i+1]=psum[i]+v[i];
}
//cout<<"Hello"<<endl;
int avgmax=0;
vector<int>vk;
for(int k=1;k<=n-2;k++){
//    cout<<k<<endl;
    int left=k;
    int right=n-1;
    int minval=ps[k];
    int avg=(psum[n]-psum[k]-minval)/(right-left);
    vk.pb(avg);
    avgmax=max(avg,avgmax);//cout<<"k "<<k<<" "<<left<<" "<<right<<" "<<minval<<" "<<avg<<" "<<psum[n]-psum[k]-minval<<" "<<right-left<<endl;
}
//cout<<avgmax<<endl;
for(int i=0;i<n-2;i++){
    if(vk[i]==avgmax)cout<<i+1<<endl;
}
















}//




































int main()
{
    startTime=(double)clock();
    freopen("howework.in","r",stdin);
    freopen("homework.out","w",stdout);
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
//const int MAX_N = 100000;
//using namespace std;

//long long score[MAX_N+1];
//long long suffix_sum[MAX_N+1];
//long long suffix_min[MAX_N+1];
//long long best_num, best_den;

//int main(void)
//{
//  ifstream fin ("homework.in");
//  ofstream fout ("homework.out");

//  int N;

//  fin >> N;
//  for (int i=1; i<=N; i++)
//    fin >> score[i];

//  suffix_sum[N] = score[N];
//  suffix_min[N] = score[N];
//  for (int i=N-1; i>=1; i--) {
//    suffix_sum[i] = suffix_sum[i+1] + score[i];
//    suffix_min[i] = min(suffix_min[i+1], score[i]);
//  }

//  best_num = 0;
//  best_den = 1;

//  for (int i=1; i<=N-2; i++)
//    if ((suffix_sum[i+1]-suffix_min[i+1]) * best_den > best_num * (N-i-1)) {
//      best_num = suffix_sum[i+1]-suffix_min[i+1];
//      best_den = N-i-1;
//    }

//  for (int i=1; i<=N-2; i++)
//    if ((suffix_sum[i+1]-suffix_min[i+1]) * best_den == best_num * (N-i-1))
//      fout << i << "\n";

//  return 0;
//}
