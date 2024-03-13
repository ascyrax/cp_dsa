///*
//ID: ascyrax1
//TASK: test
//LANG: C++14
//*/

//#include <bits/stdc++.h>
//using namespace std;

//typedef  long long ll;
//typedef long double ld;

//#define sz(x) (int)(x).size()
//#define endl "\n"
//#define ioss ios::sync_with_stdio(false);cin.tie(0);
//#define pb push_back

//double startTime;
//double gct()//get_current_time
//{
//    return ((double)clock()-startTime)/CLOCKS_PER_SEC;
//}
//void suraj();



























////   -----j-j-----   j
////   -----j-c-----   j

////------c-c----c
////------c-j----c




//void suraj(){///////////////////////

//int x,y;string s;cin>>x>>y>>s;
//int lens=int(s.size());
//char first;
//int pay=0;
//for(int i=0;i<lens;i++){
//    if(s[i]=='?')continue;
//    else{
//        first=s[i];
//    }
//}
//if(s[0]=='?'){
//    s[0]=first;
//}
//for(int i=1;i<lens;i++){
//    if(s[i]=='?'){
//        if(s[i-1]=='J')s[i]=s[i-1];
//        else if(s[i-1]=='C'){
//            if(i==lens-1){
//                s[i]=s[i-1];continue;
//            }else if(s[i+1]=='?'||s[i+1]=='C'){
//                s[i]=s[i-1];
//            }else if(s[i+1]=='J'){
//                s[i]=s[i-1];
//            }
//        }
//    }else{
//        if(s[i]=='C'&&s[i-1]=='J')pay+=y;
//        else if(s[i]=='J'&&s[i-1]=='C')pay+=x;
//    }
//}
////cout<<s<<endl;
//cout<<pay<<endl;















//}////////////////////////////

























//int main()
//{
//    startTime=(double)clock();
//    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
//    ioss
//    int t;cin>>t;for(int i=1;i<=t;i++){cout<<"Case #"<<i<<": ";
//    suraj();
//    }
//    return 0;
//}
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



























//   -----j-j-----   j
//   -----j-c-----   j

//------c-c----c
//------c-j----c


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



























//   -----j-j-----   j
//   -----j-c-----   j

//------c-c----c
//------c-j----c




void suraj(){///////////////////////

int x,y;string s;cin>>x>>y>>s;
if(x==0&&y==0){
    cout<<0<<endl;return;
}
int lens=int(s.size());
char first='?';
int pay=0;
int dist=0;
for(int i=0;i<lens;i++){
    if(s[i]=='?')continue;
    else{
        dist=i+1;
        first=s[i];break;
    }
}
int small=min(x,y);
int big=max(x,y);
int flag=0;
if(x<0||y<0){
    flag=-1;
}else{
    flag=1;
}
if(first=='?'){
    if(flag==-1){
        if(x*y>0){//both <0
            if(lens%2==0){
                pay+=(lens/2)*small;
                pay+=((lens/2)-1)*big;
            }else{
                pay=pay+(lens/2)*(big+small);
            }
        }else if(x*y==0){//big=0; and small<0
            pay+=(lens/2)*small;
        }else if(x*y<0){//big>0 and small<0
            if(abs(y)>=abs(x)){
                pay+=small;
            }else{
                if(lens%2==0){
                    pay+=(lens/2)*small;
                    pay+=(lens/2-1)*big;
                }else{
                    pay+=(lens/2)*(big+small);
                }
            }
        }
        cout<<pay<<endl;return;
    }else{//both>0
       cout<<pay<<endl;return;
    }
}
if(s[0]=='?'){
    if(flag==1)
    s[0]=first;
    else{

    }
}
for(int i=1;i<lens;i++){
    if(s[i]=='?'){
        if(s[i-1]=='J')s[i]=s[i-1];
        else if(s[i-1]=='C'){
            if(i==lens-1){
                s[i]=s[i-1];continue;
            }else if(s[i+1]=='?'||s[i+1]=='C'){
                s[i]=s[i-1];
            }else if(s[i+1]=='J'){
                s[i]=s[i-1];
            }
        }
    }else{
        if(s[i]=='C'&&s[i-1]=='J')pay+=y;
        else if(s[i]=='J'&&s[i-1]=='C')pay+=x;
    }
}
//cout<<s<<endl;
cout<<pay<<endl;















}////////////////////////////

























int main()
{
    startTime=(double)clock();
    //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    int t;cin>>t;for(int i=1;i<=t;i++){cout<<"Case #"<<i<<": ";
    suraj();
    }
    return 0;
}
