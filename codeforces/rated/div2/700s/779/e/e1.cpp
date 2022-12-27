#include <bits/stdc++.h>

using namespace std;

int main()
{

  int t;    // int means t will be an integer. and t is the no of cases
  cin >> t; // we input t.

  int a = 0;
  while (a < t) // till t is greater than zero, this while loop will run
  {
    int k, x; // k is the total volume of bucket. x is the filled volume.
    cin >> k >> x;

    cout << k - x << "\n";

    a++;
  }

  return 0;
}
