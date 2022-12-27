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

  // cin>>t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}

//...............................

//...............................

void suraj()
{
  int n, k;
  cin >> n >> k;

  vector<int> a(n), b(n);
  for (int &i : a)
    cin >> i;
  for (int &i : b)
    cin >> i;

  multiset<pair<double, pair<int, int>>> q;

  for (int i = 0; i < n; i++)
  {
    q.insert(make_pair(b[i] / (double)a[i], make_pair(b[i], a[i])));
  }

  while (k)
  {
    auto top = *(q.begin());
    // cout << "top" << endl;
    // cout << top.first << " " << top.second.first << " " << top.second.second << endl;
    // q.pop();
    q.erase(q.begin());
    top.second.first += 1;
    k--;
    top.first = top.second.first / (double)top.second.second;
    q.insert(top);
  }
  cout << (int)((*q.begin()).first) << endl;
}

//................................

// int

// int

// int

// int
