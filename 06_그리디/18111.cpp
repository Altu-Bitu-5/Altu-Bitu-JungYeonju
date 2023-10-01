#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int flatGroundHeight(int height, int block, int *ans_time, vector<int> ground)
{
    int cur_time = 0;
    for (int i = 0; i < ground.size(); i++)
    {
        int diff = ground[i] - height;

        if (diff > 0)
        {
            cur_time += 2 * (diff);
        }
        else
        {
            cur_time += 1 * abs(diff);
        }
        block += diff;
    }
    if (block >= 0)
    {
        *ans_time = min(*ans_time, cur_time);
        if (*ans_time == cur_time)
        {
            return height;
        }
        return -1;
    }
    return 0;
}

int main()
{
    // 최대 높이, 최대 시간 상수로 지정
    const int MAX_HEIGHT = 256;
    const int MIN_HEIGHT = 0;
    const int MAX_TIME = 9999999999;

    int low = MAX_HEIGHT + 1;
    int high = MIN_HEIGHT - 1;
    int ans_time = MAX_TIME;
    int ans_height = MIN_HEIGHT - 1;

    int N, M, B;
    int tmp;
    vector<int> ground;

    cin >> N >> M >> B;
    for (int i = 0; i < N * M; i++)
    {
        cin >> tmp;
        ground.push_back(tmp);
        low = min(low, ground[i]);
        high = max(high, ground[i]);
    }

    for (int height = low; height <= high; height++)
    {
        ans_height = max(ans_height, flatGroundHeight(height, B, &ans_time, ground));
    }
    cout << ans_time << " " << ans_height;

    return 0;
}