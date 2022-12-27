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

  // cin >> t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}

int inf = 1e18;
//.....................................

//.....................................
vector<int> v;

void print(vector<int> v)
{
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
//.....................................
int i = 0;
bool custom(int &a, int &b)
{
  cout << "i = " << i << endl;
  i++;
  cout << "a = " << a << " , b = " << b << endl;
  print(v);
  if (b < a)
    cout << "true => a & b will be swapped" << endl;
  return a < b; // => if true then the swap occurs.
}
//.....................................

void suraj()
{

  v = {2, 6, 5, 7, 3};

  cout << "v before sorting" << endl;
  print(v);

  sort(v.begin(), v.end(), custom);

  cout << "v" << endl;
  print(v);
}
