class Solution {
public:
    //1 <= nums.length <= 3 * 10e4
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            if (nums[i] != nums[j]) {
                ++i;
                nums[i] = nums[j];
            }
            ++j;
        }
        return i + 1;
    }
};