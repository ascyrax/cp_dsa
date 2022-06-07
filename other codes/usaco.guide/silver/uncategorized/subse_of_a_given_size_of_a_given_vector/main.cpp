/*#include <iostream>
using namespace std;
void printSubset(int arr[], int n, int r, int index, int data[], int i);
int main(){
   int a;cin>>a;
   int arr[a];for(int i=0;i<a;i++)cin>>arr[i];
   int r;cin>>r;
   cout<<"The sets are : ";
   int n = sizeof(arr) / sizeof(arr[0]);
   int data[r];
   printSubset(arr, n, r, 0, data, 0);
   return 0;
}
void printSubset(int arr[], int n, int r, int index, int data[], int i){
    cout<<"in"<<" "<<index<<" ";for(int j=0;j<sizeof(data)/sizeof(data[0]);j++)cout<<data[j]<<" ";cout<<i<<endl;
   if (index == r) {
      for (int j = 0; j < r; j++)
         cout<<data[j]<<" ";
      cout<<endl;
      return;
   }
   if (i >= n)
      return;
   data[index] = arr[i];
   printSubset(arr, n, r, index + 1, data, i + 1);
   printSubset(arr, n, r, index, data, i + 1);
}
*/
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> v;
vector<vector<int> > result;

void subset(int arr[],int k,int n,int idx){
if(idx==n)
return;

if(k==1){
 for(int i=idx;i<n;i++)
  {
     v.push_back(arr[i]);
     result.push_back(v);
     v.pop_back();
  }
}

for(int j=idx;j<n;j++) {
v.push_back(arr[j]);
subset(arr,k-1,n,j+1);
v.pop_back();
}
}

int main(){
int arr[] = {1,2,3,4,5,6,7};
int k = 4;
int n =sizeof(arr)/sizeof(arr[0]);
subset(arr,k,n,0);

for(int i = 0;i<result.size();i++)
{
for(int j = 0;j<result[i].size();j++)
{
  cout << result[i][j] << " ";
}
cout << endl;
}
}
