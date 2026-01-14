#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

// 使用 C++20 标准编译: g++ -std=c++20 unordered_map_contains.cpp -o output

int main() {
    // 创建一个 unordered_map，键是 string，值是 int
    std::unordered_map<std::string, int> scores;

    // 插入键值对
    scores["Alice"] = 95;
    scores["Bob"] = 87;
    scores["Charlie"] = 92;
    scores["David"] = 78;

    std::cout << "学生成绩表:" << std::endl;
    std::cout << "==========================" << std::endl;

    // 使用 contains 函数检查键是否存在 (C++20 特性)
    std::string student = "Alice";
    if (scores.contains(student)) {
        std::cout << student << " 的成绩是: " << scores[student] << std::endl;
    } else {
        std::cout << student << " 不在成绩表中" << std::endl;
    }

    // 检查另一个学生
    student = "Eve";
    if (scores.contains(student)) {
        std::cout << student << " 的成绩是: " << scores[student] << std::endl;
    } else {
        std::cout << student << " 不在成绩表中" << std::endl;
    }

    std::cout << "\n所有学生及其成绩:" << std::endl;
    std::cout << "==========================" << std::endl;

    // 遍历 unordered_map
    for (const auto& pair : scores) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << "\n使用 contains 检查多个学生:" << std::endl;
    std::cout << "==========================" << std::endl;

    // 批量检查
    std::vector<std::string> checkStudents = {"Alice", "Bob", "Eve", "Frank"};
    for (const auto& name : checkStudents) {
        if (scores.contains(name)) {
            std::cout << "✓ " << name << " 存在，成绩: " << scores[name] << std::endl;
        } else {
            std::cout << "✗ " << name << " 不存在" << std::endl;
        }
    }

    return 0;
}
