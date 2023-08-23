// @author: ascyrax

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long
#define pb push_back

void suraj();

signed main()
{

  ios::sync_with_stdio(false);
  cin.tie(0);

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
int mod = 1e9 + 7;
// int mod = 998244353;

void suraj()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int &i : a)
    cin >> i;
  for (int &i : b)
    cin >> i;

  multiset<int> msa;
  for (auto el : a)
    msa.insert(el);
  for (int i = 0; i < m; i++)
  {
    msa.erase(msa.begin());
    msa.insert(b[i]);
  }
  int sum = 0;
  for (auto el : msa)
    sum += el;
  cout << sum << endl;
}
