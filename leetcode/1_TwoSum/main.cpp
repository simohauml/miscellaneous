#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

//vector<int> twoSum(vector<int>& nums, int target);
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> indices;
        for(int i = 0; i < nums.size(); i++)
        {
            int remain = target - nums[i];
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(remain == nums[j])
                {
                    indices.push_back(i);
                    indices.push_back(j);
                    break;
                }
            }
        }
        return indices;
    }
};

int main() {
    Solution s;
    vector<int> numbers = { 2, 7, 11, 15, 3, 4 };
    vector<int> result = s.twoSum(numbers, 6);
    cout <<  result[0] << " " << result[1] << endl;
    return 0;
}