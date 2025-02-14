class ProductOfNumbers {
public:
    vector<int> nums;
    int lastZero;

    ProductOfNumbers() {
        lastZero = -1;
    }

    void add(int num) {
        if (num == 0) {
            nums.clear();
            lastZero = nums.size(); 
        } else {
            if (nums.empty()) {
                nums.push_back(num);
            } else {
                nums.push_back(nums.back() * num);
            }
        }
    }

    int getProduct(int k) {
        if (lastZero != -1 && lastZero > (int)nums.size() - k) {
            return 0;
        }
        if(lastZero == (int)nums.size() - k) {
            return nums.back();
        }
        if (k == (int)nums.size()) {
            return nums.back();
        }
        return nums.back() / nums[nums.size() - k - 1];
    }
};
