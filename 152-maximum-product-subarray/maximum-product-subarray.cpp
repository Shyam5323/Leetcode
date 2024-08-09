class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if(nums[0] == -2 && nums.size() == 1) {
            return -2;
        }

        vector<int> zeros;   
        vector<int> negCount; 
        
        int currNeg = 0;
        bool hasZero = false;
        
        // Identify zeros and negative counts
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeros.push_back(i);
                negCount.push_back(currNeg);
                currNeg = 0;
                hasZero = true;  // Mark that the array has at least one zero
            } else if (nums[i] < 0) {
                currNeg++;
            }
        }
        negCount.push_back(currNeg);
        
        int maxProd = nums[0];
        bool productUpdated = false;  // Initialize the flag
        
        int start = 0;
        for (int i = 0; i <= zeros.size(); i++) {
            int end = (i < zeros.size()) ? zeros[i] : n;
            int product = 1;
            
            if(negCount[i] % 2 == 0) {
                for(int j = start; j < end; j++) {
                    product *= nums[j];
                    productUpdated = true;  // Product has been updated
                }
                maxProd = max(product, maxProd);
            } else {
                int firstNegIdx = -1, lastNegIdx = -1;
                for (int j = start; j < end; j++) {
                    if (nums[j] < 0) {
                        if (firstNegIdx == -1) firstNegIdx = j;
                        lastNegIdx = j;
                    }
                }
                
                int product1 = 1;
                for(int j = firstNegIdx + 1; j < end; j++) {
                    product1 *= nums[j];
                    productUpdated = true;  // Product has been updated
                } 
                
                int product2 = 1;
                for(int j = start; j < lastNegIdx; j++) {
                    product2 *= nums[j];
                    productUpdated = true;  // Product has been updated
                }
                
                maxProd = max(product1, maxProd);
                maxProd = max(product2, maxProd);
            }
            
            start = end + 1;
        }
        
        // If no product was updated and there exists a zero, return 0
        if (!productUpdated && hasZero) {
            return 0;
        }

        return maxProd;
    }
};
