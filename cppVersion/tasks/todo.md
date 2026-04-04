# 本次任务

- [x] 排查当前目录的 C++ 标准配置与报错来源
- [x] 为编辑器/clangd 增加 C++20 默认编译参数
- [x] 验证 `unordered_map::contains` 在当前目录按 C++20 解析

# 验证记录

- `g++ -std=c++20 -fsyntax-only test/unordered_map_contains.cpp` 通过。
- `128_LongestConsecutiveSequence.cpp` 仍有独立代码错误：`us.contains()` 缺少参数，且 `if ()` 未完成。
