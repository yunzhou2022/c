#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<vector<int> > generate(int numRows)
{
  vector<vector<int> > res;
  for (int i = 0; i < numRows; i++)
  {
    vector<int> row(i + 1, 1); // Initialize the row with i+1 elements, all set to 1
    for (int j = 1; j < i; j++)
    {
      row[j] = res[i - 1][j - 1] + res[i - 1][j];
    }
    res.push_back(row); // Add the generated row to the result
  }
  return res;
}

int main()
{
  vector<vector<int> > res = generate(3);
  for (auto row : res)
  {
    for (auto col : row)
    {
      cout << col << ' ';
    }
    cout << endl;
  }

  return 0;
}
