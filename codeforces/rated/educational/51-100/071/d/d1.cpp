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
int mod = 998244353;
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
//.....................................
int calcFact(int n)
{
  int result = 1;
  for (int i = 1; i <= n; i++)
  {
    result *= i;
    result %= mod;
  }
  return result;
}
//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<pair<int, int>> vp;
  vector<int> va, vb;
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    va.pb(a);
    vb.pb(b);
    vp.pb(make_pair(a, b));
  }
  sort(va.begin(), va.end());
  sort(vb.begin(), vb.end());
  sort(vp.begin(), vp.end());

  vector<int> temp;
  for (int i = 0; i < n; i++)
    temp.pb(vp[i].second);

  int flag = 1; // if flag=0 => cnt12 = 0 && flag=1 => cnt12>0
  if (temp == vb)
    flag = 1;
  else
    flag = 0;

  // print("va", va);
  // print("vb", vb);
  // print("vp", vp);

  int cnt1 = 1;          // no of permutations which make the pair bad becz of the first elements being in increasing order.
  int cnt2 = 1;          // no of permutations which make the pair bad becz of the second elements being in increasing order.
  int cnt12 = 1;         // no of permutations which meke the sequence bad becz of both the first and the second elements in increasing order.
  int ans = calcFact(n); // n! - cnt1 - cnt2 + cnt12
  int preva = va[0];
  int cnta = 1;
  for (int i = 1; i < n; i++)
  {
    if (va[i] == preva)
    {
      cnta++;
    }
    else
    {
      cnt1 *= calcFact(cnta);
      cnt1 %= mod;

      cnta = 1;
      preva = va[i];
    }
  }
  cnt1 *= calcFact(cnta);
  cnt1 %= mod;

  int prevb = vb[0];
  int cntb = 1;
  for (int i = 1; i < n; i++)
  {
    if (vb[i] == prevb)
      cntb++;
    else
    {
      cnt2 *= calcFact(cntb);
      cnt2 %= mod;

      cntb = 1;
      prevb = vb[i];
    }
  }
  cnt2 *= calcFact(cntb);
  cnt2 %= mod;

  preva = vp[0].first;
  prevb = vp[0].second;
  cnta = 1;
  cntb = 1;
  for (int i = 1; i < n; i++)
  {
    if (vp[i].first == preva)
    {
      cnta++;
    }
    else
    {
      int mn = min(cnta, cntb);
      cnt12 *= calcFact(mn);
      cnt12 %= mod;

      preva = vp[i].first;
      prevb = vp[i].second;
      cnta = 1;
      cntb = 1;
      continue;
    }

    if (vp[i].second == prevb)
    {
      cntb++;
    }
    else
    {
      int mn = min(cnta, cntb);
      cnt12 *= calcFact(mn);
      cnt12 %= mod;

      preva = vp[i].first;
      prevb = vp[i].second;
      cnta = 1;
      cntb = 1;
      continue;
    }
  }
  int mn = min(cnta, cntb);
  cnt12 *= calcFact(mn);
  cnt12 %= mod;

  // cout << ans << " " << cnt1 << " " << cnt2 << " " << cnt12 << endl;
  if (flag == 0)
    ans = ans - cnt1 - cnt2 + 0;
  else if (flag == 1)
    ans = ans - cnt1 - cnt2 + cnt12;
  while (ans < 0)
    ans += mod;
  ans %= mod;
  cout << ans << endl;

  // cout << "HI: " << -382086438 + mod << endl;
}
