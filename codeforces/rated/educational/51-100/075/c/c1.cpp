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
  string s;
  cin >> s;

  vector<int> even, odd;
  for (auto el : s)
  {
    if ((el - '0') % 2 == 0)
      even.pb(el - '0');
    else
      odd.pb(el - '0');
  }

  // cout << "even" << endl;
  // for (auto el : even)
  //   cout << el << " ";
  // cout << endl;
  // cout << "odd" << endl;
  // for (auto el : odd)
  //   cout << el << " ";
  // cout << endl;

  int ptrEven = 0, ptrOdd = 0;
  vector<int> ans;
  while (ptrEven < even.size() || ptrOdd < odd.size())
  {
    if (ptrEven >= even.size())
    {
      ans.pb(odd[ptrOdd++]);
    }
    else if (ptrOdd >= odd.size())
    {
      ans.pb(even[ptrEven++]);
    }
    else
    {
      if (even[ptrEven] < odd[ptrOdd])
      {
        ans.pb(even[ptrEven++]);
      }
      else
      {
        ans.pb(odd[ptrOdd++]);
      }
    }
  }
  for (auto el : ans)
    cout << el;
  cout << endl;
}
