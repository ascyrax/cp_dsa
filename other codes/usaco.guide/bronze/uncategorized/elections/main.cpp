#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int main()
{
    int n;cin>>n;
    string s;cin>>s;
    int lens=n;
    int temp=-1;
    for(int i=0;i<lens;i++){
        if(s[i]=='-'){
            temp=i;
        }else{
            break;
        }
    }
    int a=0;
    int b=0;
    if(temp>=0){
    if(s[temp+1]=='A'){
        a=temp+1;
    }
    }
    if(temp>=0)
        s=s.substr(temp+1);
    temp=-1;
    lens=s.size();
    //
    //cout<<s<<endl;
    for(int i=lens-1;i>=0;i--){
        if(s[i]=='-'){
            temp=i;
        }else{
            break;
        }
    }
    //cout<<temp<<endl;
    if(temp>=0){
        if(s[temp-1]=='B'){
            b+=lens-temp;
        }
    }
    if(temp>=0)
        s=s.substr(0,temp);
    //
    //cout<<s<<endl;cout<<a<<" "<<b<<endl;
    lens=s.size();
    int l=-1;
    int r=-1;
    for(int i=0;i<lens;i++){
        if(l==-1&&s[i]=='-'){
            l=i;
        }else if(l>-1&&s[i]!='-'){
            if(s[i]=='A')a++;
            else b++;
            r=i-1;
            string x=s.substr(l,r-l+1);
            if(s[l-1]=='A'){
                if(s[r+1]=='A'){
                    a+=x.size();
                }else{
                    ;
                }
            }else if(s[l-1]=='B'){
                if(s[r+1]=='B'){
                    b+=x.size();
                }else{
                    a+=(x.size())/2;
                    b+=(x.size())/2;
                }
            }

            l=-1;r=-1;
        }else if(s[i]=='A'){
            a++;
        }else if(s[i]=='B'){
            b++;
        }
    }
    //cout<<a<<" "<<b<<endl;
    if(a>b)cout<<"A"<<endl;
    else if(a<b)cout<<"B"<<endl;
    else cout<<"Coalition government"<<endl;

    return 0;
}
