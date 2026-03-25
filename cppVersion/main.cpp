-- Global variable
local Util = require("lazyvim.util")

local KeymapFile = "/home/lizhe/.config/nvim/lua/config/keymaps.lua"
local AutocmdFile = "/home/lizhe/.config/nvim/lua/config/autocmds.lua"
local DiaryFile = "/home/lizhe/OriNote/notes/Ori/日记.事件驱动.md"
local RimeCustomizeWord = "/home/lizhe/.config/fcitx5/rime/custom_phrase/custom_phrase.txt"
local keymap = vim.api.nvim_set_keymap

vim.api.nvim_set_keymap("n", "<F1>", "<Nop>", { noremap = true, silent = true })

vim.api.nvim_set_keymap("n", "<F1>", "<Nop>", { noremap = true, silent = true })
keymap("n", "<leader>jt", "<cmd>lua GetCharUnderCursor()<CR>", { noremap = true, silent = true })

-- insert mode keymaps
-- Map Ctrl-l to move right in insert mode
vim.keymap.set("i", "<C-l>", "<Right>", { noremap = true, desc = "Move cursor right" })

-- Smart semicolon mapping: if cursor is before "]}), move right instead of typing semicolon
local function smart_semicolon()
  local cursor = vim.api.nvim_win_get_cursor(0)
  local row = cursor[1] - 1 -- 0-based indexing
  local col = cursor[2]

  -- Get current line
  local line = vim.api.nvim_buf_get_lines(0, row, row + 1, false)[1] or ""

  -- Check if there's a character to the right of cursor
  if col < #line then
    local next_char = line:sub(col + 1, col + 1)
    -- If next character is one of the closing brackets/quotes (except parentheses), move right
    if next_char == '"' or next_char == "]" or next_char == "}" then
      return "<Right>"
    end
  end

  -- Otherwise, type semicolon
  return ";"
end

-- Map semicolon in insert mode with smart behavior
-- vim.keymap.set("i", ";", smart_semicolon, { expr = true, noremap = true, desc = "Smart semicolon" })

-- Smart space mapping: if cursor is before "]", move right instead of typing space
local function smart_space()
  -- Only enable smart space in C++ files
  local filetype = vim.bo.filetype
  if not (filetype == "cpp" or filetype == "c" or filetype == "cxx") then
    return " "
  end

  local cursor = vim.api.nvim_win_get_cursor(0)
  local row = cursor[1] - 1 -- 0-based indexing
  local col = cursor[2]

  -- Get current line
  local line = vim.api.nvim_buf_get_lines(0, row, row + 1, false)[1] or ""

  -- Check if there's a character to the right of cursor
  if col < #line then
    local next_char = line:sub(col + 1, col + 1)
    -- If next character is ], move right
    if next_char == "]" then
      return "<Right>"
    end
  end

  -- Otherwise, type space
  return " "
end

-- Map space in insert mode with smart behavior
-- vim.keymap.set("i", " ", smart_space, { expr = true, noremap = true, desc = "Smart space" })

-- find/search tool
keymap("n", "<leader>fr", "<cmd>lua Snacks.picker.registers()<CR>", { noremap = true, silent = true })
-- keymap("n", "<A-b>", "<cmd>lua Snacks.picker.buffers()<CR>", { noremap = true, silent = true })
keymap("n", "gt", "<cmd>lua Snacks.picker.buffers()<CR>", { noremap = true, silent = true })
keymap(
  "n",
  "T",
  "<cmd>lua Snacks.picker.buffers()<CR>",
  { noremap = true, silent = true, desc = "search open buffers" }
)

-- Edit init.lua
-- smart w and b
keymap("n", "w", "<cmd>lua Custom_forward()<CR>", { noremap = true, silent = true })
keymap("n", "b", "<cmd>lua Custom_backward()<CR>", { noremap = true, silent = true })

-- keymap("n", "<leader>rr", "<cmd>edit $MYVIMRC<CR>", { silent = true, desc = "edit config" })
keymap("n", "<leader>cb", "<cmd>BufDel<CR>", { silent = true, desc = "Close Buffer" })
-- keymap("n", "B", "<cmd>b#<CR>", { silent = true, desc = "Close Buffer" })
keymap("n", "<A-b>", "<cmd>b#<CR>", { silent = true, desc = "Close Buffer" })
keymap("v", "<leader>y", '"+y', { silent = true, noremap = true })
keymap("v", "<leader>cc", '"+y', { silent = true, noremap = true })
keymap("v", "<leader>cy", '"+y', { silent = true, noremap = true })
keymap("n", "<leader>ca", '<ESC>mzggVG"+y`z', { silent = true })
keymap("n", "<leader>r`", ":lua SurroundWordWithBackticks()<CR>", { noremap = true, silent = true })

vim.keymap.set("i", "<C-v>", "<C-r>+", { desc = "Paste from system clipboard" })
vim.keymap.set("n", "yd", function()
  local file_path = vim.fn.expand("%:p")
  if file_path == "" then
    vim.notify("当前缓冲区没有文件路径", vim.log.levels.WARN)
    return
  end

  vim.fn.setreg("+", file_path)
  vim.notify("已复制当前文件绝对路径: " .. file_path, vim.log.levels.INFO)
end, { silent = true, desc = "复制当前缓冲区绝对路径" })

vim.keymap.set("n", "<A-o>", "<cmd>lua Snacks.picker.recent()<CR>", { noremap = true, silent = true, buffer = true })

-- reselect the indent part
vim.keymap.set("v", ">", ">gv", { noremap = true, silent = true })
vim.keymap.set("v", "<", "<gv", { noremap = true, silent = true })

-- 定义 <leader>df 删除当前文件
vim.keymap.set("n", "<leader>df", function()
  -- 获取当前文件的路径
  local file_path = vim.fn.expand("%:p")
  if file_path == "" then
    print("No file is open.")
    return
  end

  -- 确认是否删除
  local confirm = vim.fn.input("Delete file " .. file_path .. "? [y/N] ")
  if confirm:lower() ~= "y" then
    print("Deletion canceled.")
    return
  end

  -- 删除文件
  local success, err = os.remove(file_path)
  if not success then
    print("Failed to delete file: " .. err)
    return
  end

  -- 关闭当前缓冲区
  vim.cmd("bd!")
  print("File deleted: " .. file_path)
end, { desc = "Delete current file" })

-- keymap("n", "<A-l>", "<C-w>l", { silent = true })
-- keymap("n", "<A-h>", "<C-w>h", { silent = true })
keymap("n", "L", "<C-w>l", { silent = true })
keymap("n", "H", "<C-w>h", { silent = true })
keymap("n", "K", "<C-w>k", { silent = true })

keymap("n", "<S-h>", "<cmd>BufferLineCyclePrev<CR>", { silent = true })
keymap("n", "<S-l>", "<cmd>BufferLineCycleNext<CR>", { silent = true })
-- Smart window/buffer close
function _G.smart_close()
  -- 获取当前标签页
  local current_tab = vim.api.nvim_get_current_tabpage()
  -- 获取当前标签页中的所有窗口
  local wins = vim.api.nvim_tabpage_list_wins(current_tab)
  -- 过滤掉特殊窗口（如浮动窗口）
  local normal_wins = vim.tbl_filter(function(win)
    return vim.api.nvim_win_get_config(win).relative == ""
  end, wins)
  local win_count = #normal_wins

  -- 打印调试信息
  vim.notify(string.format("当前标签页普通窗口数量: %d", win_count), vim.log.levels.INFO)

  -- 获取当前窗口信息
  local current_win = vim.api.nvim_get_current_win()
  local current_buf = vim.api.nvim_get_current_buf()

  -- 检查是否是特殊buffer（如NvimTree、Telescope等）
  local buf_type = vim.api.nvim_buf_get_option(current_buf, "buftype")
  local buf_name = vim.api.nvim_buf_get_name(current_buf)
  local win_type = vim.api.nvim_win_get_config(current_win).relative

  vim.notify(
    string.format("窗口类型: %s, buffer类型: %s, buffer名称: %s", win_type, buf_type, buf_name),
    vim.log.levels.INFO
  )

  if win_count > 1 then
    vim.notify("执行关闭窗口操作", vim.log.levels.INFO)
    vim.cmd("quit")
  else
    -- 如果是特殊buffer，使用quit
    if buf_type ~= "" or win_type ~= "" then
      vim.notify("特殊buffer/窗口，执行quit", vim.log.levels.INFO)
      vim.cmd("quit")
    else
      vim.notify("普通buffer，执行BufDel", vim.log.levels.INFO)
      vim.cmd("BufDel")
    end
  end
