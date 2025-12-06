#include <vector>
#include <string>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class SolutionBasic {
private:
    vector<vector<string>> result;
    vector<string> board;
    int n;
    
    bool isValid(int row, int col) {
        // 检查列
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        
        // 检查左上对角线
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        
        // 检查右上对角线
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

// 性能测试函数
void performanceTest(int n) {
    SolutionBasic basic;
    SolutionOptimized optimized;
    
    cout << "\n=== N = " << n << " 性能测试 ===" << endl;
    
    // 测试基础版本
    auto start = high_resolution_clock::now();
    auto result1 = basic.solveNQueens(n);
    auto end = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end - start);
    
    cout << "基础版本: " << result1.size() << " 个解法, 耗时: " 
         << duration1.count() << " 微秒" << endl;
    
    // 测试优化版本
    start = high_resolution_clock::now();
    auto result2 = optimized.solveNQueens(n);
    end = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end - start);
    
    cout << "优化版本: " << result2.size() << " 个解法, 耗时: " 
         << duration2.count() << " 微秒" << endl;
    
    cout << "性能提升: " << (double)duration1.count() / duration2.count() << "x" << endl;
}

int main() {
    // 测试不同规模
    for (int n = 4; n <= 10; n++) {
        performanceTest(n);
    }
    
    return 0;
}
