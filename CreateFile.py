import json
import os
import sys
from pathlib import Path

def get_leetcode_problem_info(problem_number, json_file="LeetCodeInfo.json"):
    try:
        # 读取本地JSON文件
        with open(json_file, 'r', encoding='utf-8') as f:
            data = json.load(f)
            
        # 查找对应题号的问题
        for problem in data["stat_status_pairs"]:
            if str(problem["stat"]["frontend_question_id"]) == str(problem_number):
                return problem["stat"]["question__title"]
                
        return None
            
    except Exception as e:
        print(f"读取题目信息时出错: {e}")
        return None

def create_leetcode_file(problem_number):
    # 获取题目标题
    title = get_leetcode_problem_info(problem_number)
    
    if not title:
        print(f"无法获取题目 {problem_number} 的信息")
        return
    
    # 移除标题中的特殊字符并直接连接
    title = title.replace(' ', '').replace('-', '').replace('(', '').replace(')', '')
    
    # 创建新文件名
    new_filename = f"{problem_number}_{title}.cpp"
    
    # 模板文件路径
    template_path = "Template.cpp"
    
    try:
        # 检查模板文件是否存在
        if not os.path.exists(template_path):
            print("模板文件 Template.cpp 不存在！")
            return
            
        # 复制模板文件并重命名
        with open(template_path, 'r') as source:
            content = source.read()
            
        with open(new_filename, 'w') as target:
            target.write(content)
            
        print(f"成功创建文件: {new_filename}")
        
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
