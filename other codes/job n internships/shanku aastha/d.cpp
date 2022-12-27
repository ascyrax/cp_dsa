// @author: ascyrax

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

#define pb push_back

int counter = 2;

int find(vector<int> memory, int len)
{
  int nZeros = 0;
  for (int i = 0; i < memory.size(); i++)
  {
    if (memory[i] == 0)
      nZeros++;
    else
      nZeros = 0;
    if (nZeros == len)
    {
      return i - (len - 1);
    }
  }
  return -1;
}
int erase(vector<int> memory, int id)
{
  for (int i = 0; i < memory.size(); i++)
  {
    if (memory[i] == id)
    {
      int cnt = 0;
      for (int j = i; j < memory.size(); j++)
      {
        if (memory[j] == id)
          cnt++;
        else
          break;
      }
      return cnt;
    }
  }
  return -1;
}

vector<int> solution(vector<int> memory, vector<vector<int>> queries)
{

  vector<int> ans;
  for (int i = 0; i < queries.size(); i++)
  {
    int a = queries[i][0];
    int b = queries[i][1];
    if (a == 0)
    {
      int index = find(memory, b);
      ans.pb(index);
      if (index != -1)
      {
        for (int j = index; j <= index + b - 1; j++)
          memory[j] = counter;
        counter++;
      }
    }
    else if (a == 1)
    {
      b++;
      int cnt = erase(memory, b);
      ans.pb(cnt);
    }
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> memory(n);
  for (int &i : memory)
    cin >> i;

  vector<vector<int>> queries;
  int q;
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    int a, b;
    cin >> a >> b;
    vector<int> temp;
    temp.pb(a);
    temp.pb(b);
    queries.pb(temp);
  }
  vector<int> ans = solution(memory, queries);
  for (auto el : ans)
    cout << el << " ";
  cout << endl;
  return 0;
}