#include <bits/stdc++.h>
using namespace std;
vector<int> wordValue(vector <string> v){
    vector<int>vans;
  for(int i=0;i<int(v.size());i++){
    string a=v[i];
    int ans=0;
    for(int j=0;j<int(a.size());j++){
      char c=a[j];
      cout<<c<<" "<<int(c)<<endl;
    if(c>=97&&c<=122*-q ){
      ans=ans+(int(c)-96);
      cout<<"hi "<<ans<<endl;
    }
    }
    ans=ans*(i+1);
    vans.push_back(ans);
  }
  return vans;
}

int main(){
    vector<string>v={"codewars","abc","xyz"};
    auto ans=wordValue(v);
    for(int i:ans)cout<<i<<" ";cout<<endl;
    return 0;
}
