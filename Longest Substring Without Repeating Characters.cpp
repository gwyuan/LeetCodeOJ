// O(n) complexity. Runtime: 12ms

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        int size = s.size();
        int count = 0;
        vector<int> lastAppearance(256, -1);
        int startIndex = 0;
        
        for(int i=0; i<size; i++) {
            int ch = s[i];
            
            // Find repeated character
            if((lastAppearance[ch] != -1) && (lastAppearance[ch] >= startIndex)) {
                count = i - lastAppearance[ch];
                startIndex = lastAppearance[ch] + 1;
            }
            else 
                count++;
            
            lastAppearance[ch] = i;
            ret = max(ret, count);
        }
        
        return ret;
    }
    
};
