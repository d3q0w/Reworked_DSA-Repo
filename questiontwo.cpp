#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class myClass
{
public:
    void rotateElements(vector<int> &nums, int k)
    {

        k %= nums.size();                        // Modulo
        reverse(nums.begin(), nums.end());       // Reverse entire array
        reverse(nums.begin(), nums.begin() + k); // Reverse first k elements
        reverse(nums.begin() + k, nums.end());   // Reverse remaining elements
    }
};

int main()
{
    // test
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7}; // I used this sample array.
    int k = 3;                                // Rotate by 3 steps

    cout << "Original array: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    myClass elementsRotation;
    elementsRotation.rotateElements(nums, k); // function

    cout << "Rotated array: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}
