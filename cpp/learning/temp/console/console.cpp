#include <iostream>
//211
int main()
{
    int count{ 0 };
    int string{0};
    while (true)
    {
        std::cout << count;

        if (count % 8 == 0)
        {
            count = count % 8;
            ++string;
        }
        if (string % 12 == 0 && string > 12)
        {
            string = string % 12;
            std::cout << "-------------------"<<'\n';
        }

        ++count;
    }

    return 0;
}
