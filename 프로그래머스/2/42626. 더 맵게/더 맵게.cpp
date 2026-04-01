#include <iostream>
#include <vector>
#include <queue>

int solution(std::vector<int> scoville, int K)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }

    int count = 0;

    while (!pq.empty())
    {
        int first = pq.top(); 
        pq.pop();

        if (first >= K)
        {
            return count;
        }

        if (pq.empty())
        {
            return -1;
        }

        int second = pq.top();
        pq.pop();

        int newFood = first + (second * 2);

        pq.push(newFood);
        count++;
    }

    return -1;
}