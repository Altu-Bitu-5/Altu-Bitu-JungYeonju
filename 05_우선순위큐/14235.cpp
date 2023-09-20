#include <iostream>
#include <queue>

using namespace std;

struct cmp
{
    bool operator()(int a, int b)
    {
        return a < b;
    };
};

int main()
{
    int n, a, value;
    priority_queue<int, vector<int>, cmp> pq;

    cin >> n;
    while (n--)
    {
        cin >> a;

        if (a == 0)
        {
            if (pq.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            cout << pq.top() << "\n";
            pq.pop();
            continue;
        }
        while (a--)
        {
            cin >> value;
            pq.push(value);
        }
    }
    return 0;
}