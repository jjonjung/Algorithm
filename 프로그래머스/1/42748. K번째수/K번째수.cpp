#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (const vector<int>& command : commands)
    {
        int i = command[0];
        int j = command[1];
        int k = command[2];

        vector<int> sliced;

        for (int index = i - 1; index <= j - 1; index++)
        {
            sliced.push_back(array[index]);
        }

        sort(sliced.begin(), sliced.end());
        answer.push_back(sliced[k - 1]);
    }

    return answer;
}