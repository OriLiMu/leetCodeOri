#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    // 5 test case
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 3;
    int result = BinarySearch(nums, target);
    cout << result << endl;

    vector<int> nums2 = {1, 2, 3, 4, 5};
    int target2 = 6;
    int result2 = BinarySearch(nums2, target2);
    cout << result2 << endl;

    vector<int> nums3 = {1, 2, 3, 4, 5};
    int target3 = 0;
    int result3 = BinarySearch(nums3, target3);
    cout << result3 << endl;

    return 0;
}
