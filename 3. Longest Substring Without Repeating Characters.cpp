class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0, i = 0, j = 0;
        unordered_map<char, int> win;
        while(i < s.size() && j < s.size()){
            if(win.count(s[j]) == 0){
                win.insert({s[j], j});
                j++;
                if(j - i > longest)
                    longest = j - i;
            }
            else{
                win.erase(s[i]);
                i++;
            }
        }
        return longest;
    }
};

// TODO: Try to optimize the performance, and use the charset solution

// O(n^2) solution
/*
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        for(int i=0; i<s.length(); ++i){
            unordered_map<char, int> sub;
            for(int j=i; j<s.length(); ++j){
                bool repeat = true;
                // The substring without repeat yet
                if(sub.find(s[j]) == sub.end()){
                    sub.insert({s[j], j});
                    // Check if the substring is the longest one
                    if(sub.size() > longest){
                        longest = sub.size();
                    }
                }
                // Find a repeat and compare the length
                else{
                    break;
                }
            }
        }
        return longest;
    }
*/
