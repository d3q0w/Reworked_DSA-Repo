#include <iostream>
#include <vector>

using namespace std;

class myClass
{
public:
    int singleElement(vector<int> &nums)
    {
        int result = 0;
        for (int k = 0; k < nums.size(); ++k)
        {
            result ^= nums[k]; // XOR
        }
        return result;
    }
};

int main()
{
    // test
    vector<int> nums1 = {4, 1, 2, 1, 2};
    vector<int> nums2 = {7, 3, 5, 3, 7};

    myClass testSingle;

    cout << "The single element is : " << testSingle.singleElement(nums1) << endl;
    cout << "The single element in : " << testSingle.singleElement(nums2) << endl;

    return 0;
}
