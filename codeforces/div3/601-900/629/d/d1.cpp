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

//.....................................

void suraj()
{
  int n;
  cin >> n;

  vector<int> v(n);
  map<int, int> cnt;
  for (int &i : v)
  {
    cin >> i;
    cnt[i]++;
  }

  for (auto el : cnt)
  {
    if (el.second == n)
    {
      cout << 1 << endl;
      for (int i : v)
        cout << 1 << " ";
      cout << endl;
      return;
    }
  }

  bool flag = true;
  int ref = v[0];
  for (int i = 1; i < n; i++)
  {
    if (v[i] != ref)
    {
      flag = !flag;
    }
    ref = v[i];
  }

  int ans = 0;
  if (flag == true && v[n - 1] != v[0])
  {
    ans = 3;
  }
  else
    ans = 2;

  // cout << "ans = " << ans << endl;

  // if ans==3
  // check if two or more than two similar nos exist or not.
  // bool flag2 = false;
  int ptr = -1;
  if (ans == 3)
    for (int i = 1; i < n; i++)
    {
      if (v[i] == v[i - 1])
      {
        // flag2 = true;
        ptr = i;
        ans = 2;
        break;
      }
    }

  // cout << "ptr = " << ptr << endl;

  vector<int> col(n);
  col[0] = 1;
  ref = v[0];
  int prevCol = 1;
  for (int i = 1; i < n; i++)
  {
    if (v[i] != ref || i == ptr)
    {
      if (prevCol == 1)
        prevCol = 2;
      else
        prevCol = 1;
      ref = v[i];
    }

    col[i] = prevCol;
  }

  if (ans == 3)
  {
    col[n - 1] = 3;
    int i = n - 2;
    while (1)
    {
      if (v[i] == v[n - 1])
        col[i] = 3;
      else
        break;
      i--;
    }
  }

  cout << ans << endl;
  for (int i : col)
    cout << i << " ";
  cout << endl;
}
