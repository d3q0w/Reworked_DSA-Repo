#include <iostream>
#include <vector>

using namespace std;

class myClass
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0; // empty case

        int duplicateCounter = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
            {
                duplicateCounter++;
            }
            else
            {
                nums[i - duplicateCounter] = nums[i];
            }
        }
        return nums.size() - duplicateCounter;
    }
};

int main()
{
    // test
    vector<int> nums = {1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 7}; // feel free to change this

    std::cout << "Original Array: ";
    for (int num : nums)
        std::cout << num << " ";
    std::cout << '\n';

    myClass dupRemover;
    int newArray = dupRemover.removeDuplicates(nums);

    std::cout << "After Processing: ";
    for (int i = 0; i < newArray; i++)
        std::cout << nums[i] << " ";
    std::cout << '\n';

    return 0;
}
