class Solution {
    bool check(int sr, int sc, int er, int ec, vector<vector<char>>& board) {
        unordered_set<char> st;

        for (int i = sr; i < er; i++) {
            for (int j = sc; j < ec; j++) {
                if (board[i][j] == '.') continue;

                if (st.find(board[i][j]) != st.end())
                    return false;

                st.insert(board[i][j]);
            }
        }

        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Row
        for (int i = 0; i < 9; i++) {
            unordered_set<char> st;

            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                if (st.find(board[i][j]) != st.end())
                    return false;

                st.insert(board[i][j]);
            }
        }

        // Column
        for (int j = 0; j < 9; j++) {
            unordered_set<char> st;

            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;

                if (st.find(board[i][j]) != st.end())
                    return false;

                st.insert(board[i][j]);
            }
        }

        // 3 x 3 boxes
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {

                int er = i + 3;
                int ec = j + 3;

                if (!check(i, j, er, ec, board))
                    return false;
            }
        }

        return true;
    }
};