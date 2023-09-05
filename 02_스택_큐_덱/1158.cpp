#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void printAns(vector<int> ans)
{
    if (ans.size() == 1)
    {
        cout << "<" << ans[0] << ">";
        return;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == 0)
        {
            cout << "<" << ans[i] << ", ";
        }
        else if (i == ans.size() - 1)
        {
            cout << ans[i] << ">";
        }
        else
        {
            cout << ans[i] << ", ";
        }
    }
    return;
}

void josephus(queue<int> qu, int k)
{
    vector<int> ans;

    while (!qu.empty())
    {
        for (int i = 0; i < k - 1; i++)
        {
            qu.push(qu.front());
            qu.pop();
        }
        ans.push_back(qu.front());
        qu.pop();
    }
    printAns(ans);
    return;
}

int main()
{
    int n, k;
    queue<int> qu;

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        qu.push(i);
    }
    josephus(qu, k);
    return 0;
}