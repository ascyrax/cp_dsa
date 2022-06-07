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

  // cin>>t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}

//...............................
int n, k;
vector<int> a, b;
vector<pair<double, int>> bbya;
vector<double> copybbya;
bool check(int m)
{
  auto loc = lower_bound(copybbya.begin(), copybbya.end(), m) - copybbya.begin();
  // every powder after the loc already has powder available for m cookies
  // cout << "loc = " << loc << endl;
  int suma = 0, sumb = 0;
  for (int i = 0; i < loc; i++)
  {
    suma += a[i];
    sumb += b[i];
  }
  if (sumb == 0)
    return true;
  // cout << suma << " " << sumb << " " << ((sumb + k) / suma) << endl;
  if ((sumb + k) / suma >= m)
    return true;
  else
    return false;
}
//...............................

void suraj()
{
  cin >> n >> k;
  a = vector<int>(n);
  b = vector<int>(n);

  bbya = vector<pair<double, int>>(n);

  int suma = 0, sumb = 0;
  for (int &i : a)
  {
    cin >> i;
    suma += i;
  }
  for (int &i : b)
  {
    cin >> i;
    sumb += i;
  }

  for (int i = 0; i < n; i++)
  {
    bbya[i] = make_pair(b[i] / (double)a[i], i);
  }

  sort(bbya.begin(), bbya.end());

  vector<int> copya, copyb;
  for (int i = 0; i < n; i++)
  {
    copybbya.pb(bbya[i].first);
    copya.pb(a[bbya[i].second]);
    copyb.pb(b[bbya[i].second]);
  }
  a = copya;
  b = copyb;

  int l = 0, r = (k + sumb) / suma;
  while (l < r)
  {
    int m = l + (r - l) / 2;
    // cout << l << " " << m << " " << r << endl;
    if (check(m))
    {
      if (l == m)
      {
        if (check(r))
          l = r;
        else
          l = l;
        break;
      }
      else
        l = m;
    }
    else
    {
      r = m - 1;
    }
  }

  cout << l << endl;
}

//................................