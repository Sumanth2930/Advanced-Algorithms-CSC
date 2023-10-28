#include <iostream>
#include <vector>

int main()
{
    int n;
    int target;

    //take input array size
    std::cout << "Enter the array size: " << std::endl;
    std::cin >> n;

    //input array elements
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
            //if sum of two value is equal to target
            if (input_array[i] + input_array[j] == target) 
            {
                std::cout << "[" << i << "," << j << "]";
                i = n;
                found = 1; //update pair found
                break;
            }
        }
    }
    //if no pair found
    if (!found)
    {
        std::cout << "Not found any pair";
    }

    return 0;
}