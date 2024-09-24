class Solution {
public:
    int maxArea(std::vector<int>& height) {
        unsigned long long int area{};
        auto left = height.begin();
        auto right = height.end() - 1; 
        int width = height.size() - 1; 

        while (left < right) { 
            area = max(area, static_cast<unsigned long long int>(width) * min(*left, *right));

            if (*left > *right) {
                right--;
            } else {
                left++;
            }
            width--;
        }
        return area;
    }
};