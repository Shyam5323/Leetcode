#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<vector<int>> memo(n, vector<int>(shelfWidth + 1, -1)); 
        return place(0, shelfWidth, 0, books, shelfWidth, memo);
    }
    
private:
    int place(int book_pos, int remaining_width, int max_height, vector<vector<int>>& books, int shelfWidth, vector<vector<int>>& memo) {
        if (book_pos == books.size()) return 0;
        if (memo[book_pos][remaining_width] != -1) return memo[book_pos][remaining_width];

        int width = books[book_pos][0], height = books[book_pos][1];
        
        // Option 1: Place book on a new shelf
        int ans = height + place(book_pos + 1, shelfWidth - width, height, books, shelfWidth, memo);
        
        // Option 2: Place book on the same shelf if it fits
        if (remaining_width >= width) {
            int height_increase = max(0, height - max_height);
            ans = min(ans, height_increase + place(book_pos + 1, remaining_width - width, max(max_height, height), books, shelfWidth, memo));
        }

        return memo[book_pos][remaining_width] = ans;
    }
};
