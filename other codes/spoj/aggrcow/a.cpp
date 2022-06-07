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
int n, c;
vector<int> stalls;
bool check(int midD)
{
  int last = stalls[0];
  int cowsCnt = 1;
  for (int i = 1; i < n; i++)
  {
    int diff = stalls[i] - last;
    if (diff >= midD)
    {
      last = stalls[i];
      cowsCnt++;
    }
  }
  if (cowsCnt >= c)
    return true;
  else
    return false;
}
//...............................

void suraj()
{
  cin >> n >> c;
  stalls = vector<int>(n);
  for (int &i : stalls)
    cin >> i;

  sort(stalls.begin(), stalls.end());

  int minD = 1, maxD = 1e9;

  while (minD < maxD)
  {
    int midD = minD + (maxD - minD) / 2;
    // cout << minD << " " << midD << " " << maxD << endl;
    if (check(midD))
    {
      if (minD == midD)
      {
        if (check(maxD))
        {
          minD = maxD;
        }
        break;
      }
      else
        minD = midD;
    }
    else
    {
      maxD = midD - 1;
    }
  }

  cout << minD << endl;
}

//................................

// int

// int

// int

// int
