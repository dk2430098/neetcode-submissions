class Solution {
public:
    bool isAnagram(string s, string t) {
        int size_s = s.size();
        int size_t = t.size();

        if(size_s != size_t) return false;

        vector<int> freq(26, 0);
        for(char ch : s) {
            int idx = ch - 'a';
            freq[idx]++;
        }

        for(char ch : t){
            int idx = ch - 'a';
            if(freq[idx] == 0) return false;
            freq[idx]--;
        }

        return true;
    }
};
