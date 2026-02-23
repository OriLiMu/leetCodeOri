# C++ 测试函数模板

## 快速使用

### 1. 添加头文件和颜色定义

```cpp
// ANSI 颜色码
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BOLD "\033[1m"
#define RESET "\033[0m"
```

### 2. 定义测试用例结构

```cpp
struct TestCase {
  string input;      // 输入
  int expected;      // 期望输出（根据实际返回类型修改）
};
```

### 3. 添加测试函数

```cpp
void runTests() {
  Solution sol;

  // ========== 在这里添加你的测试用例 ==========
  vector<TestCase> tests = {
      {"输入1", 期望结果1},
      {"输入2", 期望结果2},
      // 添加更多测试用例...
  };
  // ===========================================

  int passed = 0;
  vector<int> failedIndices;

  for (int i = 0; i < tests.size(); i++) {
    int result = sol.你的函数名(tests[i].input);  // 修改为实际函数名
    bool ok = (result == tests[i].expected);

    if (ok) {
      cout << "Test " << i + 1 << ": ";
      cout << "\"" << tests[i].input << "\" -> ";
      cout << result << " [" << GREEN << "PASS" << RESET << "]" << endl;
      passed++;
    } else {
      cout << RED << BOLD << ">>> [FAIL] Test " << i + 1 << ": \""
           << tests[i].input << "\"" << RESET << endl;
      cout << RED << "           Expected: " << tests[i].expected
           << ", Got: " << result << RESET << endl;
      failedIndices.push_back(i);
    }
  }

  cout << "\n========== Result ==========" << endl;
  if (passed == tests.size()) {
    cout << GREEN << BOLD << "ALL PASSED: " << passed << "/" << tests.size()
         << RESET << endl;
  } else {
    cout << RED << BOLD << "FAILED: " << (tests.size() - passed) << "/"
         << tests.size() << RESET << endl;
    cout << RED << BOLD << "\n======== FAILED CASES ========" << RESET << endl;
    for (int idx : failedIndices) {
      int result = sol.你的函数名(tests[idx].input);  // 修改为实际函数名
      cout << RED << BOLD << "Test " << idx + 1 << RESET << endl;
      cout << RED << "  Input:    \"" << tests[idx].input << "\"" << endl;
      cout << RED << "  Expected: " << tests[idx].expected << endl;
      cout << RED << "  Got:      " << result << RESET << endl;
      cout << endl;
    }
  }
}
```

### 4. 修改 main 函数

```cpp
int main() { runTests(); }
```

---

## 需要修改的地方

| 位置 | 说明 |
|------|------|
| `TestCase.input` 类型 | 根据函数输入参数类型修改 |
| `TestCase.expected` 类型 | 根据函数返回类型修改 |
| `sol.你的函数名()` | 替换为实际的函数名 |
| 测试用例内容 | 添加实际的测试数据 |

---

## 不同输入类型的 TestCase 示例

### 字符串输入
```cpp
struct TestCase {
  string input;
  int expected;
};
```

### 整数输入
```cpp
struct TestCase {
  int input;
  int expected;
};
```

### 多参数输入
```cpp
struct TestCase {
  int a;
  int b;
  int expected;
};
// 调用: sol.func(tests[i].a, tests[i].b)
```

### 数组输入
```cpp
struct TestCase {
  vector<int> input;
  int expected;
};
// 用法: {{1, 2, 3}, 6}, {{4, 5}, 9}
```

---

## 运行测试

```bash
g++ your_file.cpp -o test && ./test
```

---

## 输出效果

```
Test 1: "(()" -> 2 [PASS]
Test 2: ")()())" -> 4 [PASS]
>>> [FAIL] Test 3: "abc"
           Expected: 5, Got: 3

========== Result ==========
FAILED: 1/3

======== FAILED CASES ========
Test 3
  Input:    "abc"
  Expected: 5
  Got:      3

ALL PASSED: 3/3   # 全部通过时显示
```
