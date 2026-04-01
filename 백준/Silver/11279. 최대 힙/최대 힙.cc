#include <iostream>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::priority_queue<int> pq;

    for (int i = 0; i < N; i++)
    {
        int x;
        std::cin >> x;

        if (x == 0)
        {
            if (pq.empty())
            {
                std::cout << 0 << '\n';
            }
            else
            {
                std::cout << pq.top() << '\n';
                pq.pop(); 
            }
        }
        else
        {
            pq.push(x);
        }
    }

    return 0;
}