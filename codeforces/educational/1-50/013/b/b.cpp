// @author: ascyrax

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
        ioss
            startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //cout << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
//const int INF = 2147483647;
//const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide
bool isLeap(int year)
{
        if (year % 100 != 0)
        {
                if (year % 4 == 0)
                        return true;
                else
                        return false;
        }
        else
        {
                if (year % 400 == 0)
                        return true;
                else
                        return false;
        }
}
//...............................

//...............................

void suraj()
{
        int n;
        cin >> n;

        //find the next century year
        // int century = n;
        // if (century % 100 == 0)
        //         century += 100;
        // while (century % 100 != 0)
        // {
        //         century++;
        // }
        // int diff = century - n;

        // if (isLeap(n))
        // {
        //         // cout << "if" << endl;

        //         // cout << "diff = " << diff << endl;
        //         if (diff > 28)
        //         {
        //                 cout << n + 28 << endl;
        //         }
        //         else
        //         { //year 96 is similar to year 108 i.e. everything shifts by 12 yeears
        //                 cout << n + 28 + 12 << endl;
        //         }
        // }
        // else
        // {
        //         // // + 6 becz if current years first day is monday and if current year is also a leap year then
        //         // // the next years first day will be wednesday, not tuesday.
        //         // if (diff > 6)
        //         // {
        //         //         if (!isLeap(n + 6))
        //         //                 cout << n + 6 << endl;
        //         //         else
        //         //         {
        //         //                 cout << n + 6 + 5 << endl;
        //         //         }
        //         // }
        //         // else
        //         // {
        //         //         if (isLeap(century))
        //         //         {
        //         //                 cout << n + 6 + 5 << endl;
        //         //         }
        //         //         else
        //         //         {
        //         //                 cout << n + 6 << endl;
        //         //         }
        //         // }
        //
        // }
        int yearCurrent = n;
        int dayInitial = 0; // 0 1 2 3 4 5 6
        int dayCurrent = 0;
        while (true)
        {
                yearCurrent++;
                if (isLeap(yearCurrent))
                {
                        dayCurrent += 2;
                        dayCurrent %= 7;
                }
                else
                {
                        dayCurrent += 1;
                        dayCurrent %= 7;
                }
                if (isLeap(n))
                {
                        if (isLeap(yearCurrent) && (dayCurrent == dayInitial))
                        {
                                cout << yearCurrent << endl;
                                break;
                        }
                }
                else
                {
                        if (!isLeap(yearCurrent) && (dayCurrent == dayInitial))
                        {
                                cout << yearCurrent << endl;
                                break;
                        }
                }
        }
}

//................................
