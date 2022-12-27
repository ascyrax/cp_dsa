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

//...............................

void suraj()
{
  int m, s;
  cin >> m >> s;

  if (s == 0)
  {
    if (m == 1)
      cout << 0 << " " << 0 << endl;
    else
      cout << -1 << " " << -1 << endl;
    return;
  }

  vector<int> bg(m, 0);
  int left = 0;

  int scopy = s;
  // for greatest m-digit no with sum of digits = s
  int biggest = 0;
  while (s)
  {
    if (bg[left] < 9)
    {
      s--;
      bg[left]++;
    }
    else
    {
      left++;
    }
    if (left == m && s > 0)
    {
      biggest = -1;
      break;
    }
  }

  // for smallest m-digit no with sum of digits =s.
  int smallest = 0;
  vector<int> sm(m, 0);
  sm[0] = 1;
  s = scopy;
  s--;
  int right = m - 1;
  while (s)
  {
    if (sm[right] < 9)
    {
      sm[right]++;
      s--;
    }
    else
    {
      right--;
    }
    if (right == -1 && s > 0)
    {
      smallest = -1;
      break;
    }
  }

  if (smallest == -1)
  {
    cout << -1 << " ";
  }
  else
  {
    for (int el : sm)
      cout << el << "";
    cout << " ";
  }

  if (biggest == -1)
    cout << -1 << endl;
  else
  {
    for (int el : bg)
      cout << el << "";
    cout << endl;
  }
}

//................................