#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
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
        string s;
        cin >> s;
        int lens = int(s.size());
        string ref = "abcdefghijklmnopqrstuvwxyz";
        string scopy = s;
        sort(scopy.begin(), scopy.end());
        if (ref.substr(0, lens) != scopy)
        {
                // cout << "if a" << endl;
                cout << "NO" << endl;
                return;
        }
        else
        {
                // cout << "else a" << endl;
                int pl = 0, pr = 0, pa = 0;
                int flag = 1;
                for (int i = 0; i < lens; i++)
                {
                        if (s[i] == 'a')
                        {
                                pa = i;
                                pl = i - 1;
                                pr = i + 1;
                                break;
                        }
                }
                int lengthTraversed = 1;
                while (lengthTraversed < lens)
                {
                        if (pl >= 0 && s[pl] == ref[lengthTraversed])
                        {
                                // cout << "if b" << endl;
                                pl--;
                                lengthTraversed++;
                        }
                        else if (pr < lens && s[pr] == ref[lengthTraversed])
                        {
                                // cout << "else if b" << endl;
                                pr++;
                                lengthTraversed++;
                        }
                        else
                        {
                                // cout << "else b" << endl;
                                cout << "NO" << endl;
                                return;
                        }
                }
                if (lengthTraversed == lens)
                        cout << "YES" << endl;
                else
                        cout << "NO" << endl;
        }
}

//................................
