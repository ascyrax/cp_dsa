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

  cin >> t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}

//.....................................
void swap(int &a, int &b)
{
  int c = a;
  a = b;
  b = c;
  return;
}
//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  if (n & 1)
  {
    for (int i = 1; i < n; i += 2)
    {
      if (v[i] > v[i + 1])
      {
        swap(v[i], v[i + 1]);
      }
    }
  }
  else
  {
    for (int i = 0; i < n; i += 2)
    {
      if (v[i] > v[i + 1])
      {
        swap(v[i], v[i + 1]);
      }
    }
  }

  vector<int> temp = v;

  sort(temp.begin(), temp.end());
  if (temp == v)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
