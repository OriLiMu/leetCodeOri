import json
import os
import sys
from pathlib import Path
import requests
import json
from bs4 import BeautifulSoup




cookie = "aliyungf_tc=450b3903767118be05b2d26622beb9c374f7959c0fa62d0318cd9188eb2270cd; _bl_uid=pUmbt6jma2j8vtos3c84gp1ua2C7; csrftoken=XnirkmlygGs0mSRkRo5OageVVEOp3eQUwAyLeqbbweOK60XJ0dcJNGgBKwPhDryz; LEETCODE_SESSION=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJfYXV0aF91c2VyX2lkIjoiNzc4NzciLCJfYXV0aF91c2VyX2JhY2tlbmQiOiJhdXRoZW50aWNhdGlvbi5hdXRoX2JhY2tlbmRzLlBob25lQXV0aGVudGljYXRpb25CYWNrZW5kIiwiX2F1dGhfdXNlcl9oYXNoIjoiMDNhZDQ0YTQ2YzcxNjFjNDQ2YTFhNGMyYzNmYWExNTU4ZDAwOGVhNjRjMjIwMzA1NjhjMmU3M2VlZmYwZmJlYiIsImlkIjo3Nzg3NywiZW1haWwiOiI1MTMyNzgyMzZAcXEuY29tIiwidXNlcm5hbWUiOiJvcmlnYW1pIiwidXNlcl9zbHVnIjoib3JpZ2FtaSIsImF2YXRhciI6Imh0dHBzOi8vYXNzZXRzLmxlZXRjb2RlLmNuL2FsaXl1bi1sYy11cGxvYWQvdXNlcnMvb3JpZ2FtaS9hdmF0YXJfMTcyMTc1NjY0MS5wbmciLCJwaG9uZV92ZXJpZmllZCI6dHJ1ZSwiZGV2aWNlX2lkIjoiZWI5ZDIwMTljMjJkODI5MGMzM2NkYjdiYzFlYzk3ZjciLCJpcCI6IjE4My4xOTcuNzEuMjMwIiwiX3RpbWVzdGFtcCI6MTczNzY5MjM5OS4xMTk0NDUsImV4cGlyZWRfdGltZV8iOjE3NDAyNTA4MDAsInZlcnNpb25fa2V5XyI6MCwibGF0ZXN0X3RpbWVzdGFtcF8iOjE3Mzg0ODgwODV9.fvDYsYGcNABB-5Vj9UyrOQonOpvBe6uXo0TLHT0V1vc; sl-session=hukoEZnmtGenW6Kp6/JUug=="  # 替换为你的实际 Cookie

def get_leetcode_problem_info(problem_number, json_file="LeetCodeInfo.json"):
    try:
        with open(json_file, 'r', encoding='utf-8') as f:
            data = json.load(f)
            
        for problem in data["stat_status_pairs"]:
            if str(problem["stat"]["frontend_question_id"]) == str(problem_number):
                return problem["stat"]["question__title"]
                
        return None
            
    except Exception as e:
        print(f"读取题目信息时出错: {e}")
        return None

def handle_existing_file(base_filename):
    # 分离文件名和扩展名
    name, ext = os.path.splitext(base_filename)
    
    # 如果文件存在且不是以_v数字结尾
    if os.path.exists(base_filename) and not name.endswith(('_v1', '_v2', '_v3', '_v4', '_v5', '_v6', '_v7', '_v8', '_v9')):
        # 重命名现有文件为_v1
        new_name = f"{name}_v1{ext}"
        os.rename(base_filename, new_name)
        print(f"重命名现有文件为: {new_name}")
        return True
    return False

def get_available_filename(base_filename):
    # 如果文件不存在，直接返回原始文件名
    if not os.path.exists(base_filename):
        return base_filename
        
    # 分离文件名和扩展名
    name, ext = os.path.splitext(base_filename)
    
    # 检查是否已有版本号
    if name.endswith(('_v1', '_v2', '_v3', '_v4', '_v5', '_v6', '_v7', '_v8', '_v9')):
        name = name[:-3]  # 移除现有版本号
    
    # 如果存在无版本号的文件，先处理它
    handle_existing_file(f"{name}{ext}")
    
    # 从v1开始查找可用的版本号
    version = 1
    while os.path.exists(f"{name}_v{version}{ext}"):
        version += 1
    
    return f"{name}_v{version}{ext}"

