class Solution {
public:
    int myAtoi(string s, int index = 0, long long answer = 0, bool negative = false, bool found = false) {
        // Base case: if index is out of bounds or if the answer has exceeded integer limits
        if (index >= s.size()) return (negative) ? -answer : answer;
        if (answer > INT_MAX) return (negative) ? INT_MIN : INT_MAX;

        char c = s[index];
        
        // If the character is a space and we haven't started building the number, skip it
        if (c == ' ' && !found) return myAtoi(s, index + 1, answer, negative, found);
        
        // If the character is a sign and we haven't started building the number, set the sign
        if ((c == '-' || c == '+') && !found) {
            negative = (c == '-');
            return myAtoi(s, index + 1, answer, negative, true);
        }

        // If the character is a digit, update the answer
        if (c >= '0' && c <= '9') {
            answer = answer * 10 + (c - '0');
            if (answer > INT_MAX) return (negative) ? INT_MIN : INT_MAX;
            return myAtoi(s, index + 1, answer, negative, true);
        }

        // If we encounter a non-space and non-digit character after starting, return the answer
        return (negative) ? -answer : answer;
    }
};