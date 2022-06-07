#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define size(x) (int)(x).size()
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
        int r, c;
        cin >> r >> c;
        int flag1 = 0, flag2 = 0;
        // if first 1 is at row1col1
        for (int i = 1; i <= c; i++)
        {
                if (i % 2 == 1)
                {
                        flag1++;
                }
                else
                        // cout << "0";
                        ;
        }
        // cout << endl;
        for (int i = 2; i < r; i++)
        {
                if (i % 2 == 0)
                {
                        for (int j = 1; j <= c; j++)
                                // cout << "0";
                                ;
                }
                else
                {
                        for (int j = 1; j <= c; j++)
                        {
                                if (j == 1 || j == c)
                                        flag1++;
                                else
                                        // cout << "0";
                                        ;
                        }
                }
                // cout << endl;
        }
        if (r % 2 == 0)
        {
                for (int i = 1; i <= c; i++)
                {
                        if (i <= 2)
                                // cout << "0";
                                ;
                        else if (i >= c - 1)
                                // cout << "0";
                                ;
                        else
                        {
                                if (i % 2 == 1)
                                        flag1++;
                        }
                }
        }
        else
        {
                for (int i = 1; i <= c; i++)
                {
                        if (i % 2 == 1)
                                flag1++;
                        else
                                // cout << "0";
                                ;
                }
        }
        // for 1 starting with row1col2
        for (int i = 1; i <= c; i++)
        {
                if (i % 2 == 0)
                {
                        flag2++;
                }
                else
                        // cout << "0";
                        ;
        }
        // cout << endl;
        for (int i = 2; i < r; i++)
        {
                if (i % 2 == 0)
                {
                        for (int j = 1; j <= c; j++)
                                // cout << "0";
                                ;
                }
                else
                {
                        for (int j = 1; j <= c; j++)
                        {
                                if (j == 1 || j == c)
                                        flag2++;
                                else
                                        // cout << "0";
                                        ;
                        }
                }
                // cout << endl;
        }
        if (r % 2 == 0)
        {
                for (int i = 1; i <= c; i++)
                {
                        if (i <= 2)
                                // cout << "0";
                                ;
                        else if (i >= c - 1)
                                // cout << "0";
                                ;
                        else
                        {
                                if (i % 2 == 1)
                                        flag2++;
                        }
                }
        }
        else
        {
                for (int i = 1; i <= c; i++)
                {
                        if (i % 2 == 1)
                                flag2++;
                        else
                                // cout << "0";
                                ;
                }
        }
        // cout << endl;
        if (flag1 > flag2)
        {
                for (int i = 1; i <= c; i++)
                {
                        if (i % 2 == 1)
                        {
                                cout << "1";
                        }
                        else
                                cout << "0";
                }
                cout << endl;
                for (int i = 2; i < r; i++)
                {
                        if (i % 2 == 0)
                        {
                                for (int j = 1; j <= c; j++)
                                        cout << "0";
                        }
                        else
                        {
                                for (int j = 1; j <= c; j++)
                                {
                                        if (j == 1 || j == c)
                                                cout << "1";
                                        else
                                                cout << "0";
                                }
                        }
                        cout << endl;
                }
                if (r % 2 == 0)
                {
                        for (int i = 1; i <= c; i++)
                        {
                                if (i <= 2)
                                        cout << "0";

                                else if (i >= c - 1)
                                        cout << "0";
                                else
                                {
                                        if (i % 2 == 1)
                                                cout << "1";
                                        else
                                                cout << "0";
                                }
                        }
                }
                else
                {
                        for (int i = 1; i <= c; i++)
                        {
                                if (i % 2 == 1)
                                        cout << "1";
                                else
                                        cout << "0";
                        }
                }
                cout << endl;
        }
        else
        {
                for (int i = 1; i <= c; i++)
                {
                        if (i % 2 == 0)
                        {
                                cout << "1";
                        }
                        else
                                cout << "0";
                }
                cout << endl;
                for (int i = 2; i < r; i++)
                {
                        if (i % 2 == 0)
                        {
                                for (int j = 1; j <= c; j++)
                                        cout << "0";
                        }
                        else
                        {
                                for (int j = 1; j <= c; j++)
                                {
                                        if (j == 1 || j == c)
                                                cout << "1";
                                        else
                                                cout << "0";
                                }
                        }
                        cout << endl;
                }
                // cout << "last line" << endl;
                if (r % 2 == 0)
                {
                        // cout << "if r%2==0" << endl;
                        for (int i = 1; i <= c; i++)
                        {
                                if (i <= 2 || i >= c - 1)
                                        cout << "0";
                                else
                                {
                                        if (i % 2 == 1)
                                                cout << "1";
                                        else
                                                cout << "0";
                                }
                        }
                }
                else
                {
                        // cout << "else" << endl;
                        for (int i = 1; i <= c; i++)
                        {
                                if (i % 2 == 1)
                                        cout << "1";
                                else
                                        cout << "0";
                        }
                }
                cout << endl;
        }
}

//................................
