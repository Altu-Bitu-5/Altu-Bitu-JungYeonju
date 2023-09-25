#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct cmp
{
    bool operator()(int a, int b)
    {
        return a > b;
    };
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, cmp> pq;
    int n, k;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            pq.push(k);
        }

        while (pq.size() > n)
        {
            pq.pop();
        }
    }

    cout << pq.top();

    return 0;
}
