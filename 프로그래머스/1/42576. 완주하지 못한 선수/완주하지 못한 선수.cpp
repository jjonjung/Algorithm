#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    unordered_map<string, int> countMap;

    for (const string& name : participant)
    {
        countMap[name]++;
    }

    for (const string& name : completion)
    {
        countMap[name]--;
    }

    for (const string& name : participant)
    {
        if (countMap[name] > 0)
        {
            return name;
        }
    }

    return "";
}