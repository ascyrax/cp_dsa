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

  // ioss

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
  int mn = inf;
  int index = -1;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    if (v[i] < mn)
      index = i;
    mn = min(v[i], mn);
  }

  if (n % 2 == 1)
  {
    // next time joe will come to the first pile
    // mike wins cz he will make this pile = 0 in the first move
    cout << "Mike" << endl;
  }
  else
  {
    index++;
    if (index & 1)
      cout << "Joe" << endl;
    else
      cout << "Mike" << endl;
  }
  // int loopNo = mn + 1; // when the game will be decided.
  // int stonesRemoved = ((loopNo - 1) * n) + index;
  // // cout << "index = " << index << endl;
  // // cout << "loopNO = " << loopNo << endl;
  // // cout << "stonesRemoved = " << stonesRemoved << endl;
  // // person removing the (stonesRemoved+1)th stone will loose.
  // // viz person removing the (stonesRemoved)th stone wins
  // if (stonesRemoved & 1ll)
  //   cout << "Mike" << endl;
  // else
  //   cout << "Joe" << endl;
}
