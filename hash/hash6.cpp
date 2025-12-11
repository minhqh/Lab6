int pairMatching(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    
    int count = 0;
    int left = 0;
    int right = nums.size() - 1;
    
    while (left < right) {
        int sum = nums[left] + nums[right];
        
        if (sum == target) {
            count++;    
            left++;    
            right--;
        }
        else if (sum < target) {
            left++;   
        }
        else {
            right--;  
        }
    }
    
    return count;
}