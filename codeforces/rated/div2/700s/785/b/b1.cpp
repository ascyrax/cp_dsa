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
  string s;
  cin >> s;
  int lens = s.size();

  set<int> sAlpha;
  for (char el : s)
    sAlpha.insert(el);
  vector<char> alpha;
  for (char el : sAlpha)
    alpha.pb(el);

  int lenalpha = alpha.size();

  for (int i = 0; i < lenalpha; i++)
  {
    for (int j = i + 1; j < lenalpha; j++)
    {
      char c1 = alpha[i], c2 = alpha[j];
      int sum = 0, mxSum = 0, mnSum = 0;
      for (int i = 0; i < lens; i++)
      {
        if (s[i] == c1)
          sum++;
        else if (s[i] == c2)
          sum--;
        // if (sum)
        mnSum = min(sum, mnSum);
        mxSum = max(sum, mxSum);
      }
      // cout << c1 << " " << c2 << endl;
      // cout << mxSum - mnSum << endl;
      if (abs(mxSum - mnSum) > 1)
      {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
}
