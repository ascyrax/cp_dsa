#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define endl "\n"
#define ioss                         \
        ios::sync_with_stdio(false); \
        cin.tie(0);
#define pb push_back

double startTime;
double gct() //get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        ioss int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;

//...............................

void suraj()
{
        int n;
        cin >> n;
        int c1 = n / 3;
        int c2 = n / 3;
        if (n % 3 == 0)
        {
                ;
        }
        else if (n % 3 == 1)
        {
                c1++;
        }
        else
        {
                c2++;
        }
        cout << c1 << " " << c2 << endl;
}

//................................
