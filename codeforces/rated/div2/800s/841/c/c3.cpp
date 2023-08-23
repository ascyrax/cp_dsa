// @author: ascyrax

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long
#define pb push_back

void suraj();

vector<int> squares; // perfect squares => numbers with odd no of divisors

signed main()
{

  ios::sync_with_stdio(false);
  cin.tie(0);

  // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

  // cout << setprecision(15) << fixed;

  for (int i = 0; i * i <= 262144; i++) // 131071
    squares.pb(i * i);

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
int mod = 1e9 + 7;
// int mod = 998244353;
// vector<int> mpXor(2 * 262144 + 1, 0); // even this wont work becz mpXor.clear() => size of mpXor = 0 now.

void suraj()
{
  // mpXor.clear();
  cout << mpXor.size() << endl;
  for (int i = 0; i < 10; i++)
    cout << mpXor[i] << " ";
  cout << endl;
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
  // unordered_map<int, int> mpXor;
  // vector<int> mpXor(263000, 0);
  vector<int> mpXor(2 * 262144 + 1, 0);
  // vector<int> mpXor(2 * mxXorSumPossible + 1, 0);
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
