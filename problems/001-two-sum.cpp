#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            int complement = target - nums[i];
            
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            numMap[nums[i]] = i;
        }
        
        return {}; // 如果没有找到解决方案
    }
};

// 测试函数
void test() {
    Solution solution;
    
    // 测试用例 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(nums1, target1);
    cout << "Test 1: [" << result1[0] << ", " << result1[1] << "]" << endl;
    assert(result1 == vector<int>({0, 1}));
    
    // 测试用例 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(nums2, target2);
    cout << "Test 2: [" << result2[0] << ", " << result2[1] << "]" << endl;
    assert(result2 == vector<int>({1, 2}));
    
    // 测试用例 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = solution.twoSum(nums3, target3);
    cout << "Test 3: [" << result3[0] << ", " << result3[1] << "]" << endl;
    assert(result3 == vector<int>({0, 1}));
    
    cout << "All tests passed!" << endl;
}

int main() {
    test();
    return 0;
}
