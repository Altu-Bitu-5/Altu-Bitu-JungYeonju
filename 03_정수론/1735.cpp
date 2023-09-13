#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    int a, b, c, d;
    int n, m;
    int g;

    cin >> a >> b >> c >> d;

    n = (a * d) + (b * c);
    m = b * d;
    g = gcd(n, m);

    cout << n / g << " " << m / g;

    return 0;
}