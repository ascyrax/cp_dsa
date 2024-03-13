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

//...............................
char other(char c)
{
  vector<char> temp = {'a', 'b', 'c', 'd', 'e'};
  for (auto el : temp)
    if (el != c)
    {
      // cout << "c = " << c << endl;
      // cout << "el = " << el << endl;
      return el;
    }
}
//...............................

void suraj()
{
  int n, m;
  cin >> n >> m;
  string s, a;
  cin >> s >> a;

  int ptr = 0;
  map<int, int> loc;
  vector<bool> found(m, false);
  for (int i = 0; i < m; i++)
  {
    int el = a[i];
    for (; ptr < n; ptr++)
    {
      if (s[ptr] == el)
      {
        found[i] = true;
        loc[i] = ptr++;
        break;
      }
    }
    if (ptr == n)
      break;
  }
  if (loc.size() == m)
  {
    // subsequence found
    cout << -1 << endl;
    return;
  }
  for (int i = 0; i < m; i++)
  {
    if (found[i])
      continue;
    loc[i] = n;
  }
  int j = 0;
  for (int i = 0; i < m; i++)
  {
    for (; j < n && j < loc[i]; j++)
    {
      if (s[j] == '?')
      {
        s[j] = other(a[i]);
      }
    }
  }
  cout << s << endl;
}

//................................

// int

// int

// int

// int
