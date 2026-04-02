#include <iostream>
#include <string>

int main()
{
    int T;
    std::cin >> T;

    while (T--)
    {
        std::string s;
        std::cin >> s;

        int count = 0;
        bool isValid = true;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                count++;  
            }
            else
            {
                count--;  

                if (count < 0)
                {
                    isValid = false;
                    break;
                }
            }
        }

        if (count != 0)
        {
            isValid = false;
        }

        if (isValid)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }

    return 0;
}