def create_leetcode_file(problem_number):
    title = get_leetcode_problem_info(problem_number)
    
    if not title:
        print(f"无法获取题目 {problem_number} 的信息")
        return
    
    title = title.replace(' ', '').replace('-', '').replace('(', '').replace(')', '')
    base_filename = f"{problem_number}_{title}.cpp"
    
    # 获取可用的文件名
    new_filename = get_available_filename(base_filename)

    try:
        template = get_cpp_template_by_test_number(problem_number, cookie)
        # 将模板写入文件
        with open("Template.cpp", "w", encoding="utf-8") as file:
            file.write(template)
        print("C++ template has been written to leetcode_cpp_template.txt")
    except Exception as e:
        print(f"Error: {e}")
    
    template_path = "Template.cpp"
    
    try:
        if not os.path.exists(template_path):
            print("模板文件 Template.cpp 不存在！")
            return
            
        with open(template_path, 'r') as source:
            content = source.read()
        
        # Process content to uncomment ListNode and TreeNode structures
        lines = content.split('\n')
        processed_lines = []
        i = 0
        
        while i < len(lines):
            line = lines[i]
            
            # Look for the start of a struct definition in comments
            if '/**' in line and i + 1 < len(lines):
                # Check if next lines contain struct definition
                j = i + 1
                struct_start = -1
                struct_end = -1
                
                # Look for struct ListNode or TreeNode within the comment block
                while j < len(lines) and '*/' not in lines[j]:
                    if 'struct ListNode' in lines[j] or 'struct TreeNode' in lines[j]:
                        struct_start = j
                        break
                    j += 1
                
                if struct_start != -1:
                    # Found struct in comment, extract it
                    struct_lines = []
                    
                    # Continue until end of comment or end of struct
                    k = struct_start
                    while k < len(lines) and '*/' not in lines[k]:
                        clean_line = lines[k].lstrip()
                        if clean_line.startswith('*'):
                            clean_line = clean_line[1:].lstrip()
                        struct_lines.append(clean_line)
                        k += 1
                    
                    # Add the struct definition
                    processed_lines.extend(struct_lines)
                    
                    # Skip to end of comment
                    while i < len(lines) and '*/' not in lines[i]:
                        i += 1
                    i += 1  # Skip closing */
                else:
                    # No struct found, keep original
                    processed_lines.append(line)
                    i += 1
            else:
                processed_lines.append(line)
                i += 1
        
        content = '\n'.join(processed_lines)
        
        content = """#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <strings.h>
#include <queue>

using namespace std;
""" + content + """
int main() {
  Solution s;
  cout << "hello" << endl;
}
            """
            
        with open(new_filename, 'w') as target:
            target.write(content)
            
        print(f"成功创建文件: {new_filename}")
        os.system('clang-format -i ' + new_filename)
        os.system('nvim ' + new_filename)
        
    except Exception as e:
        print(f"创建文件时出错: {e}")

def get_problem_slug_by_test_number(test_number):
    # 获取 LeetCode 问题列表的 API
    url = "https://leetcode.cn/api/problems/all/"

    # 发送 HTTP 请求
    response = requests.get(url)
    if response.status_code != 200:
        raise Exception(f"Failed to fetch problem list. Status code: {response.status_code}")

    # 解析 JSON 数据
    problems_data = response.json()

    # 遍历问题列表，找到与 test_number 匹配的题目
    for problem in problems_data['stat_status_pairs']:
        if problem['stat']['frontend_question_id'] == str(test_number):
            return problem['stat']['question__title_slug']

    raise Exception(f"No problem found with test number: {test_number}")

def get_cpp_template_by_test_number(test_number, cookie):
    # 获取题目 slug
    problem_slug = get_problem_slug_by_test_number(test_number)

    # LeetCode 中文版题目页面 URL
    url = f"https://leetcode.cn/problems/{problem_slug}/"

    # 设置请求头，包含 Cookie
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36",
        "Cookie": cookie,
    }

    # 发送 HTTP 请求
    response = requests.get(url, headers=headers)
    if response.status_code != 200:
        raise Exception(f"Failed to fetch the page. Status code: {response.status_code}")

    # 解析 HTML 内容
    soup = BeautifulSoup(response.content, "html.parser")

    # 查找 <script id="__NEXT_DATA__"> 标签
    script_tag = soup.find("script", id="__NEXT_DATA__")
    if not script_tag:
        raise Exception("Script tag with id '__NEXT_DATA__' not found on the page.")

    # 提取 JSON 内容并转换为 Python 字典
    json_data = json.loads(script_tag.string)

    # 提取 C++ 代码模板
    cpp_template = json_data['props']['pageProps']['dehydratedState']['queries'][1]['state']['data']['question']['codeSnippets'][0]['code']

    return cpp_template


        

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("使用方法: python script.py <题目编号>")
        sys.exit(1)
        
    try:
        problem_number = int(sys.argv[1])
        create_leetcode_file(problem_number)
    except ValueError:
        print("请输入有效的题目编号")
