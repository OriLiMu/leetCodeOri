import requests
import json
from bs4 import BeautifulSoup

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

# 示例：获取测试编号为 1 的 C++ 模板
test_number = 1  # 测试编号
cookie = "aliyungf_tc=450b3903767118be05b2d26622beb9c374f7959c0fa62d0318cd9188eb2270cd; _bl_uid=pUmbt6jma2j8vtos3c84gp1ua2C7; csrftoken=XnirkmlygGs0mSRkRo5OageVVEOp3eQUwAyLeqbbweOK60XJ0dcJNGgBKwPhDryz; LEETCODE_SESSION=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJfYXV0aF91c2VyX2lkIjoiNzc4NzciLCJfYXV0aF91c2VyX2JhY2tlbmQiOiJhdXRoZW50aWNhdGlvbi5hdXRoX2JhY2tlbmRzLlBob25lQXV0aGVudGljYXRpb25CYWNrZW5kIiwiX2F1dGhfdXNlcl9oYXNoIjoiMDNhZDQ0YTQ2YzcxNjFjNDQ2YTFhNGMyYzNmYWExNTU4ZDAwOGVhNjRjMjIwMzA1NjhjMmU3M2VlZmYwZmJlYiIsImlkIjo3Nzg3NywiZW1haWwiOiI1MTMyNzgyMzZAcXEuY29tIiwidXNlcm5hbWUiOiJvcmlnYW1pIiwidXNlcl9zbHVnIjoib3JpZ2FtaSIsImF2YXRhciI6Imh0dHBzOi8vYXNzZXRzLmxlZXRjb2RlLmNuL2FsaXl1bi1sYy11cGxvYWQvdXNlcnMvb3JpZ2FtaS9hdmF0YXJfMTcyMTc1NjY0MS5wbmciLCJwaG9uZV92ZXJpZmllZCI6dHJ1ZSwiZGV2aWNlX2lkIjoiZWI5ZDIwMTljMjJkODI5MGMzM2NkYjdiYzFlYzk3ZjciLCJpcCI6IjE4My4xOTcuNzEuMjMwIiwiX3RpbWVzdGFtcCI6MTczNzY5MjM5OS4xMTk0NDUsImV4cGlyZWRfdGltZV8iOjE3NDAyNTA4MDAsInZlcnNpb25fa2V5XyI6MCwibGF0ZXN0X3RpbWVzdGFtcF8iOjE3Mzg0ODgwODV9.fvDYsYGcNABB-5Vj9UyrOQonOpvBe6uXo0TLHT0V1vc; sl-session=hukoEZnmtGenW6Kp6/JUug=="  # 替换为你的实际 Cookie

try:
    template = get_cpp_template_by_test_number(test_number, cookie)
    # 将模板写入文件
    with open("Template.cpp", "w", encoding="utf-8") as file:
        file.write(template)
    print("C++ template has been written to leetcode_cpp_template.txt")
except Exception as e:
    print(f"Error: {e}")

