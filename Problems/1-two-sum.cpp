class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen; // Map: number -> index

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        // Check if complement already seen
        if (seen.find(complement) != seen.end()) {
            return {seen[complement], i};
        }

        // Store the current number and its index
        seen[nums[i]] = i;
    }

    return {}; // Guaranteed to have one solution, so this won't be reached
}
};