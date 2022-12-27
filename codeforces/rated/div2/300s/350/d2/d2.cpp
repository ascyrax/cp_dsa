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
  unsigned int n, k;
  cin >> n >> k;

  vector<unsigned int> a(n), b(n);
  for (unsigned int i = 0; i < n; i++)
    cin >> a[i];

  for (unsigned int i = 0; i < n; i++)
    cin >> b[i];

  vector<pair<double, unsigned int>> bbya(n);

  for (unsigned int i = 0; i < n; i++)
  {
    bbya[i] = make_pair(b[i] / (double)a[i], i);
  }
  sort(bbya.begin(), bbya.end());
  vector<double> copy(n);
  vector<unsigned int> copya(n), copyb(n);
  for (unsigned int i = 0; i < n; i++)
  {
    unsigned int ind = bbya[i].second;
    copya[i] = a[ind];
    copyb[i] = b[ind];
  }
  a = copya;
  b = copyb;

  vector<unsigned int> psa(n), psb(n);

  psa[0] = a[0];
  psb[0] = b[0];
  for (unsigned int i = 1; i < n; i++)
  {
    psa[i] = psa[i - 1] + a[i];
    psb[i] = psb[i - 1] + b[i];
  }

  for (unsigned int i = 0; i < n; i++)
    copy[i] = bbya[i].first;

  cout << "a" << endl;
  for (unsigned int i : a)
    cout << i << " ";
  cout << endl;
  cout << "b" << endl;
  for (unsigned int i : b)
    cout << i << " ";
  cout << endl;
  cout << "bbya" << endl;
  for (auto el : bbya)
    cout << el.first << " ";
  cout << endl;
  cout << "copy" << endl;
  for (auto el : copy)
    cout << el << " ";
  cout << endl;

  // unsigned int l = 0, r = 1e10;
  unsigned int l = 0, r = (psb[n - 1] + k) / psa[n - 1];
  // unsigned int l = 0, r = 1e7;
  while (l < r)
  {
    unsigned int m = l + (r - l) / 2;
    auto loc = lower_bound(copy.begin(), copy.end(), m) - copy.begin() - 1;
    unsigned int required = 0;
    if (loc > 0)
      required = psa[loc] * m;
    else
      required = 0;
    unsigned int present = 0;
    if (loc > 0)
      present = psb[loc];
    else
      present = 0;

    cout << l << " " << m << " " << r << endl;
    cout << required << " " << present << endl;

    if (required - present <= k)
    {
      cout << "if" << endl;
      if (l == m)
      {
        cout << "ifif" << endl;
        // check for r once.
        auto loc2 = lower_bound(copy.begin(), copy.end(), r) - copy.begin() - 1;
        unsigned int required2 = 0;
        if (loc2 > 0)
          required2 = psa[loc] * m;
        else
          required2 = 0;
        unsigned int present2 = 0;
        if (loc2 > 0)
          present2 = psb[loc];
        else
          present2 = 0;
        cout << required2 << " " << present2 << endl;
        if (required2 - present2 <= k)
        {
          cout << "ififif" << endl;
          l = r;
        }
        break;
      }
      else
      {
        cout << "ifelse" << endl;
        l = m;
      }
    }
    else
    {
      cout << "else" << endl;
      if (l == m)
      {
        cout << "elseif" << endl;
        r = l;
        break;
      }
      else
      {
        cout << "elseelse" << endl;
        r = m - 1;
      }
    }
  }
  cout << l << endl;

  cout << "==================================" << endl;

  for (unsigned int j = 104; j <= 105; j++)
  {
    int req = 0;
    for (int i = 0; i < n; i++)
    {
      req += max((unsigned long long)(0), (a[i] * j - b[i]));
    }
    cout << "req = " << req << endl;
  }
}

//................................