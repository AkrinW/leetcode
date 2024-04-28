class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size();
        while (i < j && j != 0) {
            if (nums[i] != val) {
                ++i;
            } else {
                nums[i] = nums[j-1];
                --j;
            }
        }
        return j;
    }
};