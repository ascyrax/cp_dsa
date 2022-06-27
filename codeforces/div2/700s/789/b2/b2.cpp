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
void print(string s, vector<int> v)
{
  cout << "----" << endl;
  cout << s << endl;
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    v[i] = s[i] - '0';
  }

  print("v", v);
  int cnt = 1;
  vector<int> segSizes;
  for (int i = 1; i < n; i++)
  {
    if (v[i] == v[i - 1])
    {
      cnt++;
    }
    else
    {
      segSizes.pb(cnt);
      cnt = 1;
    }
  }
  segSizes.pb(cnt);

  vector<int> ps(segSizes.size());
  ps[0] = segSizes[0];
  for (int i = 1; i < segSizes.size(); i++)
    ps[i] = ps[i - 1] + segSizes[i];

  vector<int> temp(segSizes.size());
  for (int i = 0; i < ps.size(); i++)
  {
    temp[i] = v[ps[i] - 1];
  }

  int nOper = 0;

  print("segSizes", segSizes);
  print("temp", temp);

  vector<int> v3;
  for (int i = 1; i < segSizes.size(); i++)
  {
    if ((segSizes[i] & 1) == (segSizes[i - 1] & 1) && ((segSizes[i] & 1) == 1) && (temp[i] == temp[i - 1]))
    {
      // cout << "i = " << i << endl;
      int mn = min(segSizes[i], segSizes[i - 1]);
      int mx = max(segSizes[i], segSizes[i - 1]);
      int mxPtr = i, mnPtr = i - 1;
      // find correct ptrs.
      if (segSizes[i] == mn)
      {
        mnPtr = i;
        mxPtr = i - 1;
      }
      else if (segSizes[i] == mx)
      {
        mxPtr = i;
        mnPtr = i - 1;
      }
      mn--;
      mx++;
      segSizes[mnPtr]--;
      segSizes[mxPtr]++;

      nOper++;
    }
    else
    {
      // do nothing
    }
  }
  print("segSizes", segSizes);

  // int tempSum = 0;
  // int parity = (segSizes[0] % 2);
  // for (int i = 0; i < segSizes.size(); i++)
  // {
  //   if ((segSizes[i] % 2) == parity)
  //   {
  //     tempSum += segSizes[i];
  //   }
  //   else
  //   {
  //     v3.pb(tempSum);
  //     tempSum = segSizes[i];
  //     parity = segSizes[i] % 2;
  //   }
  //   if (i == segSizes.size() - 1)
  //     v3.pb(tempSum);
  // }
  for (int i = 0; i < segSizes.size(); i++)
    v3.pb(segSizes[i]);

  print("v3", v3);

  // cout << "nOperations = " << nOper << endl;

  vector<int> v4;
  // in v3, count of odd elements is even in number.
  int lenv3 = v3.size();
  vector<int> flag(lenv3, 0);
  if (v3[0] % 2 == 0)
  {
    // left to right sweep
    for (int i = 1; i < lenv3 - 1; i++)
    {
      if (v3[i] % 2 == 0)
        continue;
      if (i + 1 < lenv3 && v3[i + 1] == 2 && flag[i] != 2)
      {
        v3[i]++;
        v3[i + 1]--;
        flag[i + 1] = 2;
      }
      else if (v3[i] == 1)
      {
        v3[i]--;
        v3[i + 1]++;
      }
      else if (v3[i + 1] == 1)
      {
        v3[i + 1]--;
        v3[i]++;
      }
      else
      {
        // this will cover the case when v3[i+1]=2. for which we need to distribue v3[i+1] between v3[i] and v3[i+2]
        v3[i]++;
        v3[i + 1]--;
      }
      nOper++;
    }
  }
  else if (v3[0] % 2 == 1)
  {
    if (v3[lenv3 - 1] % 2 == 0)
    {
      // right to left
      for (int i = lenv3 - 1; i > 0; i--)
      {
        if (i - 1 >= 0 && v3[i - 1] == 2 && flag[i] != 2)
        {
          v3[i]++;
          v3[i - 1]--;
          flag[i - 1] = 2;
        }
        else if (v3[i] % 2 == 0)
          continue;

        if (v3[i] == 1)
        {
          v3[i]--;
          v3[i - 1]++;
        }
        else if (v3[i - 1] == 1)
        {
          v3[i - 1]--;
          v3[i]++;
        }
        else
        {
          // this will cover the case when v3[i+1]=2. for which we need to distribue v3[i+1] between v3[i] and v3[i+2]
          v3[i]++;
          v3[i - 1]--;
        }
        nOper++;
      }
    }
    else if (v3[lenv3 - 1] % 2 == 1)
    {
      for (int i = 0; i < lenv3 - 1; i++)
      {
        if (v3[i] % 2 == 0)
          continue;
        if (i + 1 < lenv3 && v3[i + 1] == 2 && flag[i] != 2)
        {
          v3[i]++;
          v3[i + 1]--;
          flag[i + 1] = 2;
        }
        else if (v3[i] == 1)
        {
          v3[i]--;
          v3[i + 1]++;
        }
        else if (v3[i + 1] == 1)
        {
          v3[i + 1]--;
          v3[i]++;
        }
        else
        {
          // this will cover the case when v3[i+1]=2. for which we need to distribue v3[i+1] between v3[i] and v3[i+2]
          v3[i]++;
          v3[i + 1]--;
        }
        nOper++;
      }
    }
  }
  print("v3", v3);
  vector<int> temp2;
  for (int i = 0; i < lenv3; i++)
  {
    if (v3[i] > 0)
    {
      v4.pb(v3[i]);
      temp2.pb(temp[i]);
    }
  }
  print("temp2", temp2);
  int nSegs = 1;
  for (int i = 1; i < temp2.size(); i++)
  {
    if (temp2[i] != temp2[i - 1])
      nSegs++;
  }
  // int cnt1 = 0, cnt0 = 0;
  // for (int i = 0; i < n; i++)
  // {
  //   if (v[i] == 1)
  //     cnt1++;
  //   else
  //     cnt0++;
  // }
  // if (nOper >= min(cnt0, cnt1))
  //   cout << nOper << " " << 1 << endl;
  // else
  cout << nOper << " " << nSegs << endl;
}
