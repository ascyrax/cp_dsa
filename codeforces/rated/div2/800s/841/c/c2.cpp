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

  ioss

      // startTime=(double)clock();

      // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

      // cout << setprecision(15) << fixed;
      for (int i = 0; i * i <= 262143; i++) // 131071
  {
    squares.pb(i * i);
  }
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
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  vector<int> pXor(n + 1, 0);
  map<int, int> mpXor;
  mpXor[0]++;
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    pXor[i] = pXor[i - 1] ^ v[i - 1];
    // print("pxor[i]", pXor[i]);
    ans += i;
    // cout << "ans a " << ans << endl;
    for (int j = 0; j < squares.size(); j++)
    {
      int square = squares[j];
      int pXorReq = square ^ pXor[i];
      // if (pXorReq < 10)
      //   cout << pXorReq << endl;
      if (mpXor.count(pXorReq) > 0)
      {
        // cout << "pXorReq found " << pXorReq << endl;
        ans -= mpXor[pXorReq];
        // cout << "ans b " << ans << endl;
      }
    }
    mpXor[pXor[i]]++;
    // print("ans c ", ans);
    // cout << "---" << endl;
  }

  cout << ans << endl;
}
