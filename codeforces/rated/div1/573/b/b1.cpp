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
int mod = 1e9 + 7;
//.....................................

void print(string s, vector<int> v)
{
  cout << s << endl;
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
void print(string s, set<int> st)
{
  cout << s << endl;
  for (auto el : st)
    cout << el << " ";
  cout << endl;
}
//.....................................

//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> v(n);
  int pileSum = 0;
  map<int, int> m;
  for (int &i : v)
  {
    cin >> i;
    pileSum += i;
    m[i]++;
  }

  int cnt2 = 0, cntgt2 = 0;
  int repeatingVal = -1;
  for (auto el : m)
  {
    if (el.second > 2)
      cntgt2++;
    else if (el.second == 2)
    {
      cnt2++;
      repeatingVal = el.first;
    }
  }
  if (cntgt2 > 0)
  {
    // b wins
    cout << "cslnb" << endl;
    return;
  }
  else if (cnt2 > 1)
  {
    // b wins
    cout << "cslnb" << endl;
    return;
  }
  else if (cnt2 == 1)
  {
    if (repeatingVal == 0)
    {
      // b wins
      cout << "cslnb" << endl;
      return;
    }
    if (m[repeatingVal - 1] > 0)
    {
      // b wins
      cout << "cslnb" << endl;
      return;
    }
    else // do the normal thing
      ;
  }

  int sum = ((n - 1) * (n - 1 + 1)) / 2;

  int diff = pileSum - sum;

  // cout << "sum: " << sum << endl;
  // cout << "pileSum: " << pileSum << endl;
  // cout << "diff: " << diff << endl;
  if (diff % 2 == 0)
  {
    // b wins
    cout << "cslnb" << endl;
  }
  else
    cout << "sjfnb" << endl;
}
