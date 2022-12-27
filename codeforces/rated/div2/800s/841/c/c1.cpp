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
void print(string s, vector<pair<int, int>> vp)
{
  cout << s << endl;
  for (auto el : vp)
  {
    cout << el.first << " " << el.second << endl;
  }
}
int inf = 1e18;
int mod = 1e9 + 7;
// int mod = 998244353;
//.....................................

//.....................................
int countDivisors(int xorSum)
{
  int nDiv = 0;
  for (int i = 1; i * i <= xorSum; i++)
  {
    if (i * i == xorSum)
      nDiv--;
    if (xorSum % i == 0)
    {
      nDiv += 2; // i and xorSum/i
    }
  }

  return nDiv;
}
//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  vector<int> pXor(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    pXor[i] = pXor[i - 1] ^ v[i - 1];
  }
  print("pXor", pXor);
  vector<int> pEven(n + 1, 0), pOdd(n + 1, 0);
  // pEven[0] = 1;
  // pOdd[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    cout << "i " << i << " " << pXor[i] << endl;
    cout << countDivisors(pXor[i]) << endl;
    if (countDivisors(pXor[i]) % 2 == 0)
    {
      pEven[i] = pEven[i - 1] + 1;
      pOdd[i] = pOdd[i - 1];
    }
    else
    {
      pEven[i] = pEven[i - 1];
      pOdd[i] = pOdd[i - 1] + 1;
    }
  }
  print("pEven", pEven);
  print("pOdd", pOdd);
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    if (countDivisors(pXor[i]) % 2 == 0)
    {
      // substr 1...i is having an even xor
      ans += pEven[i];
    }
    else
    {
      ans += pOdd[i];
    }
  }
  cout << ans << endl;
}
