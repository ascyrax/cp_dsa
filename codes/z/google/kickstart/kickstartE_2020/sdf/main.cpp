#include <iostream>

using namespace std;

int main()
{

    int p;cin>>p;
    int cnt=0;
    int i=0;
    while(cnt<p){
           if((5*i+2)%4==0){
               i++;
           }else{
               cout<<5*i+2<<endl;
               cnt++;i++;
           }
    }



    return 0;
}
