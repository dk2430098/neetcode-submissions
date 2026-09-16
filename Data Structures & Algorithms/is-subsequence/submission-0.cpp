class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n > m) return false;

        int i = 0, j = 0;

        while(i < n){
            char ch = s[i];

            bool flag = false;
            while(j < m){
                if(ch == t[j]) {
                    flag = true;
                    j++;
                    break;
                }
                j++;
            }

            if(flag == false) return false;
            i++;
        }

        return true;
    }
};