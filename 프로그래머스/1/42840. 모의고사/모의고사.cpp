#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> result;

    vector<int> p1 = {1, 2, 3, 4, 5};
    vector<int> p2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> p3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int s1 = 0, s2 = 0, s3 = 0;

    int i1 = 0, i2 = 0, i3 = 0;

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == p1[i1]) s1++;
        if (answers[i] == p2[i2]) s2++;
        if (answers[i] == p3[i3]) s3++;

        i1++;
        i2++;
        i3++;

        if (i1 == p1.size()) i1 = 0;
        if (i2 == p2.size()) i2 = 0;
        if (i3 == p3.size()) i3 = 0;
    }

    int maxScore = max({s1, s2, s3});

    if (s1 == maxScore) result.push_back(1);
    if (s2 == maxScore) result.push_back(2);
    if (s3 == maxScore) result.push_back(3);

    return result;
}