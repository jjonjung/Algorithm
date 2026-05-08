#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    vector<int> count(N + 2, 0);

    for (int stage : stages)
    {
        count[stage]++;
    }

    vector<pair<double, int>> failureRates;
    int reachedUsers = stages.size();

    for (int stage = 1; stage <= N; stage++)
    {
        double failureRate = 0.0;

        if (reachedUsers > 0)
        {
            failureRate = (double)count[stage] / reachedUsers;
        }

        failureRates.push_back({ failureRate, stage });

        reachedUsers -= count[stage];
    }

    sort(failureRates.begin(), failureRates.end(),
        [](const pair<double, int>& a, const pair<double, int>& b)
        {
            if (a.first == b.first)
            {
                return a.second < b.second;
            }

            return a.first > b.first;
        });

    for (const auto& rateInfo : failureRates)
    {
        answer.push_back(rateInfo.second);
    }

    return answer;
}