end

-- 修改 q 键映射，添加条件判断
keymap(
  "n",
  "q",
  "<cmd>lua require('config.utils').smart_quit()<CR>",
  { silent = true, desc = "Smart close window/buffer" }
)

-- alt j move down to the split window
vim.keymap.set("n", "<A-j>", "<C-w>j", { silent = true })

-- alt k move up to the split window
vim.keymap.set("n", "<A-k>", "<C-w>k", { silent = true })

vim.api.nvim_set_keymap("n", "X", ":lua Restart_neovim()<CR>", { noremap = true, silent = true })

vim.keymap.set("n", "<A-r>", function()
  -- 执行原来的 source 命令
  vim.cmd("source $MYVIMRC")
  -- 重新加载键位映射
  package.loaded["config.keymaps"] = nil
  require("config.keymaps")
  -- 重新加载 autocmds
  package.loaded["config.autocmds"] = nil
  require("config.autocmds")
  -- 重新加载 obsidian.nvim 插件
  package.loaded["obsidian"] = nil
  require("obsidian").setup({
    workspaces = {
      {
        name = "Ori",
        path = "~/OriNote/notes/Ori/",
      },
    },
    picker = {
      name = "telescope.nvim",
      -- note_mappings = {
      --   new = "<C-x>",
      --   insert_link = "<a-i>",
      -- },
      -- tag_mappings = {
      --   tag_note = "<C-x>",
      --   insert_tag = "<a-i>",
      -- },
    },
    recent_files = {
      enabled = true,
      show_sidewindow = false,
      max_files = 20,
    },
    notes_subdir = "notes",
    log_level = vim.log.levels.INFO,
    daily_notes = {
      folder = "notes/dailies",
      date_format = "%Y-%m-%d",
      alias_format = "%B %-d, %Y",
      default_tags = { "daily-notes" },
    },
    completion = {
      nvim_cmp = true,
      min_chars = 2,
    },
    mappings = {
      ["gf"] = {
        action = function()
          return require("obsidian").util.gf_passthrough()
        end,
        opts = { noremap = false, expr = true, buffer = true },
      },
      ["<leader>ch"] = {
        action = function()
          return require("obsidian").util.toggle_checkbox()
        end,
        opts = { buffer = true },
      },
      ["<cr>"] = {
        action = function()
          return require("obsidian").util.smart_action()
        end,
        opts = { buffer = true, expr = true },
      },
    },
    new_notes_location = "notes_subdir",
    preferred_link_style = "wiki",
    disable_frontmatter = false,
    sort_by = "modified",
    sort_reversed = true,
    search_max_lines = 1000,
    open_notes_in = "current",
    callbacks = {
      post_setup = function(client)
        -- Override the insert_link picker to use recent files
        local original_resolve_note_async_with_picker_fallback = client.resolve_note_async_with_picker_fallback

        client.resolve_note_async_with_picker_fallback = function(self, search_term, callback)
          -- 调试信息1: 函数入口

          local recent_files = require("obsidian.recent_files")
          local note = require("obsidian.note")

          -- Try to get recent files first
          local recent_notes = {}
          local recent_paths = recent_files.recent_files

          -- 调试信息2: recent_files 数据检查
          if recent_paths then
            for i, path in ipairs(recent_paths) do
            end
          else
          end

          if recent_paths and #recent_paths > 0 then
            for _, file_path in ipairs(recent_paths) do
              if file_path:match("%.md$") then
                -- 调试信息3: 路径处理
                local vault_path = self:vault_relative_path(file_path)

                if vault_path then
                  local ok, note_obj = pcall(note.from_file, file_path)
                  -- 调试信息4: note 对象创建
                  if ok and note_obj then
                    print(note_obj.id or "nil", "title:", note_obj.title or "nil")
                    table.insert(recent_notes, note_obj)
                  else
                  end
                else
                end
              else
              end
            end

            -- 调试信息5: picker 调用前检查
            for i, note in ipairs(recent_notes) do
              print(note.id or "nil", "title:", note.title or "nil", "path:", note.path or "nil")
            end

            -- If we have recent notes, use them for the picker
            if #recent_notes > 0 then
              local picker = self:picker()
              if picker then
                picker:pick_note(recent_notes, {
                  prompt_title = "Recent Files (Obsidian)",
                  callback = function(note)
                    if note then
                    else
                    end
                    callback(note)
                  end,
                })
                return
              else
              end
            else
            end
          end

          -- 调试信息6: 回退机制
          print(type(original_resolve_note_async_with_picker_fallback))

          -- Fall back to original behavior
          return original_resolve_note_async_with_picker_fallback(self, search_term, callback)
        end
      end,
    },
  })
  -- save file
  vim.cmd("write")
  -- 提示成功信息
  print("Neovim 和 Obsidian 插件重新加载成功！")
end, { noremap = true, silent = true })

-- leetCode
-- 设置快捷键映射
keymap(
  "n",
  "<leader>cs",
  ":lua CopySolutionClass()<CR>",
  { silent = true, desc = "Copy Solution Content", noremap = true }
)

-- -- 设置切换cout过滤的快捷键
-- keymap(
--   "n",
--   "<leader>csf",
--   ":lua ToggleCoutFilter()<CR>",
--   { silent = true, desc = "Toggle cout filter for Solution copy", noremap = true }
-- )

-- build and run cmake
vim.keymap.set("n", "<leader>rr", compile_and_run, {
  desc = "Compile and run CMake project",
})

-- Edit command

-- Clear content between tag
function ClearBetweenTags()
  vim.api.nvim_feedkeys(vim.api.nvim_replace_termcodes("T>", true, true, true), "n", true)
  vim.api.nvim_feedkeys(vim.api.nvim_replace_termcodes("ct<", true, true, true), "n", true)
end

-- 全局变量控制是否过滤cout语句
_G.filter_cout_in_copy = true

function ToggleCoutFilter()
  _G.filter_cout_in_copy = not _G.filter_cout_in_copy
  local status = _G.filter_cout_in_copy and "开启" or "关闭"
  print("Solution类复制时cout过滤已" .. status)
end

local function trim_line(line)
  return line:match("^%s*(.-)%s*$")
end

local function is_print_start_line(trimmed)
  local uncommented = trimmed:gsub("^//%s*", "")

  return uncommented:match("^cout%s*<<")
    or uncommented:match("^std::cout%s*<<")
    or uncommented:match("^cerr%s*<<")
    or uncommented:match("^std::cerr%s*<<")
    or uncommented:match("^clog%s*<<")
    or uncommented:match("^std::clog%s*<<")
    or uncommented:match("^printf%s*%(")
    or uncommented:match("^std::printf%s*%(")
end

local function is_blank_or_comment_line(trimmed)
  return trimmed == "" or trimmed:match("^//")
end

local function is_control_block_start(trimmed)
  return trimmed:match("^for%s*%(")
    or trimmed:match("^if%s*%(")
    or trimmed:match("^while%s*%(")
    or trimmed:match("^else%s*{")
    or trimmed:match("^else%s*$")
end

local function find_block_end(lines, block_start, scope_end)
  local brace_count = 0
  local has_opening_brace = false

  for line_number = block_start, scope_end do
    for char in lines[line_number]:gmatch(".") do
      if char == "{" then
        brace_count = brace_count + 1
        has_opening_brace = true
      elseif char == "}" then
        brace_count = brace_count - 1
        if has_opening_brace and brace_count == 0 then
          return line_number
        end
      end
    end
  end

  return nil
end

local function expand_print_range(lines, start_line, end_line, scope_start, scope_end)
  local expanded_start = start_line
  local expanded_end = end_line

  while expanded_start > scope_start do
    local previous_trimmed = trim_line(lines[expanded_start - 1])
    if not is_blank_or_comment_line(previous_trimmed) then
      break
    end
    expanded_start = expanded_start - 1
  end

  while expanded_end < scope_end do
    local next_trimmed = trim_line(lines[expanded_end + 1])
    if not is_blank_or_comment_line(next_trimmed) then
      break
    end
    expanded_end = expanded_end + 1
  end

  return expanded_start, expanded_end
