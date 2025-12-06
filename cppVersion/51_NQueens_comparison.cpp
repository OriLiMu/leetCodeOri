#include <vector>
#include <string>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// 基础版本
class SolutionBasic {
private:
    vector<vector<string>> result;
    vector<string> board;
    int n;
    
    bool isValid(int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        
        return true;
    }
    
    void backtrack(int row) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (isValid(row, col)) {
                board[row][col] = 'Q';
                backtrack(row + 1);
                board[row][col] = '.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        board.resize(n, string(n, '.'));
        result.clear();
        backtrack(0);
        return result;
    }
};

// 数组优化版本
class SolutionOptimized {
private:
    vector<vector<string>> result;
    vector<string> board;
    int n;
    vector<bool> columns, diag1, diag2;
    
    void backtrack(int row) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            int d1 = row - col + n - 1;
            int d2 = row + col;
            
            if (!columns[col] && !diag1[d1] && !diag2[d2]) {
                board[row][col] = 'Q';
                columns[col] = diag1[d1] = diag2[d2] = true;
                
                backtrack(row + 1);
                
                board[row][col] = '.';
                columns[col] = diag1[d1] = diag2[d2] = false;
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        board.resize(n, string(n, '.'));
        columns.resize(n, false);
        diag1.resize(2 * n - 1, false);
        diag2.resize(2 * n - 1, false);
        result.clear();
        backtrack(0);
        return result;
    }
};

// 位运算版本
class SolutionBitmask {
private:
    vector<vector<string>> result;
    int n;
    
    void backtrack(int row, int columns, int diag1, int diag2, vector<string>& board) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        int available = ~(columns | diag1 | diag2) & ((1 << n) - 1);
        
        while (available) {
            int position = available & -available;
            available ^= position;
            
            int col = 0;
            int temp = position;
            while (temp > 1) {
                temp >>= 1;
                col++;
            }
            
            board[row][col] = 'Q';
            backtrack(row + 1, 
                     columns | position,
                     (diag1 | position) << 1,
                     (diag2 | position) >> 1,
                     board);
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

// 性能测试函数
void performanceTest(int n) {
    SolutionBasic basic;
    SolutionOptimized optimized;
    SolutionBitmask bitmask;
    
    cout << "\n=== N = " << n << " 性能对比 ===" << endl;
    
    // 测试基础版本
    auto start = high_resolution_clock::now();
    auto result1 = basic.solveNQueens(n);
    auto end = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end - start);
    
    cout << "基础版本:   " << result1.size() << " 个解法, 耗时: " 
         << duration1.count() << " 微秒" << endl;
    
    // 测试优化版本
    start = high_resolution_clock::now();
    auto result2 = optimized.solveNQueens(n);
    end = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end - start);
    
    cout << "数组优化版: " << result2.size() << " 个解法, 耗时: " 
         << duration2.count() << " 微秒" << endl;
    
    // 测试位运算版本
    start = high_resolution_clock::now();
    auto result3 = bitmask.solveNQueens(n);
    end = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(end - start);
    
    cout << "位运算版:   " << result3.size() << " 个解法, 耗时: " 
         << duration3.count() << " 微秒" << endl;
    
    // 验证结果一致性
    if (result1.size() == result2.size() && result2.size() == result3.size()) {
        cout << "✓ 所有版本结果一致" << endl;
    } else {
        cout << "✗ 结果不一致！" << endl;
    }
    
    cout << "数组优化 vs 基础: " << (double)duration1.count() / duration2.count() << "x" << endl;
    cout << "位运算 vs 基础:   " << (double)duration1.count() / duration3.count() << "x" << endl;
    cout << "位运算 vs 数组优化: " << (double)duration2.count() / duration3.count() << "x" << endl;
}

int main() {
    cout << "N皇后问题三种实现版本性能对比" << endl;
    cout << "======================================" << endl;
    
    // 测试不同规模
    for (int n = 4; n <= 12; n++) {
        performanceTest(n);
    }
    
    return 0;
}
