class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> m_map;
        for(int i=0; i<nums.size(); i++) {
            std::map<int, int>::iterator it;
            it = m_map.find(nums[i]);
            // Found the paired value, return both indices
            if(it != m_map.end()) {
                vector<int> indices{it->second, i};
                return indices;
            }
            // The paired value is not found, store its paired value with this index
            else {
                m_map.insert(pair<int, int>(target - nums[i], i));
            }
        }
        vector<int> indices;
        return indices;
    }
};