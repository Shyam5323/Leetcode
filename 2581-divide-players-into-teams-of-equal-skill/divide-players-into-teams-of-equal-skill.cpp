class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        unordered_set<int> s(skill.begin(), skill.end()); 
        int n = skill.size();
        long long totalChemistry = 0;
        
        sort(skill.begin(), skill.end());
        
        int targetSum = skill[0] + skill[n - 1]; 

        for (int i = 0; i < n / 2; ++i) {
            int left = skill[i];
            int right = skill[n - i - 1];
            
            if (left + right != targetSum) {
                return -1; 
            }
            
            totalChemistry += left * right;
        }

        return totalChemistry;
    }
};
