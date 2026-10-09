class Solution {
public:
    bool isPalindrome(string s) {
        const char* start_ptr = s.c_str();
        const char* last_ptr = start_ptr + s.length() - 1;
        while (start_ptr <= last_ptr) {
            while(!isalnum(*start_ptr)) start_ptr++;
            while(!isalnum(*last_ptr)) last_ptr--;
            if (tolower(*start_ptr) != tolower(*last_ptr) && start_ptr <= last_ptr) return false;
            start_ptr++;
            last_ptr--;
        }
        return true;
    }
};
