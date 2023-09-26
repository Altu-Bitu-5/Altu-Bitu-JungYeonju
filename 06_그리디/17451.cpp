#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, tmp;
    vector<int> speed;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        speed.push_back(tmp);
    }

    long long earth_speed = speed[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (earth_speed % speed[i])
        {
            earth_speed = ((earth_speed / speed[i]) + 1) * speed[i];
        }
    }

    cout << earth_speed << "\n";
    return 0;
}