end

local function merge_ranges(ranges)
  if #ranges == 0 then
    return {}
  end

  table.sort(ranges, function(left, right)
    return left[1] < right[1]
  end)

  local merged = { { ranges[1][1], ranges[1][2] } }

  for i = 2, #ranges do
    local current = ranges[i]
    local last_merged = merged[#merged]

    if current[1] <= last_merged[2] + 1 then
      last_merged[2] = math.max(last_merged[2], current[2])
    else
      table.insert(merged, { current[1], current[2] })
    end
  end

  return merged
end

local function find_solution_class_range(lines)
  local start_line = -1
  local end_line = -1
  local brace_count = 0
  local has_opening_brace = false

  for i, line in ipairs(lines) do
    if start_line == -1 then
      if line:match("^%s*class%s+Solution[%s:{]") then
        start_line = i
      end
    end

    if start_line ~= -1 then
      for char in line:gmatch(".") do
        if char == "{" then
          brace_count = brace_count + 1
          has_opening_brace = true
        elseif char == "}" then
          brace_count = brace_count - 1
        end
      end

      if has_opening_brace and brace_count == 0 and line:match("^%s*};?%s*$") then
        end_line = i
        break
      end
    end
  end

  return start_line, end_line
end

local function find_outermost_print_only_block(lines, target_line, scope_start, scope_end)
  local best_start = nil
  local best_end = nil

  for line_number = target_line, scope_start, -1 do
    local trimmed = trim_line(lines[line_number])

    if is_control_block_start(trimmed) then
      local block_end = find_block_end(lines, line_number, scope_end)

      if block_end and target_line >= line_number and target_line <= block_end then
        if is_cout_only_block(lines, line_number, block_end) then
          best_start = line_number
          best_end = block_end
        end
      end
    end
  end

  return best_start, best_end
end

local function collect_print_ranges(lines, scope_start, scope_end)
  local ranges = {}
  local processed_lines = {}

  for line_number = scope_start, scope_end do
    if not processed_lines[line_number] then
      local trimmed = trim_line(lines[line_number])

      if is_print_start_line(trimmed) then
        local range_start, range_end
        local block_start, block_end = find_outermost_print_only_block(lines, line_number, scope_start, scope_end)

        if block_start and block_end and is_cout_only_block(lines, block_start, block_end) then
          range_start = block_start
          range_end = block_end
        else
          local statement_lines = find_cout_statement_lines(lines, line_number, scope_end)
          range_start = statement_lines[1]
          range_end = statement_lines[#statement_lines]
        end

        range_start, range_end = expand_print_range(lines, range_start, range_end, scope_start, scope_end)
        table.insert(ranges, { range_start, range_end })

        for i = range_start, range_end do
          processed_lines[i] = true
        end
      end
    end
  end

  return merge_ranges(ranges)
end

function CopySolutionClass()
  -- 获取当前buffer的所有行
  local lines = vim.api.nvim_buf_get_lines(0, 0, -1, false)
  local start_line, end_line = find_solution_class_range(lines)

  -- 如果找到了Solution类
  if start_line ~= -1 and end_line ~= -1 then
    -- 获取Solution类的内容
    local solution_lines = vim.api.nvim_buf_get_lines(0, start_line - 1, end_line, false)

    local filtered_lines = {}

    if _G.filter_cout_in_copy then
      local print_ranges = collect_print_ranges(lines, start_line, end_line)
      local range_index = 1

      for line_number = start_line, end_line do
        local current_range = print_ranges[range_index]

        while current_range and line_number > current_range[2] do
          range_index = range_index + 1
          current_range = print_ranges[range_index]
        end

        local is_in_print_range = current_range and line_number >= current_range[1] and line_number <= current_range[2]

        if not is_in_print_range then
          table.insert(filtered_lines, lines[line_number])
        end
      end
    else
      -- 不过滤，直接复制所有内容
      filtered_lines = solution_lines
    end

    local solution_content = table.concat(filtered_lines, "\n")
    -- 复制到系统剪贴板
    vim.fn.setreg("+", solution_content)
    local filter_status = _G.filter_cout_in_copy and "（已去除打印代码）" or "（包含所有内容）"
    print("Solution类已复制到系统剪贴板" .. filter_status)
  else
    print("未找到Solution类")
  end
end

function ToggleCoutComments()
  local lines = vim.api.nvim_buf_get_lines(0, 0, -1, false)

  -- 查找Solution类的范围
  local solution_start = -1
  local solution_end = -1

  for i, line in ipairs(lines) do
    if line:match("^class%s+Solution") then
      solution_start = i
    elseif solution_start ~= -1 and line:match("^};") then
      solution_end = i
      break
    end
  end

  if solution_start == -1 then
    solution_start = 1
    solution_end = #lines
    print("未找到Solution类，将处理整个文件的cout")
  else
    print(string.format("只处理Solution类内的cout（第%d行到第%d行）", solution_start, solution_end))
  end

  -- 寻找所有包含cout的行
  local cout_lines = {}
  for i = solution_start, solution_end do
    local line = lines[i]
    local trimmed = line:match("^%s*(.-)%s*$")

    -- 检查是否包含cout（包括已注释的）
    if trimmed:match("cout") or trimmed:match("printf") then
      table.insert(cout_lines, i)
    end
  end

  if #cout_lines == 0 then
    print("在指定范围内未找到包含cout的行")
    return
  end

  -- 分析代码块结构，找出需要完整注释的代码块
  local blocks_to_comment = {}
  local processed_lines = {}

  for _, cout_line in ipairs(cout_lines) do
    if processed_lines[cout_line] then
      goto continue
    end

    -- 检查cout行是否在控制结构内
    local block_start, block_end = find_enclosing_block(lines, cout_line, solution_start, solution_end)

    if block_start and block_end then
      -- 检查这个代码块是否只包含cout相关的语句
      if is_cout_only_block(lines, block_start, block_end) then
        -- 标记整个代码块
        table.insert(blocks_to_comment, { block_start, block_end, "block" })
        for i = block_start, block_end do
          processed_lines[i] = true
        end
      else
        -- 只标记cout行本身
        local cout_block_lines = find_cout_statement_lines(lines, cout_line, solution_end)
        table.insert(blocks_to_comment, { cout_block_lines[1], cout_block_lines[#cout_block_lines], "cout" })
        for _, line_num in ipairs(cout_block_lines) do
          processed_lines[line_num] = true
        end
      end
    else
      -- 没有在控制结构内，只处理cout语句本身
      local cout_block_lines = find_cout_statement_lines(lines, cout_line, solution_end)
      table.insert(blocks_to_comment, { cout_block_lines[1], cout_block_lines[#cout_block_lines], "cout" })
      for _, line_num in ipairs(cout_block_lines) do
        processed_lines[line_num] = true
      end
    end

    ::continue::
  end

  -- 检查是否有未注释的块
  local has_uncommented = false
  for _, block in ipairs(blocks_to_comment) do
    local start_line, end_line = block[1], block[2]
    for i = start_line, end_line do
      local line = lines[i]
      local trimmed = line:match("^%s*(.-)%s*$")
      if trimmed ~= "" and not trimmed:match("^//") then
        has_uncommented = true
        break
      end
    end
    if has_uncommented then
      break
    end
  end

  -- 执行注释/取消注释
  local action = has_uncommented and "comment" or "uncomment"
  local total_lines = 0

  for _, block in ipairs(blocks_to_comment) do
    local start_line, end_line = block[1], block[2]
    for i = start_line, end_line do
      local line = lines[i]
      local new_line

      if action == "comment" then
        local indent = line:match("^(%s*)")
        local content = line:match("^%s*(.*)$")
        if content ~= "" then -- 不注释空行
          new_line = indent .. "// " .. content
        else
          new_line = line
        end
      else
        if line:match("^(%s*)// (.*)$") then
          local indent, content = line:match("^(%s*)// (.*)$")
          new_line = indent .. content
        elseif line:match("^(%s*)//%s*(.*)$") then
          local indent, content = line:match("^(%s*)//%s*(.*)$")
          new_line = indent .. content
        else
          new_line = line
        end
      end

      vim.api.nvim_buf_set_lines(0, i - 1, i, false, { new_line })
      total_lines = total_lines + 1
    end
  end

  local action_text = action == "comment" and "已注释" or "已取消注释"
  local scope_text = solution_start == 1 and solution_end == #lines and "整个文件" or "Solution类内"
  print(
    string.format(
      "%s %s %d 行包含cout的代码块（%d个代码块）",
      action_text,
      scope_text,
      total_lines,
      #blocks_to_comment
    )
  )
end

-- 辅助函数：查找包围cout行的代码块
function find_enclosing_block(lines, cout_line, solution_start, solution_end)
  local block_start = nil
  local block_end = nil

  -- 向上查找控制结构的开始
  for i = cout_line - 1, solution_start, -1 do
    local line = lines[i]
    local trimmed = line:match("^%s*(.-)%s*$")

    -- 检查是否是控制结构的开始
    if
      trimmed:match("^for%s*%(")
      or trimmed:match("^if%s*%(")
      or trimmed:match("^while%s*%(")
      or trimmed:match("^else%s*{")
      or trimmed:match("^else%s*$")
    then
      block_start = i
      break
    end

    -- 如果遇到函数定义或其他代码块结束，停止查找
    if trimmed:match("^}") and not trimmed:match("^}%s*else") then
      break
    end
  end

  if not block_start then
    return nil, nil
  end

  -- 向下查找对应的结束大括号
  local brace_count = 0
  local found_opening_brace = false

  for i = block_start, solution_end do
    local line = lines[i]
    local trimmed = line:match("^%s*(.-)%s*$")

    -- 计算大括号
    for char in trimmed:gmatch(".") do
      if char == "{" then
        brace_count = brace_count + 1
        found_opening_brace = true
      elseif char == "}" then
        brace_count = brace_count - 1
        if brace_count == 0 and found_opening_brace then
          block_end = i
          return block_start, block_end
        end
      end
    end
  end

  return nil, nil
end

-- 辅助函数：检查代码块是否只包含cout相关语句
function is_cout_only_block(lines, block_start, block_end)
  local meaningful_lines = 0
  local cout_lines = 0

  for i = block_start, block_end do
    local line = lines[i]
    local trimmed = line:match("^%s*(.-)%s*$")

    -- 跳过空行、注释行、控制结构行和大括号行
    if
      trimmed ~= ""
      and not trimmed:match("^//")
      and not trimmed:match("^{%s*$")
      and not trimmed:match("^}%s*$")
      and not trimmed:match("^for%s*%(")
      and not trimmed:match("^if%s*%(")
      and not trimmed:match("^while%s*%(")
      and not trimmed:match("^else")
    then
      meaningful_lines = meaningful_lines + 1

      -- 检查是否是cout相关的行
      if trimmed:match("cout") or trimmed:match("printf") or trimmed:match("^<<") then -- cout语句的延续行
        cout_lines = cout_lines + 1
      end
    end
  end

  -- 如果所有有意义的行都是cout相关的，返回true
  return meaningful_lines > 0 and cout_lines == meaningful_lines
end

-- 辅助函数：查找cout语句的所有行（包括多行）
function find_cout_statement_lines(lines, start_line, solution_end)
  local result = { start_line }
  local current_line = start_line

  local line = lines[current_line]
  local trimmed = line:match("^%s*(.-)%s*$")
  local is_commented = trimmed:match("^//")

  -- 如果当前行不以分号结尾，继续查找
  local current_trimmed = is_commented and trimmed:gsub("^//%s*", "") or trimmed

  while not current_trimmed:match(";%s*$") and current_line < solution_end do
    current_line = current_line + 1
    if current_line <= solution_end then
      local next_line = lines[current_line]
      local next_trimmed = next_line:match("^%s*(.-)%s*$")

      local is_continuation = false

      if is_commented then
        if next_trimmed:match("^//") then
          local next_content = next_trimmed:gsub("^//%s*", "")
          if next_content:match("^<<") or next_content:match("^%w") then
            is_continuation = true
          end
        end
      else
        if next_trimmed:match("^<<") or next_trimmed:match("^%s*<<") then
          is_continuation = true
        end
      end

      if is_continuation then
        table.insert(result, current_line)
        current_trimmed = is_commented and next_trimmed:gsub("^//%s*", "") or next_trimmed
      else
        break
      end
    end
  end

  return result
end

keymap("n", "ci>", ":lua ClearBetweenTags()<CR>", { noremap = true, silent = true })
keymap(
  "n",
  "<leader>od",
  ":lua ToggleCoutComments()<CR>",
  { noremap = true, silent = true, desc = "Toggle cout comments in Solution class" }
)

-- 添加一个函数来切换main函数中的cout
function ToggleMainCoutComments()
  local lines = vim.api.nvim_buf_get_lines(0, 0, -1, false)
  local main_start = -1
  local main_end = -1

  -- 查找main函数的范围
  for i, line in ipairs(lines) do
    if line:match("int%s+main%s*%(") then
      main_start = i
    elseif main_start ~= -1 and line:match("^}%s*$") then
      main_end = i
      break
    end
  end

  if main_start == -1 then
    print("未找到main函数")
    return
  end

  print(string.format("处理main函数内的cout（第%d行到第%d行）", main_start, main_end))

  local cout_blocks = {}
  local processed_lines = {}

  -- 在main函数范围内查找cout
  for i = main_start, main_end do
    local line = lines[i]
    if processed_lines[i] then
      goto continue
    end

    local trimmed = line:match("^%s*(.-)%s*$")
    local is_commented_cout = false
    local is_cout_start = false

    if trimmed:match("^//.*cout") or trimmed:match("^//.*std::cout") or trimmed:match("^//.*printf") then
      is_cout_start = true
      is_commented_cout = true
    elseif trimmed:match("cout") or trimmed:match("std::cout") or trimmed:match("printf%s*%(") then
      if trimmed:match("cout%s*<<") or trimmed:match("std::cout%s*<<") or trimmed:match("printf%s*%(") then
        is_cout_start = true
        is_commented_cout = false
      end
    end

    if is_cout_start then
      local block_lines = { i }
      local current_line = i
      processed_lines[current_line] = true

      local current_trimmed = trimmed
      if is_commented_cout then
        current_trimmed = current_trimmed:gsub("^//%s*", "")
      end

      while not current_trimmed:match(";%s*$") and current_line < main_end do
        current_line = current_line + 1
        if current_line <= main_end then
          local next_line = lines[current_line]
          local next_trimmed = next_line:match("^%s*(.-)%s*$")

          local is_continuation = false

          if is_commented_cout then
            if next_trimmed:match("^//") then
              local next_content = next_trimmed:gsub("^//%s*", "")
              if next_content:match("^<<") or next_content:match("^%w") then
                is_continuation = true
              end
            end
          else
            if
              next_trimmed:match("^<<")
              or next_trimmed:match("^%s*<<")
              or (
                next_trimmed ~= ""
                and not next_trimmed:match("^//")
                and not next_trimmed:match("^%w+%s*%(")
                and not next_trimmed:match("^}")
              )
            then
              is_continuation = true
            end
          end

          if is_continuation then
            table.insert(block_lines, current_line)
            processed_lines[current_line] = true

            if is_commented_cout then
              current_trimmed = next_trimmed:gsub("^//%s*", "")
            else
              current_trimmed = next_trimmed
            end
          else
            break
          end
        end
      end

      table.insert(cout_blocks, { lines = block_lines, is_commented = is_commented_cout })
    end

    ::continue::
  end

  if #cout_blocks == 0 then
    print("在main函数内未找到包含cout的行")
    return
  end

  local has_uncommented = false
  for _, block in ipairs(cout_blocks) do
    if not block.is_commented then
      has_uncommented = true
      break
    end
  end

  local modified_lines = {}
  local action = has_uncommented and "comment" or "uncomment"
  local total_lines = 0

  for _, block in ipairs(cout_blocks) do
    for _, line_num in ipairs(block.lines) do
      local line = lines[line_num]
      local new_line

      if action == "comment" then
        local indent = line:match("^(%s*)")
        local content = line:match("^%s*(.*)$")
        new_line = indent .. "// " .. content
      else
        if line:match("^(%s*)// (.*)$") then
          local indent, content = line:match("^(%s*)// (.*)$")
          new_line = indent .. content
        elseif line:match("^(%s*)//%s*(.*)$") then
          local indent, content = line:match("^(%s*)//%s*(.*)$")
          new_line = indent .. content
        else
          new_line = line
        end
      end

      table.insert(modified_lines, { line_num, new_line })
      total_lines = total_lines + 1
    end
  end

  for _, modification in ipairs(modified_lines) do
    local line_num, new_line = modification[1], modification[2]
    vim.api.nvim_buf_set_lines(0, line_num - 1, line_num, false, { new_line })
  end

  local action_text = action == "comment" and "已注释" or "已取消注释"
  print(
    string.format(
      "%s main函数内 %d 行包含cout的代码（%d个cout语句块）",
      action_text,
      total_lines,
      #cout_blocks
    )
  )
end

-- Window maximization toggle
local window_maximized = false
local original_layout = nil

function ToggleWindowMaximize()
  if window_maximized then
    -- Restore original layout
    if original_layout then
      vim.cmd("wincmd =")
      window_maximized = false
      original_layout = nil
      print("Window layout restored")
    end
  else
    -- Save current layout and maximize current window
    original_layout = {}
    local windows = vim.api.nvim_tabpage_list_wins(0)
    for _, win in ipairs(windows) do
      local config = vim.api.nvim_win_get_config(win)
      if config.relative == "" then -- Only normal windows
        original_layout[win] = {
          width = vim.api.nvim_win_get_width(win),
          height = vim.api.nvim_win_get_height(win),
        }
      end
    end

    -- Maximize current window
    vim.cmd("wincmd |")
    vim.cmd("wincmd _")
    window_maximized = true
    print("Window maximized")
  end
end

vim.keymap.set("n", "<leader>oc", function()
  -- Change to the algorithm tests folder
  vim.cmd("cd /home/lizhe/OriNote/notes/Ori/Computer/Alogrithm/Tests")
  print("Changed to algorithm tests folder")

  -- Prompt for test number
  local test_number = vim.fn.input("Enter LeetCode test number: ")
  if test_number == "" then
    print("No test number provided, aborting...")
    return
  end

  -- Validate it's a number
  if not test_number:match("^%d+$") then
    print("Please enter a valid number")
    return
  end

  -- Run the script
  local script_path = "/home/lizhe/OriNote/wikiScripts/Utils/generate_leetcode_md.py"
  local cmd = string.format("python3 %s %s", script_path, test_number)

  print("Running: " .. cmd)
  local output = vim.fn.system(cmd)

  -- Show the output
  print(output)

  -- Check if the file was created and open it
  local filename = string.format("leetcode-%s.md", test_number)
  local file_path = "/home/lizhe/OriNote/notes/Ori/Computer/Alogrithm/Tests/" .. filename

  -- Check if file exists
  local file = io.open(file_path, "r")
  if file then
    file:close()
    vim.cmd("edit " .. file_path)
    print("Opened: " .. filename)
  else
    print("File not found: " .. filename)
  end
end, { silent = true, desc = "Go to algo folder and generate LeetCode MD" })

-- Find references
keymap("n", "<A-S-f>", "<cmd>Trouble lsp_references auto_refresh=false<CR>", { silent = true })
vim.keymap.set("n", "P", function()
  vim.fn.jobstart({ "/home/lizhe/CodeOri/speech-to-text/whisper/voice_client.bash", "toggle" }, { detach = true })
end, { silent = true, desc = "Run voice record script (if not CLion)" })

-- Tmux
-- keymap("n", "<C-h>", "<cmd>TmuxNavigateLeft<CR>", { silent = true, desc = "TmuxNavigateLeft" })
-- keymap("n", "<C-l>", "<cmd>TmuxNavigateRight<CR>", { silent = true, desc = "TmuxNavigateRight" })

-- Goto File Navigation
-- 定义 gx 键映射
vim.keymap.set("n", "gx", function()
  require("config.url_open").open_url_under_cursor()
end, { desc = "Open URL under cursor in Firefox" })

-- Remove unused headers for C/C++ files
vim.keymap.set("n", "<leader>rh", function()
  require("config.utils").remove_unused_headers()
end, { desc = "Remove unused headers" })

-- flash jump line
keymap(
  "n",
  "<leader>jj",
  '<cmd>lua require("flash").jump({search = { mode = "search", max_length = 0 },  label = { after = { 0, 0 }},pattern = "^"})<CR>',
  { silent = true, desc = "jump to line" }
)

-- 定义键映射 <leader>ot 打开指定文件并跳转到主要任务列表
vim.keymap.set("n", "<leader>ot", function()
  -- 打开目标文件
  vim.cmd("e /home/lizhe/OriNote/notes/Ori/OriTask.md")

  -- 等待文件加载完成
  vim.defer_fn(function()
    -- 先跳到文件开头，确保能找到目标
    vim.cmd("normal! gg")
    -- 搜索 "主要任务列表" 文本
    local found_line = vim.fn.search("主要任务列表", "W")

    if found_line > 0 then
      -- 找到后，跳转到段落末尾（使用 } 跳到下一个空行前）
      vim.cmd("normal! }b")
    else
      -- 如果没找到，提示用户
      vim.notify("未找到 '主要任务列表'", vim.log.levels.WARN)
    end
  end, 100)
end, { noremap = true, silent = true, desc = "Open OriTask and go to 主要任务列表" })

-- 定义键映射 <leader>op 打开指定文件
vim.keymap.set("n", "<leader>op", function()
  vim.cmd("e /home/lizhe/OriNote/notes/Ori/思维方法/做事原则方法.md")
  vim.defer_fn(function()
    vim.cmd("normal! }")
  end, 100)
end, { noremap = true, silent = true, desc = "Open OriTask Code Task and go to paragraph end" })

-- vim.keymap.set("n", "f", function()
--   require("flash").jump({ search = { mode = "search" }, label = { after = { 0, 0 } }, pattern = "\\[\\[[^\\]]*\\]\\]" })
-- end, { silent = true, desc = "jump to markdown links" })

vim.keymap.set("n", "<leader>fd", function()
  require("flash").jump({
    matcher = function(win)
      ---@param diag Diagnostic
      return vim.tbl_map(function(diag)
        return {
          pos = { diag.lnum + 1, diag.col },
          end_pos = { diag.end_lnum + 1, diag.end_col - 1 },
        }
      end, vim.diagnostic.get(vim.api.nvim_win_get_buf(win)))
    end,
    action = function(match, state)
      vim.api.nvim_win_call(match.win, function()
        vim.api.nvim_win_set_cursor(match.win, match.pos)
        vim.diagnostic.open_float()
      end)
      state:restore()
    end,
  })
end, { desc = "Flash jump to diagnostics诊断信息" })

keymap("n", "<leader>ok", "<cmd>edit " .. KeymapFile .. "<CR>", { silent = true, desc = "open keymap file" })
keymap("n", "<leader>or", "<cmd>edit " .. DiaryFile .. "<CR>", { silent = true, desc = "打开日记" })
keymap("n", "<leader>rj", "<cmd>edit " .. DiaryFile .. "<CR>", { silent = true, desc = "打开日记" })
keymap("n", "<leader>oa", "<cmd>edit" .. AutocmdFile .. "<CR>", { silent = true, desc = "open autocmd file" })
keymap("n", "<leader>oi", "<cmd>edit" .. RimeCustomizeWord .. "<CR>", { silent = true, desc = "Rime Custom word" })
keymap(
  "n",
  "<leader>om",
  "<cmd>edit /home/lizhe/.config/nvim/snippets/markdown.json<CR>",
  { silent = true, desc = "Open markdown snippets" }
)
-- Navigate to algorithm tests folder and generate LeetCode markdown
vim.keymap.set("n", "<leader>oc", function()
  -- Change to the algorithm tests folder
  vim.cmd("cd /home/lizhe/OriNote/notes/Ori/Computer/Alogrithm/Tests")
  print("Changed to algorithm tests folder")

  -- Prompt for test number
  local test_number = vim.fn.input("Enter LeetCode test number: ")
  if test_number == "" then
    print("No test number provided, aborting...")
    return
  end

  -- Validate it's a number
  if not test_number:match("^%d+$") then
    print("Please enter a valid number")
    return
  end

  -- Run the script
  local script_path = "/home/lizhe/OriNote/wikiScripts/Utils/generate_leetcode_md.py"
  local cmd = string.format("python3 %s %s", script_path, test_number)

  print("Running: " .. cmd)
  local output = vim.fn.system(cmd)

  -- Show the output
  print(output)

  -- Check if the file was created and open it
  local pattern = string.format("%s_*.md", test_number)
  local search_path = "/home/lizhe/OriNote/notes/Ori/Computer/Alogrithm/Tests/"

  -- Use vim.fn.glob to find files matching the pattern
  local files = vim.fn.glob(search_path .. pattern, false, true)

  if #files > 0 then
    -- Open the first matching file
    vim.cmd("edit " .. files[1])
    print("Opened: " .. vim.fn.fnamemodify(files[1], ":t"))
  else
    print("Warning: No file found matching pattern: " .. pattern)
  end
end, { silent = true, desc = "Go to algo folder and generate LeetCode MD" })

-- Run LeetCode markdown generator with input prompt (kept as separate option)
vim.keymap.set("n", "<leader>ol", function()
  local test_number = vim.fn.input("Enter LeetCode test number: ")
  if test_number == "" then
    print("No test number provided, aborting...")
    return
  end

  -- Validate it's a number
  if not test_number:match("^%d+$") then
    print("Please enter a valid number")
    return
  end

  -- Run the script
  local script_path = "/home/lizhe/OriNote/wikiScripts/Utils/generate_leetcode_md.py"
  local cmd = string.format("python3 %s %s", script_path, test_number)

  print("Running: " .. cmd)
  local output = vim.fn.system(cmd)

  -- Show the output
  print(output)

  -- Check if the file was created and open it
  local pattern = string.format("%s_*.md", test_number)
  local search_path = "/home/lizhe/OriNote/notes/Ori/Computer/Alogrithm/Tests/"

  -- Use vim.fn.glob to find files matching the pattern
  local files = vim.fn.glob(search_path .. pattern, false, true)

  if #files > 0 then
    -- Open the first matching file
    vim.cmd("edit " .. files[1])
    print("Opened: " .. vim.fn.fnamemodify(files[1], ":t"))
  else
    print("Warning: No file found matching pattern: " .. pattern)
  end
end, { silent = true, desc = "Generate LeetCode markdown file" })

-- vim.keymap.set("n", "<leader>on", function()
--   local current_file = vim.fn.expand("%:p")
--   vim.cmd("ObsidianOpen")
--   vim.notify("The " .. current_file .. " is opened in Obsidian", vim.log.levels.INFO)
--   vim.fn.system("hyprctl dispatch workspace 2")
-- end, { silent = true, desc = "open note in Obsidian app" })

vim.keymap.set("n", "<leader>on", function()
  local fzf = require("fzf-lua")
  local obsidian = require("obsidian")

  -- 获取 obsidian client
  local client = obsidian.get_client()
  if not client then
    vim.notify("Obsidian client not available", vim.log.levels.ERROR)
    return
  end

  -- 获取 vault 根目录和当前文件目录
  local vault_path = "/home/lizhe/OriNote/notes/Ori"
  local current_file_dir = vim.fn.expand("%:p:h")

  -- 收集 vault 下所有子目录（排除隐藏目录）
  local dirs = {}
  local function get_dirs(path, relative)
    for name, type in vim.fs.dir(path) do
      -- 排除以 . 开头的隐藏目录
      if type == "directory" and not name:match("^%.") then
        local full_path = path .. "/" .. name
        local rel_path = relative ~= "" and (relative .. "/" .. name) or name
        table.insert(dirs, rel_path)
        get_dirs(full_path, rel_path)
      end
    end
  end

  get_dirs(vault_path, "")

  -- 计算当前文件相对于 vault 的目录
  local current_rel_dir = "."
  if current_file_dir:find(vault_path, 1, true) then
    local rel = current_file_dir:sub(#vault_path + 1)
    if rel ~= "" then
      current_rel_dir = rel:gsub("^/", "")
    end
  end

  -- 使用 fzf-lua 选择目录
  fzf.fzf_exec(dirs, {
    prompt = "Select Note Directory❯ ",
    fzf_opts = {
      ["--header"] = string.format([[Current: %s (ESC to use current)]], current_rel_dir),
    },
    actions = {
      ["default"] = function(selected)
        local target_dir

        if selected and #selected > 0 then
          -- 用户选择了目录
          target_dir = vault_path .. "/" .. selected[1]
        else
          -- 用户取消选择，使用当前文件目录
          target_dir = current_file_dir
        end

        -- 选择目录后，输入笔记标题
        vim.ui.input({ prompt = "Note title: " }, function(title)
          if not title or title == "" then
            return
          end

          -- 使用 Obsidian Lua API 创建笔记
          local ok, note = pcall(function()
            return client:create_note({ title = title, id = title, dir = target_dir })
          end)

          if ok and note then
            vim.cmd("edit " .. tostring(note.path))
          else
            vim.notify("Failed to create note: " .. tostring(note), vim.log.levels.ERROR)
          end
        end)
      end,
    },
  })
end, { silent = true, desc = "Create new Obsidian note with directory selection" })

-- 映射 <leader>gg 到搜索功能
keymap("n", "<leader>rg", "<cmd>lua Search_google_with_clipboard()<CR>", {
  silent = true,
  desc = "Google search clipboard",
})

keymap("v", "<leader>rg", "<cmd>lua Search_google_with_clipboard()<CR>", {
  silent = true,
  desc = "Google search clipboard",
})

-- Miscellaneous settings
-- Float terminal
vim.keymap.set("n", "<A-S-x>", function()
  Util.terminal(nil, { border = "rounded", size = { width = 0.5, height = 0.5 } })
end, { desc = "Term with border" })
-- Bookmark browser
keymap("n", "<leader>fB", "<cmd>BrowserBookmarks<CR>", { silent = true, desc = "open file keymap" })

vim.api.nvim_set_keymap("i", "<C-S-v>", "<Cmd>lua InsertMarkdownURL()<CR>", { noremap = true, silent = true })
-- 检查剪贴板支持性

vim.api.nvim_set_keymap("v", "<C-c>", '"+y', { noremap = true, silent = true })
vim.api.nvim_set_keymap("x", "<C-c>", '"+y', { noremap = true, silent = true })

-- related site: https://www.reddit.com/r/neovim/comments/14lvzw4/in_vim_b_and_b_means_and_any_other_letter_have/
vim.keymap.set("o", "ar", "a]") -- [r]ectangular bracket
vim.keymap.set("o", "ac", "a}") -- [c]urly brace
vim.keymap.set("o", "am", "aW") -- [m]assive word (= no shift needed)
vim.keymap.set("o", "aq", 'a"') -- [q]uote
vim.keymap.set("o", "az", "a'") -- [z]ingle quote
vim.keymap.set("o", "ir", "i]")
vim.keymap.set("o", "ic", "i}")
vim.keymap.set("o", "im", "iW")
vim.keymap.set("o", "iz", "i'")

-- plugin keymap
-- vim.keymap.set({ "n", "x", "o" }, "<leader>e", "<Cmd>Neotree position=float<CR>", { noremap = true })

vim.cmd([=[
hi FloatermBorder guibg=orange guifg=cyan
autocmd! InsertEnter * call feedkeys("\<Cmd>noh\<cr>" , 'n')
nnoremap da ggdG
nnoremap gf gF
nnoremap <S-A-K> viwy:he <C-r>"
nnoremap 'r 'R
nnoremap 'k 'K
setlocal nospell
set iskeyword-=-
set relativenumber
nnoremap < <<
nnoremap > >>
nnoremap }  }b
nnoremap {  {w
nnoremap gb {w
vnoremap gb {w
nnoremap gw {w
vnoremap gw {w
nnoremap ge }be
vnoremap ge }be
vnoremap gh g0
vnoremap gl $
nnoremap gh ^
nnoremap gl $
nnoremap <A-a> <C-o>
nnoremap <A-d> <C-i>
nnoremap <ESC> <cmd>lua vim.cmd('write')<CR>
nnoremap p p`]
vnoremap y y`]
nnoremap Y y$
nnoremap gn :bn<CR>
cnoremap %s %s/\v
imap jj <esc>
imap jk <esc>
imap Jk <esc>
imap JK <esc>
" imap K <esc>
onoremap p ip`]
map , <Plug>(wildfire-fuel)
" This selects the previous closest text object.
vmap <C-,> <Plug>(wildfire-water)
nnoremap j gj
nnoremap k gk
]=])

-- 添加可视模式下使用`键包围选中文本的映射
vim.keymap.set("v", "`", function()
  local saved_reg = vim.fn.getreg('"')
  vim.cmd("normal! y")
  local selected_text = vim.fn.getreg('"')
  vim.fn.setreg('"', "`" .. selected_text .. "`")
  vim.cmd("normal! gvp")
  vim.fn.setreg('"', saved_reg)
end, { desc = "Surround selection with backticks" })

-- 自定义词移动映射 - 让 cw 在标点符号前停止
-- 方案二：使用 ce 替代 cw (更精确的词尾移动)
vim.keymap.set("n", "cw", "ce", { desc = "Change word (stop at punctuation)" })
vim.keymap.set("n", "dw", "de", { desc = "Delete word (stop at punctuation)" })

-- 方案三：自定义函数来处理特定的标点符号
local function smart_word_motion(motion_type)
  local line = vim.api.nvim_get_current_line()
  local col = vim.api.nvim_win_get_cursor(0)[2]

  -- 查找下一个标点符号的位置
  local punctuation_pos = nil
  local punctuation_chars = {
    ";",
    ":",
    ",",
    ".",
    "!",
    "?",
    "+",
    "-",
    "*",
    "/",
    "=",
    "<",
    ">",
    "[",
    "]",
    "(",
    ")",
    "{",
    "}",
    "@",
    "#",
    "$",
    "%",
    "^",
    "&",
    "|",
    "~",
  }

  for i = col + 1, #line do
    local char = line:sub(i, i)
    for _, punct in ipairs(punctuation_chars) do
      if char == punct then
        punctuation_pos = i - 1 -- 转换为 0-based 索引
        break
      end
    end
    if punctuation_pos then
      break
    end
  end

  if punctuation_pos and punctuation_pos > col then
    -- 如果找到标点符号，移动到该位置
    vim.api.nvim_win_set_cursor(0, { vim.api.nvim_win_get_cursor(0)[1], punctuation_pos })
    if motion_type == "change" then
      vim.cmd("normal! v" .. col .. "|c")
    elseif motion_type == "delete" then
      vim.cmd("normal! v" .. col .. "|d")
    end
  else
    -- 否则使用默认的词移动
    if motion_type == "change" then
      vim.cmd("normal! ce")
    elseif motion_type == "delete" then
      vim.cmd("normal! de")
    end
  end
end

-- 备选方案：使用 <leader>cw 和 <leader>dw 来使用智能词移动
vim.keymap.set("n", "<leader>cw", function()
  smart_word_motion("change")
end, { desc = "Smart change word (stop at punctuation)" })
vim.keymap.set("n", "<leader>dw", function()
  smart_word_motion("delete")
end, { desc = "Smart delete word (stop at punctuation)" })

-- 另一种简单的方案：直接使用 ct; 类型的命令
vim.keymap.set("n", "<leader>c;", "ct;", { desc = "Change until semicolon" })
vim.keymap.set("n", "<leader>d;", "dt;", { desc = "Delete until semicolon" })
vim.keymap.set("n", "<leader>c,", "ct,", { desc = "Change until comma" })
vim.keymap.set("n", "<leader>d,", "dt,", { desc = "Delete until comma" })

-- QuQu: Toggle ASR start/stop via <A-e>
local ququ_script = "/home/lizhe/.config/nvim/scripts/test_http_curl.sh"

local function ququ_is_recording()
  local status_cmd = { "bash", "-lc", "curl -s --max-time 2 http://127.0.0.1:38765/api/status" }
  local ok, out = pcall(vim.fn.system, status_cmd)
  if not ok then
    return nil
  end
  if type(out) ~= "string" or out == "" then
    return nil
  end
  local ok_json, decoded = pcall(vim.json.decode, out)
  if not ok_json then
    return nil
  end
  if decoded and decoded.data and type(decoded.data.isRecording) == "boolean" then
    return decoded.data.isRecording
  end
  if decoded and type(decoded.isRecording) == "boolean" then
    return decoded.isRecording
  end
  return nil
end

-- 持续状态通知：录音进行中
_G.QuquRecordingTimer = _G.QuquRecordingTimer or nil
_G.QuquRecordingNotif = _G.QuquRecordingNotif or nil

local function ququ_dismiss_notify()
  local ok, notify = pcall(require, "notify")
  if ok and notify.dismiss then
    notify.dismiss({ pending = true, silent = true })
  end
  _G.QuquRecordingNotif = nil
end

local function ququ_show_persistent_notify()
  local ok, notify = pcall(require, "notify")
  if ok then
    if not _G.QuquRecordingNotif then
      _G.QuquRecordingNotif = notify("录音正在进行...", "info", { title = "QuQu", timeout = false })
    end
  else
    -- 退化处理：简短提示一次，避免刷屏
    vim.notify("录音正在进行...", vim.log.levels.INFO)
  end
end

local function ququ_start_status_watch()
  if _G.QuquRecordingTimer then
    return
  end
  ququ_show_persistent_notify()
  local timer = vim.loop.new_timer()
  _G.QuquRecordingTimer = timer
  -- 每5秒轮询一次状态
  timer:start(
    0,
    5000,
    vim.schedule_wrap(function()
      local rec = ququ_is_recording()
      if rec == true then
        -- 录音中：不重复显示通知
      elseif rec == false then
        -- 已停止：清理定时器与通知
        if _G.QuquRecordingTimer then
          _G.QuquRecordingTimer:stop()
          _G.QuquRecordingTimer:close()
          _G.QuquRecordingTimer = nil
        end
        ququ_dismiss_notify()
        -- 即时通知在触发停止时已显示，此处不再重复提示
      else
        -- 无法获取状态时，不做操作，等待下次轮询
      end
    end)
  )
end

local function ququ_stop_status_watch()
  if _G.QuquRecordingTimer then
    _G.QuquRecordingTimer:stop()
    _G.QuquRecordingTimer:close()
    _G.QuquRecordingTimer = nil
  end
  ququ_dismiss_notify()
end

-- 在光标处插入文本（支持多行）
local function ququ_insert_text_at_cursor(text)
  if not text or text == "" then
    return
  end
  local row_col = vim.api.nvim_win_get_cursor(0)
  local row = row_col[1] - 1
  local col = row_col[2]

  -- 获取缓冲区行数和当前行的长度
  local buf_line_count = vim.api.nvim_buf_line_count(0)
  local line_length = 0

  -- 检查行是否有效，如果无效则设置为缓冲区末尾
  if row >= buf_line_count then
    row = buf_line_count - 1
  end

  -- 获取当前行的长度
  if row >= 0 then
    local line_content = vim.api.nvim_buf_get_lines(0, row, row + 1, false)[1]
    if line_content then
      line_length = #line_content
    end
  end

  -- 确保列位置不超出当前行长度
  if col > line_length then
    col = line_length
  end

  local lines = {}
  for s in tostring(text):gmatch("([^\n]*)\n?") do
    table.insert(lines, s)
  end
  if #lines > 0 and lines[#lines] == "" then
    table.remove(lines, #lines)
  end
  if #lines == 0 then
    return
  end
  vim.api.nvim_buf_set_text(0, row, col, row, col, lines)
end

-- 停止录音并把系统剪贴板内容插入到光标处
local function ququ_stop_and_insert()
  local cmd = {
    "bash",
    "-lc",
    "curl -s -X POST http://127.0.0.1:38765/api/recording/stop -H 'Content-Type: application/json' -d '{}'",
  }
  vim.fn.jobstart(cmd, {
    stdout_buffered = true,
    on_exit = function()
      ququ_stop_status_watch()
      -- 略等应用将识别文本放入系统剪贴板
      vim.defer_fn(function()
        local clip = vim.fn.getreg("+")
        if clip and clip ~= "" then
          ququ_insert_text_at_cursor(clip)
          vim.notify("已从系统剪贴板插入识别文本", vim.log.levels.INFO)
        else
          vim.notify("系统剪贴板为空，未插入文本", vim.log.levels.WARN)
        end
      end, 200)
    end,
  })
end

function QuquToggleRecording()
  -- Check script exists
  if vim.fn.filereadable(ququ_script) == 0 then
    vim.notify("QuQu脚本未找到: " .. ququ_script, vim.log.levels.ERROR)
    return
  end

  local is_rec = ququ_is_recording()
  local action = (is_rec == true) and "stop" or "start"

  if action == "stop" then
    -- 立即提示已停止
    vim.notify("录音已经停止", vim.log.levels.INFO)
    ququ_stop_and_insert()
    return
  end

  local args = { ququ_script, action }
  vim.fn.jobstart(args, {
    stdout_buffered = true,
    on_exit = function(_, code)
      if code == 1 or code == 0 then
        if action == "start" then
          vim.notify("QuQu 已启动录音", vim.log.levels.INFO)
          ququ_start_status_watch()
        end
      else
        vim.notify("QuQu " .. action .. " 失败 (退出码 " .. tostring(code) .. ")", vim.log.levels.ERROR)
      end
    end,
  })
end

-- 智能创建 tmux 面板功能（优化版 - 减少延迟）
function SmartTmuxSplit()
  -- 获取当前 buffer 的目录
  local current_dir = vim.fn.expand("%:p:h")
  local working_dir = vim.fn.getcwd()

  -- 如果当前 buffer 没有文件（比如新文件），使用工作目录
  if current_dir == "" or current_dir == "." then
    current_dir = working_dir
  end

  -- 检查是否在 tmux 环境中
  local tmux_env = vim.env.TMUX
  if not tmux_env then
    return
  end

  -- 执行水平分割（左右分），即 tmux 的 -h 选项
  local split_cmd = 'tmux split-window -h -c "' .. current_dir .. '"'
  vim.fn.system(split_cmd)
end

local function copy_text_to_clipboard(content)
  local ok = pcall(vim.fn.setreg, "+", content)
  if ok and vim.fn.getreg("+") == content then
    return true
  end

  local external_tools = {
    { "wl-copy" },
    { "xclip", "-selection", "clipboard" },
    { "xsel", "--clipboard", "--input" },
  }

  for _, cmd in ipairs(external_tools) do
    if vim.fn.executable(cmd[1]) == 1 then
      vim.fn.system(cmd, content)
      if vim.v.shell_error == 0 then
        return true
      end
    end
  end

  return false
end

local function copy_current_file_path_to_clipboard()
  local file_path = vim.fn.expand("%:p")
  if file_path == "" then
    vim.notify("当前缓冲区没有文件路径，跳过复制", vim.log.levels.WARN)
    return false
  end

  if copy_text_to_clipboard(file_path) then
    return true
  end

  vim.notify("未找到可用的剪贴板工具：+ 寄存器 / wl-copy / xclip / xsel", vim.log.levels.ERROR)
  return false
end

-- 创建右侧面板函数，宽度为窗口的1/4
function CreateTmuxRightPanel()
  -- 获取当前 buffer 的目录
  local current_dir = vim.fn.expand("%:p:h")
  local working_dir = vim.fn.getcwd()

  -- 如果当前 buffer 没有文件（比如新文件），使用工作目录
  if current_dir == "" or current_dir == "." then
    current_dir = working_dir
  end

  copy_current_file_path_to_clipboard()

  -- 检查是否在 tmux 环境中
  local tmux_env = vim.env.TMUX
  if not tmux_env then
    vim.notify("不在 tmux 环境中", vim.log.levels.WARN)
    return
  end

  -- 使用百分比来创建右侧面板，30% 宽度，并自动运行 Codex
  local split_cmd = 'tmux split-window -h -p 30 -c "' .. current_dir .. '" codex'
  vim.fn.system(split_cmd)

  -- vim.notify("已创建右侧面板 (30% 宽度) 并运行 Codex", vim.log.levels.INFO)
end

-- 添加快捷键映射 <leader>tp 来创建右侧面板
vim.keymap.set("n", "<leader>tp", CreateTmuxRightPanel, {
  noremap = true,
  silent = true,
  desc = "Copy file path, open tmux right panel, and run Codex",
})

-- 添加 M-n 键绑定来调用智能面板创建功能
vim.keymap.set("n", "<A-n>", SmartTmuxSplit, {
  noremap = true,
  silent = true,
  desc = "Smart tmux split in current buffer directory",
})

-- Toggle opencode terminal (disabled)
-- vim.keymap.set("n", "<leader>oo", function()
--   vim.fn.system("~/.config/hypr/scripts/toggle_opencode_term.sh &")
-- end, { noremap = true, silent = true, desc = "Toggle opencode terminal" })

vim.keymap.set("n", "<leader>ob", function()
  vim.cmd("ObsidianBacklinks")
end, { noremap = true, silent = true, desc = "Open current note in Obsidian" })

-- Open current note in Obsidian
vim.keymap.set("n", "<leader>oo", function()
  vim.cmd("ObsidianOpen")
end, { noremap = true, silent = true, desc = "Open current note in Obsidian" })

-- Firefox recent URL 选择复制
local firefox_recent = require("config.firefox_recent")
firefox_recent.setup()

vim.keymap.set("n", "<leader>cu", function()
  firefox_recent.pick_and_copy_recent_url()
end, { noremap = true, silent = true, desc = "Pick Firefox recent URL and copy markdown link" })

-- 智谱 AI 翻译功能
vim.keymap.set("v", "<leader>tt", function()
  require("utils.zhipu_translation").translate_visual()
end, { noremap = true, silent = true, desc = "Translate selected text with Zhipu AI" })

vim.keymap.set("n", "<leader>tt", function()
  require("utils.zhipu_translation").translate_word()
end, { noremap = true, silent = true, desc = "Translate word under cursor with Zhipu AI" })

-- ev 函数：快速编辑配置文件
vim.keymap.set("n", "<leader>ev", function()
  require("utils.ev").open_ev_picker()
end, { noremap = true, silent = true, desc = "Edit config file (ev)" })

-- Claude/Codex 项目目录文件选择器 - 插入路径到光标位置
vim.keymap.set({ "n", "i" }, "@", function()
  local utils = require("config.utils")
  local agent_name, cwd = utils.get_ai_cli_context()
  local was_insert_mode = vim.fn.mode() == "i"

  if not agent_name then
    -- 不在 AI CLI 环境中，输入正常的 @ 字符
    if was_insert_mode then
      return "@"
    end
    return
  end

  if not cwd or cwd == "" then
    vim.notify("无法获取 " .. agent_name .. " 项目目录", vim.log.levels.ERROR)
    if was_insert_mode then
      return "@"
    end
    return
  end

  -- 保存当前光标位置
  local cursor_pos = vim.api.nvim_win_get_cursor(0)
  local ai_picker_filter = require("config.ai_picker_filter")
  local picker_opts = ai_picker_filter.get_files_picker_opts(cwd)

  -- 使用 snacks picker 选择文件
  picker_opts.actions = {
    confirm = function(picker, item)
      if not item then
        return
      end
      picker:close()
      -- item.file 已经是相对于 cwd 的相对路径
      local relative_path = item.file
      -- 插入 @ + 相对路径 + 两个空格，便于继续输入
      local text = "@" .. relative_path .. "  "
      vim.api.nvim_buf_set_text(0, cursor_pos[1] - 1, cursor_pos[2], cursor_pos[1] - 1, cursor_pos[2], { text })
      -- 将光标移动到插入文本末尾（空格后）
      vim.api.nvim_win_set_cursor(0, { cursor_pos[1], cursor_pos[2] + #text })
      if was_insert_mode then
        vim.cmd("startinsert")
      end
    end,
  }

  Snacks.picker.files(picker_opts)
end, { noremap = true, silent = true, expr = true, desc = "Claude/Codex 项目文件选择并插入路径" })
