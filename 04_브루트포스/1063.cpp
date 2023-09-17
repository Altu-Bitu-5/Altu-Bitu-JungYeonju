#include <iostream>
#include <string>

using namespace std;

void moveChessmen(int kx, int ky, int dolx, int doly, int n)
{
    while (n--)
    {

        string s[8] = {"R", "L", "B", "T", "RT", "LT", "RB", "LB"};
        int dy[8] = {0, 0, -1, 1, 1, 1, -1, -1};
        int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};

        string str;

        cin >> str;

        for (int i = 0; i < 8; i++)
        {
            if (str == s[i])
            {
                int mx = kx + dx[i];
                int my = ky + dy[i];
                if (mx <= 0 || my <= 0 || mx >= 9 || my >= 9)
                    break;
                if (mx == dolx && my == doly)
                {
                    int mmx = dolx + dx[i];
                    int mmy = doly + dy[i];
                    if (mmx <= 0 || mmy <= 0 || mmx >= 9 || mmy >= 9)
                        break;
                    dolx += dx[i];
                    doly += dy[i];
                }
                kx += dx[i];
                ky += dy[i];
            }
        }
    }

    char char_k = kx + 'A' - 1;
    char char_d = dolx + 'A' - 1;

    cout << char_k << ky << "\n"
         << char_d << doly;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string king, dol;
    int n, kx, ky, dolx, doly;

    cin >> king >> dol >> n;

    kx = king[0] - 'A' + 1;
    ky = king[1] - '0';

    dolx = dol[0] - 'A' + 1;
    doly = dol[1] - '0';

    moveChessmen(kx, ky, dolx, doly, n);
}
