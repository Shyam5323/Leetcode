
using namespace std;

class Solution {
public:
    int binaryToInteger(string bin) {
        int num = 0;
        int index = 0;
        for (int i = bin.length() - 1; i >= 0; i--) {
            if (bin[i] == '1') {
                num += (1 << index);  
            }
            index++;
        }
        return num;
    }

    string numToBin(int num, int length) {
        string bin = "";
        for (int i = length - 1; i >= 0; i--) {
            bin += (num & (1 << i)) ? '1' : '0';
        }
        return bin;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        vector<int> intNums;
        for (auto& num : nums) {
            intNums.push_back(binaryToInteger(num));
        }

        int len = nums[0].length();
        sort(intNums.begin(), intNums.end());

        for (int i = 0; i < intNums.size(); i++) {
            if (i != intNums[i]) {
                return numToBin(i, len);
            }
        }
        return numToBin(intNums.size(), len);
    }
};
