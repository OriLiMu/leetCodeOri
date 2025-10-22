return {
  "OriLiMu/bullets.vim",
  "ojroques/nvim-bufdel",
  "uga-rosa/ccc.nvim",
  -- Lua
  {
    "folke/twilight.nvim",
    opts = {
      -- your configuration comes here
      -- or leave it empty to use the default settings
      -- refer to the configuration section below
    },
  },
  "djoshea/vim-autoread",
  "voldikss/vim-translator",
  -- "rlue/vim-barbaric",
  "MattesGroeger/vim-bookmarks",
  "OriLiMu/vim-markdown",
  {
    "Thiago4532/mdmath.nvim",
    dependencies = {
      "nvim-treesitter/nvim-treesitter",
    },
    -- The build is already done by default in lazy.nvim, so you don't need
    -- the next line, but you can use the command `:MdMath build` to rebuild
    -- if the build fails for some reason.
    -- build = ':MdMath build'
  },
  {
    enabled = true,
    "MeanderingProgrammer/render-markdown.nvim",
    -- "OriLiMu/render-markdown.nvim",
    dependencies = { "nvim-treesitter/nvim-treesitter", "nvim-mini/mini.nvim" }, -- if you use the mini.nvim suite
    -- dependencies = { 'nvim-treesitter/nvim-treesitter', 'nvim-mini/mini.icons' }, -- if you use standalone mini plugins
    -- dependencies = { 'nvim-treesitter/nvim-treesitter', 'nvim-tree/nvim-web-devicons' }, -- if you prefer nvim-web-devicons
    ---@module 'render-markdown'
    ---@type render.md.UserConfig
    opts = {
      dash = { enabled = false },
      -- code = { enabled = false },
      bullet = {
        enabled = true,
        render_modes = false,
        icons = { "•", "◦" },
        ordered_icons = function(ctx)
          local value = vim.trim(ctx.value)
          local index = tonumber(value:sub(1, #value - 1))
          return ("%d."):format(index > 1 and index or ctx.index)
        end,
        left_pad = 0,
        right_pad = 0,
        highlight = "RenderMarkdownBullet",
        scope_highlight = {},
        scope_priority = nil,
      },
      link = {
        enabled = true,
        render_modes = false,
        footnote = {
          enabled = true,
          icon = "󰯔 ",
          superscript = true,
          prefix = "",
          suffix = "",
        },
        image = "󰥶 ",
        email = "󰀓 ",
        hyperlink = "󰌹 ",
        highlight = "RenderMarkdownLink",
        wiki = {
          -- icon = "󱗖 ",
          -- icon = "",
          icon = "",
          body = function()
            return nil
          end,
          highlight = "RenderMarkdownWikiLink",
          scope_highlight = nil,
        },
        custom = {
          web = { pattern = "^http", icon = "󰖟 " },
          discord = { pattern = "discord%.com", icon = "󰙯 " },
          github = { pattern = "github%.com", icon = "󰊤 " },
          gitlab = { pattern = "gitlab%.com", icon = "󰮠 " },
          google = { pattern = "google%.com", icon = "󰊭 " },
          neovim = { pattern = "neovim%.io", icon = " " },
          reddit = { pattern = "reddit%.com", icon = "󰑍 " },
          stackoverflow = { pattern = "stackoverflow%.com", icon = "󰓌 " },
          wikipedia = { pattern = "wikipedia%.org", icon = "󰖬 " },
          youtube = { pattern = "youtube%.com", icon = "󰗃 " },
        },
      },
    },
    config = function(_, opts)
      require("render-markdown").setup(opts)

      -- 设置 RenderMarkdownLink、RenderMarkdownWikiLink 和链接文本高亮组颜色为 #c792ea
      -- vim.api.nvim_create_autocmd("ColorScheme", {
      --   pattern = "*",
      --   callback = function()
      --     vim.cmd([[highlight RenderMarkdownLink guifg=#c792ea]])
      --     vim.cmd([[highlight RenderMarkdownWikiLink guifg=#c792ea]])
      --     vim.cmd([[highlight @markup.link.label.markdown_inline guifg=#c792ea gui=underline]])
      --   end,
      -- })

      -- 立即应用颜色设置
      vim.cmd([[highlight RenderMarkdownLink guifg=#c792ea]])
      vim.cmd([[highlight RenderMarkdownWikiLink guifg=#c792ea]])
      vim.cmd([[highlight @markup.link.label.markdown_inline guifg=#c792ea gui=underline]])
    end,
  },
  "skywind3000/asyncrun.vim",
  {
    "sphamba/smear-cursor.nvim",
    opts = {},
  },
  -- "gcmt/wildfire.vim",
  {
    "numToStr/Comment.nvim",
    lazy = false,
  },
  {
    "szw/vim-maximizer",
    keys = {
      { "<leader>wm", "<cmd>MaximizerToggle<CR>" },
    },
  },
  {
    "fladson/vim-kitty",
  },

  -- project management
  {
    "ahmedkhalf/project.nvim",
    config = function()
      require("project_nvim").setup({
        -- your configuration comes here
        -- or leave it empty to use the default settings
        -- refer to the configuration section below
      })
    end,
  },
  {
    "folke/todo-comments.nvim",
    dependencies = { "nvim-lua/plenary.nvim" },
    opts = {},
  },
  {
    "dhruvmanila/browser-bookmarks.nvim",
    version = "*",
    -- Only required to override the default options
    opts = {
      -- Override default configuration values
      selected_browser = "chrome",
      url_open_command = "google-chrome-stable",
    },
  },
  {
    "nvim-telescope/telescope.nvim",
    tag = "0.1.5",
    dependencies = { "nvim-lua/plenary.nvim" },
    config = function()
      require("telescope").setup({
        defaults = {
          -- 配置默认设置
        },
      })
    end,
  },
  -- markdown related
  -- {
  --   "lukas-reineke/headlines.nvim",
  --   dependencies = "nvim-treesitter/nvim-treesitter",
  --   config = true, -- or `opts = {}`
  -- },
  {
    "antonk52/markdowny.nvim",
    config = function()
      require("markdowny").setup()
    end,
  },
  {
    "OriLiMu/outline.nvim",
    lazy = true,
    cmd = { "Outline", "OutlineOpen" },
    keys = { -- Example mapping to toggle outline
      { "<leader>ol", "<cmd>Outline<CR>", desc = "Toggle outline" },
    },
    opts = {
      outline_window = {
        position = "left",
        focus_on_open = false,
        width = 13,
      },
    },
  },
  {
    "3rd/image.nvim",
    config = function()
      require("image").setup({
        -- 设置图片显示为实际大小
        backend = "kitty",
        integrations = {
          markdown = {
            enabled = true,
            clear_in_insert_mode = false,
            download_remote_images = true,
            only_render_image_at_cursor = false,
            filetypes = { "markdown", "vimwiki" },
          },
        },
        max_width = nil,
        max_height = nil,
        max_width_window_percentage = 20,
        max_height_window_percentage = 20,
        window_overlap_clear_enabled = true,
        window_overlap_clear_ft_ignore = { "cmp_menu", "cmp_docs", "" },
      })
      package.path = package.path .. ";" .. vim.fn.expand("$HOME") .. "/.luarocks/share/lua/5.1/?/init.lua"
      package.path = package.path .. ";" .. vim.fn.expand("$HOME") .. "/.luarocks/share/lua/5.1/?.lua"
    end,
  },
  -- {
  --   "michaelb/sniprun",
  --   branch = "master",
  --   build = "sh install.sh",
  --   -- do 'sh install.sh 1' if you want to force compile locally
  --   -- (instead of fetching a binary from the github release). Requires Rust >= 1.65
  --
  --   config = function()
  --     require("sniprun").setup({
  --       -- your options
  --       display = {
  --         "TempFloatingWindow", --# display results in the command-line  area
  --         "VirtualTextOk", --# display ok results as virtual text (multiline is shortened)
  --         -- "VirtualText",             --# display results as virtual text
  --         -- "TempFloatingWindow",      --# display results in a floating window
  --         -- "LongTempFloatingWindow",  --# same as above, but only long results. To use with VirtualText[Ok/Err]
  --         -- "Terminal",                --# display results in a vertical split
  --         -- "TerminalWithCode",        --# display results and code history in a vertical split
  --         -- "NvimNotify",              --# display with the nvim-notify plugin
  --         -- "Api"                      --# return output to a programming interface
  --       },
  --     })
  --   end,
  -- },
  {
    "christoomey/vim-tmux-navigator",
    lazy = false,
    cmd = {
      "TmuxNavigateLeft",
      "TmuxNavigateDown",
      "TmuxNavigateUp",
      "TmuxNavigateRight",
      "TmuxNavigatePrevious",
    },
    keys = {
      { "<c-h>", "<cmd>TmuxNavigateLeft<cr>" },
      { "<c-j>", "<cmd>TmuxNavigateDown<cr>" },
      { "<c-k>", "<cmd>TmuxNavigateUp<cr>" },
      { "<c-l>", "<cmd>TmuxNavigateRight<cr>" },
      { "<c-\\>", "<cmd>TmuxNavigatePrevious<cr>" },
    },
  },
  {
    "stevearc/oil.nvim",
    ---@module 'oil'
    ---@type oil.SetupOpts
    opts = {},
    -- Optional dependencies
    dependencies = { { "nvim-mini/mini.icons", opts = {} } },
    -- dependencies = { "nvim-tree/nvim-web-devicons" }, -- use if prefer nvim-web-devicons
  },
  {
    "folke/snacks.nvim",
    opts = { words = { enabled = false } },
  },
  {
    "akinsho/toggleterm.nvim",
    config = true,
    cmd = "ToggleTerm",
    keys = { { "<leader>ft", "<cmd>ToggleTerm<cr>", desc = "Toggle floating terminal" } },
    opts = {
      open_mapping = [[<F4>]],
      direction = "float",
      shade_filetypes = {},
      hide_numbers = true,
      insert_mappings = true,
      terminal_mappings = true,
      start_in_insert = true,
      close_on_exit = true,
    },
  },
  {
    "dhruvmanila/browser-bookmarks.nvim",
    version = "*",
    -- Only required to override the default options
    opts = {
      -- Override default configuration values
      -- selected_browser = 'chrome'
    },
    -- dependencies = {
    --   -- Only if your selected browser is Firefox, Waterfox or buku
    --   'kkharji/sqlite.lua',
    --
    --   -- Only if you're using the Telescope extension
    --   'nvim-telescope/telescope.nvim',
    -- }
  },
}
