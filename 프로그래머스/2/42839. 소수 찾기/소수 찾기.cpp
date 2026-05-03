#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

class SolutionHelper
{
public:
    unordered_set<int> madeNumbers;
    vector<bool> visited;
    string digits;

    bool IsPrime(int number)
    {
        if (number < 2)
        {
            return false;
        }

        for (int i = 2; i * i <= number; i++)
        {
            if (number % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    void DFS(string current)
    {
        if (!current.empty())
        {
            int number = stoi(current);
            madeNumbers.insert(number);
        }

        for (int i = 0; i < digits.size(); i++)
        {
            if (visited[i])
            {
                continue;
            }

            visited[i] = true;
            DFS(current + digits[i]);
            visited[i] = false;
        }
    }
};

int solution(string numbers)
{
    SolutionHelper helper;

    helper.digits = numbers;
    helper.visited = vector<bool>(numbers.size(), false);

    helper.DFS("");

    int answer = 0;

    for (int number : helper.madeNumbers)
    {
        if (helper.IsPrime(number))
        {
            answer++;
        }
    }

    return answer;
}