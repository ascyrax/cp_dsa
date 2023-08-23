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
vector<int> squares; // perfect squares => numbers with odd no of divisors

signed main()
{

  for (int i = 0; i * i <= 262144; i++) // 131071
    squares.pb(i * i);

  int t = 1;

  cin >> t;

  for (int i = 1; i <= t; i++)
    suraj();

  return 0;
}

//.....................................

int inf = 1e18;
int mod = 1e9 + 7;
// int mod = 998244353;
//.....................................

//.....................................
void print(string s, int n)
{
  cout << s << " " << n << endl;
}
//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> v(n);
  int mx = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    mx = max(mx, v[i]);
  }
  int mxXorSumPossible = 1;
  while (mxXorSumPossible <= mx)
    mxXorSumPossible *= 2;
  // now any xorSum < mxXorSumPossible

  vector<int> pXor(n + 1, 0);
  unordered_map<int, int> mpXor;
  // vector<int> mpXor(263000, 0);
  // vector<int> mpXor(2 * 262144, 0);
  // xor ^ sth = 262144 max lets say, then sth can be = 2*262144
  mpXor[0]++;
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    pXor[i] = pXor[i - 1] ^ v[i - 1];
    ans += i;
    for (int j = 0; j < squares.size(); j++)
    {
      int square = squares[j];
      if (square > mxXorSumPossible)
        break;
      int pXorReq = square ^ pXor[i];
      ans -= mpXor[pXorReq];
    }
    mpXor[pXor[i]]++;
  }

  cout << ans << endl;
}
