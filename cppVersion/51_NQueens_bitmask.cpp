#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    int n;
    
    // 使用位运算的回溯算法
    void backtrack(int row, int columns, int diag1, int diag2, vector<string>& board) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        // 计算当前行可用的位置
        // columns: 已占用的列
        // diag1: 已占用的主对角线（左移一位）
        // diag2: 已占用的副对角线（右移一位）
        int available = ~(columns | diag1 | diag2) & ((1 << n) - 1);
        
        while (available) {
            // 获取最低位的1，表示可用的位置
            int position = available & -available;
            
            // 移除该位置，继续尝试其他位置
            available ^= position;
            
            // 计算皇后所在的列
            int col = 0;
            int temp = position;
            while (temp > 1) {
                temp >>= 1;
                col++;
            }
            
            // 放置皇后
            board[row][col] = 'Q';
            
            // 递归到下一行
            backtrack(row + 1, 
                     columns | position,
                     (diag1 | position) << 1,
                     (diag2 | position) >> 1,
                     board);
            
            // 回溯，移除皇后
            board[row][col] = '.';
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        result.clear();
        
        vector<string> board(n, string(n, '.'));
        backtrack(0, 0, 0, 0, board);
        
        return result;
    }
};

// 测试函数
int main() {
    Solution s;
    
    cout << "=== 位运算优化版本测试 ===" << endl;
    
    // 测试不同规模的N皇后问题
    for (int n = 1; n <= 8; n++) {
        vector<vector<string>> results = s.solveNQueens(n);
        cout << "N = " << n << " 时共有 " << results.size() << " 种解法" << endl;
        
        // 只显示第一个解法（如果有的话）
        if (!results.empty()) {
            cout << "第一个解法:" << endl;
            for (const string& row : results[0]) {
                cout << row << endl;
            }
            cout << endl;
        }
        cout << "------------------------" << endl;
    }
    
    return 0;
}
