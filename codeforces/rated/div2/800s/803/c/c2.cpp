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

int inf = 1e18;
//.....................................

//.....................................

//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> v(n);

  int nPos = 0, nNeg = 0, nZer = 0;
  vector<int> pos, neg;
  map<int, int> m;
  int sum = 0;
  for (int &i : v)
  {
    cin >> i;
    m[i]++;
    if (i > 0)
    {
      nPos++;
      pos.pb(i);
    }
    else if (i < 0)
    {
      nNeg++;
      neg.pb(i);
    }
    else
      nZer++;
    sum += i;
  }

  sort(v.begin(), v.end());

  vector<int> v2;
  for (int &i : v)
  {
    if (i == 0)
      continue;
    else
      v2.pb(i);
  }
  if (nZer)
  {
    v2.pb(0);
  }
  sort(v2.begin(), v2.end());
  int lenv2 = v2.size();

  // cout << m[10] << " " << m[5] << " " << m[1] << endl;

  if (nPos >= 3 || nNeg >= 3)
  {
    cout << "NO" << endl;
    return;
  }
  else
  {
    for (int i = 0; i < lenv2; i++)
    {
      for (int j = i + 1; j < lenv2; j++)
      {
        for (int k = j + 1; k < lenv2; k++)
        {
          int sum = v2[i] + v2[j] + v2[k];
          // cout << "sum = " << sum << endl;
          if (m[sum] == 0)
          {
            cout << "NO" << endl;
            return;
          }
        }
      }
    }
  }
  cout << "YES" << endl;
}
