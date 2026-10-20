class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        int res = 0;
        
        for(int k = 1; k <= n; k++){
            if(n % k == 0){
                bool is_val = true;
                for(int i = 0; i < n; i += k){
                    int drop_idx = -1;
                    
                    // 1. Find if the chunk has at most one "drop"
                    for(int j = i; j < i + k - 1; j++) {
                        if(nums[j] > nums[j+1]) {
                            if(drop_idx != -1) { drop_idx = -2; break; } // More than 1 drop
                            drop_idx = j;
                        }
                    }
                    
                    // 2. Reject if >1 drop, or if the wrap-around boundary isn't sorted
                    if(drop_idx == -2 || (drop_idx != -1 && nums[i + k - 1] > nums[i])) {
                        is_val = false; 
                        break;
                    }
                    
                    // 3. Verify the rotated chunk matches sorted_nums exactly (Zero allocations)
                    int offset = (drop_idx == -1) ? 0 : (drop_idx - i + 1);
                    for(int j = 0; j < k; j++) {
                        if(nums[i + (offset + j) % k] != sorted_nums[i + j]) {
                            is_val = false;
                            break;
                        }
                    }
                    
                    if(!is_val) break;
                }
                if(is_val) res += k;
            }
        }
        return res;
    }
};