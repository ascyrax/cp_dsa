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
        ioss
            //cout << setprecision(15) << fixed << endl;
            int t;
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
const int inf = 2147483647;
const int ninf = -2147483647 - 1;
//...............................

//...............................

//...............................

void suraj()
{
        int k;
        cin >> k;
        string num;
        cin >> num;
        vector<int> count(10);
        for (int i = 0; i < k; i++)
        {
                int digit = num[i] - 48; // 0 =48 in ascii
                count[digit]++;
        }
        // for (int i : count)
        //         cout << i << " ";
        // cout << endl;
        if (count[1] + count[4] + count[6] + count[8] + count[9] > 0)
        {
                cout << 1 << endl;
                vector<int> temp = {1, 4, 6, 8, 9};
                for (int a : temp)
                {
                        // cout << a << " " << count[a] << endl;
                        if (count[a] > 0)
                        {
                                cout << a << endl;
                                return;
                        }
                }
        }
        else
        { // only 2,3,5 and 7 are present
                vector<int> temp = {2, 3, 5, 7};
                for (int t : temp)
                {
                        if (count[t] >= 2)
                        {
                                cout << 2 << endl;
                                cout << t << "" << t << endl;
                                return;
                        }
                }
                // if 2 similar are not present
                if (count[2] == 1 && count[5] == 1)
                {
                        cout << 2 << endl;
                        bool flag2 = true, flag5 = true;
                        for (int i = 0; i < k; i++)
                        {
                                if (flag2 && (num[i] - 48 == 2))
                                {
                                        cout << 2 << "";
                                        flag2 = false;
                                }
                                if (flag5 && (num[i] - 48 == 5))
                                {
                                        cout << 5 << "";
                                        flag5 = false;
                                }
                                if (flag2 == false && flag5 == false)
                                        break;
                        }
                        cout << endl;
                }
                else if (count[2] == 1 && count[7] == 1)
                {
                        cout << 2 << endl;
                        bool flag2 = true, flag7 = true;
                        for (int i = 0; i < k; i++)
                        {
                                if (flag2 && (num[i] - 48 == 2))
                                {
                                        cout << 2 << "";
                                        flag2 = false;
                                }
                                if (flag7 && (num[i] - 48 == 7))
                                {
                                        cout << 7 << "";
                                        flag7 = false;
                                }
                                if (flag2 == false && flag7 == false)
                                        break;
                        }
                        cout << endl;
                }
                else if (count[5] == 1 && count[7] == 1)
                {
                        cout << 2 << endl;
                        bool flag5 = true, flag7 = true;
                        for (int i = 0; i < k; i++)
                        {
                                if (flag5 && (num[i] - 48 == 5))
                                {
                                        cout << 5 << "";
                                        flag5 = false;
                                }
                                if (flag7 && (num[i] - 48 == 7))
                                {
                                        cout << 7 << "";
                                        flag7 = false;
                                }
                                if (flag5 == false && flag7 == false)
                                        break;
                        }
                        cout << endl;
                }
                else if (count[3] == 1 and count[5] == 1)
                {
                        cout << 2 << endl
                             << 35 << endl; //becz 53 ho hi nahi sakta warna no-prime ban hi nahi payega
                }
                else if (count[2] == 1 && count[3] == 1)
                {
                        cout << 2 << endl
                             << 32 << endl; //becz 23 ho hi nahi sakta warna no-prime ban hi nahi payega
                }
        }
}

//................................
