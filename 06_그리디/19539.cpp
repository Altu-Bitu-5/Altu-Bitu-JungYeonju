#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, height;
    vector<int> tree;

    cin >> n;
    while (n--)
    {
        cin >> height;
        tree.push_back(height);
    }

    int odd = 0;
    int even = 0;

    for (int i = 0; i < tree.size(); i++)
    {
        odd += tree[i] % 2;
        even += tree[i] / 2;
    }

    even = even - odd;
    if (even < 0 || even % 3 != 0)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
    return 0;
}