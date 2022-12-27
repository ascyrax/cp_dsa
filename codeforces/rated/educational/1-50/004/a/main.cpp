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





























void suraj(){
int n,a,b;cin>>n>>a>>b;
string s;cin>>s;
if(n%a==0){
    cout<<n/a<<endl;
    int c=n/a;
    for(int i=0,j=0;j<c;j++,i+=a)cout<<s.substr(i,a)<<endl;

}
else if(n%b==0){
    cout<<n/b<<endl;
    int c=n/b;
    for(int i=0,j=0;j<c;j++,i+=b)cout<<s.substr(i,b)<<endl;


}
else if(n%(a+b)==0){
    cout<<2*n/(a+b)<<endl;
    int c=n/(a+b);
    int i=0;int j=0;
    for( i=0,j=0;j<c;i+=a,j++)cout<<s.substr(i,a)<<endl;
    for(j=0;j<c;j++,i+=b)cout<<s.substr(i,b)<<endl;
}
else{
    //int d=n%(a+b);
    for(int i=0;i<101;i++){
        if((n-a*i>0)&&(n-a*i)%b==0){
            int aa=i;int bb=(n-i*a)/b;
            int ptr=0;
            cout<<aa+bb<<endl;
            for(int k=0;k<aa;k++){
                cout<<s.substr(ptr,a)<<endl;ptr+=a;
            }
            for(int k=0;k<bb;k++){
                cout<<s.substr(ptr,b)<<endl;ptr+=b;
            }
            return;
        }
        else if((n-b*i)>0&&(n-b*i)%a==0){
            int bb=i;int aa=(n-i*b)/a;
            int ptr=0;
            cout<<aa+bb<<endl;
            for(int k=0;k<bb;k++){
                cout<<s.substr(ptr,b)<<endl;ptr+=b;
            }
            for(int k=0;k<aa;k++){
                cout<<s.substr(ptr,a)<<endl;ptr+=a;
            }
            return;

        }
    }
    cout<<-1<<endl;
}





}//
























int main()
{
    startTime=(double)clock();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt,"w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
