class Solution {
    bool f(int i, int j, int n, int m, string& s, string& t){
        if(i == n) return true;
        if(j >= m) return false;

        if(s[i] == t[j]) {
            i++;
        }

        return f(i, j+1, n, m, s, t);
    }
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        return f(0, 0, n, m, s, t);
    }
};