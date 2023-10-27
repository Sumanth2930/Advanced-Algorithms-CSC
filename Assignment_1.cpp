#include <iostream>
#include <vector>

int main()
{
    int n;
    int target;

    std::cout << "Enter the array size: " << std::endl;
    std::cin >> n;

    std::vector<int> input_array(n);
    std::cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> input_array[i];
    }
    std::cout << "Enter Target: ";
    std::cin >> target;
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (input_array[i] + input_array[j] == target)
            {
                std::cout << "[" << input_array[i] << "," << input_array[j] << "]";
                i = n;
                found = 1;
                break;
            }
        }
    }
    if (!found)
    {
        std::cout << "Not found any pair";
    }

    return 0;
}