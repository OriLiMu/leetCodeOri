#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    vector<string> board;
    int n;
    
    // 使用位运算优化的冲突检查
    // columns: 记录被占用的列
    // diag1: 记录被占用的主对角线 (row - col)
    // diag2: 记录被占用的副对角线 (row + col)
    vector<bool> columns, diag1, diag2;
    
    // 回溯算法（优化版）
    void backtrack(int row) {
        // 如果已经放置了n个皇后，找到一个解
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        // 尝试在当前行的每一列放置皇后
        for (int col = 0; col < n; col++) {
            int d1 = row - col + n - 1;  // 主对角线索引，加上偏移量避免负数
            int d2 = row + col;          // 副对角线索引
            
            // 检查是否冲突
            if (!columns[col] && !diag1[d1] && !diag2[d2]) {
                // 放置皇后
                board[row][col] = 'Q';
                columns[col] = true;
                diag1[d1] = true;
                diag2[d2] = true;
                
                // 递归到下一行
                backtrack(row + 1);
                
                // 回溯，移除皇后
                board[row][col] = '.';
                columns[col] = false;
                diag1[d1] = false;
                diag2[d2] = false;
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        
        // 清空结果
        result.clear();
        
        // 初始化棋盘
        board.clear();
        board.resize(n, string(n, '.'));
        
        // 初始化冲突检查数组
        columns.clear();
        columns.resize(n, false);
        diag1.clear();
        diag1.resize(2 * n - 1, false);  // 主对角线有2n-1条
        diag2.clear();
        diag2.resize(2 * n - 1, false);  // 副对角线有2n-1条
        
        // 从第0行开始回溯
        backtrack(0);
        
        return result;
    }
};

// 测试函数
int main() {
    Solution s;
    
    // 测试不同规模的N皇后问题
    for (int n = 1; n <= 8; n++) {
        vector<vector<string>> results = s.solveNQueens(n);
        cout << "N = " << n << " 时共有 " << results.size() << " 种解法" << endl;
        
        // 只显示前2个解法（如果有的话）
        for (int i = 0; i < min(2, (int)results.size()); i++) {
            cout << "解法 " << i + 1 << ":" << endl;
            for (const string& row : results[i]) {
                cout << row << endl;
            }
            cout << endl;
        }
        cout << "------------------------" << endl;
    }
    
    return 0;
}
