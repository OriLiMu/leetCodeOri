#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    vector<string> board;
    int n;
    
    // 检查在(row, col)位置放置皇后是否安全
    bool isValid(int row, int col) {
        // 检查当前列
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        
        // 检查左上对角线 (row-1, col-1), (row-2, col-2), ...
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        // 检查右上对角线 (row-1, col+1), (row-2, col+2), ...
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        return true;
    }
    
    // 回溯算法
    void backtrack(int row) {
        // 如果已经放置了n个皇后，找到一个解
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        // 尝试在当前行的每一列放置皇后
        for (int col = 0; col < n; col++) {
            if (isValid(row, col)) {
                // 放置皇后
                board[row][col] = 'Q';
                
                // 递归到下一行
                backtrack(row + 1);
                
                // 回溯，移除皇后
                board[row][col] = '.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        // 初始化棋盘
        board.resize(n, string(n, '.'));
        
        // 从第0行开始回溯
        backtrack(0);
        
        return result;
    }
};

// 测试函数
int main() {
    Solution s;
    int n = 4;
    vector<vector<string>> results = s.solveNQueens(n);
    
    cout << "N = " << n << " 时共有 " << results.size() << " 种解法：" << endl;
    for (int i = 0; i < results.size(); i++) {
        cout << "解法 " << i + 1 << ":" << endl;
        for (const string& row : results[i]) {
            cout << row << endl;
        }
        cout << endl;
    }
    
    return 0;
}
