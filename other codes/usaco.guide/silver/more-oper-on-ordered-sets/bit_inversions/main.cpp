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

string bit;cin>>bit;
int m;cin>>m;
int len=int(bit.size());
multiset<int>mslength;
set<int>sends;

sends.insert(0);
for(int i=1;i<int(bit.size());i++){
    if(bit[i]==bit[i-1]){
        ;
    }else{
        mslength.insert(i-*(--sends.end()));
        sends.insert(i-1);sends.insert(i);
    }
}/////////////2 possible cases.......1111011111/000010000 and 11110000/00001111
sends.insert(len-1);
mslength.insert(len-*(--sends.end()));



for(int i=0;i<m;i++){
    int pos;cin>>pos;
    pos--;
////    cout<<typeid(!(bit[pos]-'0')).name()<<endl;
//    cout<<bit[pos]<<" ";
//    bit[pos]=!(bit[pos]-'0');
//    cout<<bit[pos]<<" "<<bit<<endl;
//    if(bit[pos]=='0')bit[pos]='1';
//    else bit[pos]='0';
//    cout<<bit<<endl;
    int left=0,right=0;
    if(*sends.lower_bound(pos)==pos){
        if(pos==len-1){

        }else if(pos==0){

        }else if(bit[pos-1]==bit[pos+1]){

        }else if(bit[pos]==bit[pos-1]){

        }else if(bit[pos]==bit[pos+1]){

        }
    }else{
        left=pos-*(--sends.lower_bound(pos));
        right=*(sends.lower_bound(pos))-pos;
        mslength.insert(left);mslength.insert(right);
        mslength.erase(mslength.find(right-left));
    }
    if(*--sends.lower_bound(pos)==*++sends.lower_bound(pos)){
        sends.insert(pos-1);sends.insert(pos);sends.insert(pos+1);
    }else{
        sends.insert(pos+1);sends.erase(sends.find(pos-1));
    }

}















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
