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
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> vpa(n);

  vector<int> a(n);
  for (int &i : a)
    cin >> i;
  int k;
  cin >> k;
  vector<pair<int, int>> vpb(k);
  vector<int> b(k);
  for (int &i : b)
    cin >> i;

  int diff = abs(k - n);
  if (diff % (abs(m - 1)) != 0)
  {
    cout << "NO" << endl;
    return;
  }

  for (int i = 0; i < n; i++)
  {
    int first = a[i];
    int second = 1;
    while (first % m == 0)
    {
      second *= m;
      first /= m;
    }
    vpa[i] = make_pair(first, second);
  }

  for (int i = 0; i < k; i++)
  {
    int first = b[i];
    int second = 1;
    while (first % m == 0)
    {
      second *= m;
      first /= m;
    }
    vpb[i] = make_pair(first, second);
  }

  // cout << "vpa" << endl;
  // for (auto el : vpa)
  // {
  //   cout << el.first << " " << el.second << "  ,  ";
  // }
  // cout << endl;
  // cout << "vpb" << endl;
  // for (auto el : vpb)
  // {
  //   cout << el.first << " " << el.second << "  ,  ";
  // }
  // cout << endl;

  int ptrA = 0, ptrB = 0;

  for (ptrA = 0; ptrA < n; ptrA++)
  {
    if (ptrB > k)
    {
      cout << "NO" << endl;
      return;
    }
    if (vpa[ptrA].first != vpb[ptrB].first)
    {
      cout << "NO" << endl;
      return;
    }
    else
    {
      // both pairs have equal first element
      while (vpa[ptrA].second > 0)
      {
        if (ptrB > k)
        {
          cout << "NO" << endl;
          return;
        }
        if (vpb[ptrB].first != vpa[ptrA].first)
        {
          cout << "NO" << endl;
          return;
        }

        if (vpa[ptrA].second > vpb[ptrB].second)
        {
          vpa[ptrA].second -= vpb[ptrB].second;
          vpb[ptrB].second = 0;
          ptrB++;
        }
        else if (vpa[ptrA].second < vpb[ptrB].second)
        {
          vpb[ptrB].second -= vpa[ptrA].second;
          vpa[ptrA].second = 0;
          break; // top for loop will increase ptrA
        }
        else if (vpa[ptrA].second == vpb[ptrB].second)
        {
          vpa[ptrA].second = 0;
          vpb[ptrB].second = 0;
          ptrB++;
          break;
        }
      }
    }
  }
  if (ptrA == n)
  { // which is obviously the case if we are at this line
    if (ptrB < k)
    {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}
