// @author: ascyrax
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl "\n"
#define ioss                   \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define int long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front

double startTime;

double gct() // get_current_time
{
  return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

void suraj();

signed main()
{

  ioss

      // startTime=(double)clock();

      // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

      // cout << setprecision(15) << fixed;

      int t = 1;

  // cin>>t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}

//...............................
int n;
vector<int> a;
vector<int> b;

int sub(int l, int r)
{
  int cnt = 0;
  b[r] = -a[r];
  cnt++;
  for (int i = r - 1; i >= l; i--)
  {
    int prev = -b[i + 1];
    int curr = a[i];
    int q = (prev + a[i]) / a[i];
    cnt += q;
    b[i] = q * a[i] * -1;
  }
  return cnt;
}

int add(int l, int r)
{
  int cnt = 0;
  b[l] = a[l];
  cnt++;
  for (int i = l + 1; i <= r; i++)
  {
    int prev = b[i - 1];
    int curr = a[i];
    int q = (prev + a[i]) / a[i];
    cnt += q;
    b[i] = q * a[i];
  }
  return cnt;
}
//...............................

void suraj()
{
  cin >> n;
  a = vector<int>(n);
  b = vector<int>(n);
  for (int &i : a)
    cin >> i;

  int nSteps = 1e18;

  // // elements of b>0
  // b = a;
  // for(int i=1;i<n;i++){
  //   int diff
  // }

  // // elements of b<0

  // If i add ai to bi at the ith position then for all i>this position, i will have to add ai to bi. and for all i < this position, i could have subtracted ai from bi.

  for (int i = 0; i <= n - 1; i++)
  {
    b = a;
    int subCnt = 0, addCnt = 0;
    if (i - 1 >= 0)
      subCnt = sub(0, i - 1);
    // b[i] will remain = 0 .
    if (i + 1 <= n - 1)
      addCnt = add(i + 1, n - 1);
    // cout << "i = " << i << endl;
    // cout << "addCnt = " << addCnt << endl;
    // cout << "subCnt = " << subCnt << endl;
    nSteps = min(nSteps, subCnt + addCnt);
  }

  cout << nSteps << endl;
}

//................................

// int

// int

// int

// int
