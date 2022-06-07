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

double gct() // get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

void suraj();

int main()
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

//...............................

void suraj()
{
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> child(n + 1); // child of a node. ie  u->v.
        vector<int> parent(n + 1);

        child[0] = -1;
        parent[0] = -1;

        int left = -1;
        if (s[0] == 'R')
                left = 0;
        else
        {
                for (int i = 1; i <= n; i++)
                {
                        if (s[i - 1] == 'L')
                                left = i;
                        else
                                break;
                }
        }
        // cout << "left = " << left << endl;

        for (int i = 1; i <= n; i++)
        {
                if (s[i - 1] == 'L')
                {
                        if (parent[i - 1] != -1)
                        {
                                child[parent[i - 1]] = i;
                                parent[i] = parent[i - 1];
                                child[i] = i - 1;
                                parent[i - 1] = i;
                        }
                        else
                        {
                                child[i] = i - 1;
                                parent[i - 1] = i;
                                parent[i] = -1;
                        }
                }
                else
                {
                        int temp = child[i - 1];
                        child[i - 1] = i;
                        parent[i] = i - 1;
                        child[i] = temp;
                        if (temp != -1)
                                parent[temp] = i;
                }
        }
        while (left != -1)
        {
                cout << left << " ";
                left = child[left];
        }
        cout << endl;
}

//................................

// int

// int

// int

// int
