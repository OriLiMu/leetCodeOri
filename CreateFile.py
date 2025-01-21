import json
import os
import sys
from pathlib import Path

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
    
    template_path = "Template.cpp"
    
    try:
        if not os.path.exists(template_path):
            print("模板文件 Template.cpp 不存在！")
            return
            
        with open(template_path, 'r') as source:
            content = source.read()
            
        with open(new_filename, 'w') as target:
            target.write(content)
            
        print(f"成功创建文件: {new_filename}")
        os.system('nvim ' + new_filename)
        
    except Exception as e:
        print(f"创建文件时出错: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("使用方法: python script.py <题目编号>")
        sys.exit(1)
        
    try:
        problem_number = int(sys.argv[1])
        create_leetcode_file(problem_number)
    except ValueError:
        print("请输入有效的题目编号")
