" GENERAL SETTINGS
set number
set colorcolumn=81
set noexpandtab
set tabstop=4
set shiftwidth=4
set wildmenu
set background=dark
set autoindent
set smartindent
set nowrap
set scrolloff=2
set sidescroll=1
set sidescrolloff=4
syntax on

" PACKAGE SETTINGS
let g:airline_theme="term"
let g:ycm_show_diagnostics_ui = 0
let g:ale_linters = {"c": ["gcc"], "cpp": ["g++"], "tex": ["chktex"]}
let g:c_syntax_for_h = 1
let g:livepreview_previewer = 'zathura'
let g:livepreview_engine = 'xelatex'
let g:tex_flavor = "latex"

" GENERAL MAPPINGS
nnoremap <Leader>p :w<CR>:!make<CR>
nnoremap <Leader>o :!make run<CR>

nnoremap <Leader>h :vertical resize<Space>
nnoremap <Leader>v :resize<Space>

nnoremap <Leader>u :UndotreeToggle<CR>

inoremap {<CR> {<CR>}<Esc>ko

nnoremap <Leader>c :!xclip -sel c %<CR>
inoremap <C-v> <Esc>!!xclip -o<CR>i

nnoremap <C-p> "0p
vnoremap <C-p> "0p

" PYTHON MAPPINGS
autocmd FileType python nnoremap <Leader>p :w<CR>:!python %<CR>
autocmd FileType python nnoremap <Leader>o :w<CR>:!python -i %<CR>
autocmd FileType python setlocal expandtab

" TEX MAPPINGS
autocmd FileType tex packadd latexlivepreview
autocmd FileType tex packadd closeb
autocmd FileType tex nnoremap <Leader>p :LLPStartPreview<CR>
autocmd FileType tex nnoremap <Leader>o :w<CR>:!xelatex %<CR>
autocmd FileType tex nnoremap <Leader>O :w<CR>:!xelatex %<CR>
autocmd FileType tex imap <C-e> <C-_>
autocmd FileType tex setlocal textwidth=80
autocmd FileType tex setlocal spell

autocmd FileType tex inoremap @EN \begin{enumerate}<CR>\end{enumerate}<Esc>ko<Tab>\item<CR><Tab>
autocmd FileType tex inoremap @EL \begin{enumerate}[(a)]<CR>\end{enumerate}<Esc>ko<Tab>\item<CR><Tab>
autocmd FileType tex inoremap @I \begin{itemize}<CR>\end{itemize}<Esc>ko<Tab>\item<CR><Tab>
autocmd FileType tex inoremap @EQ \begin{equation*}<CR>\end{equation*}<Esc>ko<Tab>
autocmd FileType tex inoremap @NEQ \begin{equation}<CR>\end{equation}<Esc>ko<Tab>
autocmd FileType tex inoremap @A \begin{align*}<CR>\end{align*}<Esc>ko<Tab>
autocmd FileType tex inoremap @S \section*{}<Esc>i
autocmd FileType tex inoremap @NS \section{}<Esc>i

" TEXT AND MAIL MAPPINGS
autocmd FileType text setlocal textwidth=80
autocmd FileType text setlocal spell
autocmd FileType mail setlocal textwidth=80
autocmd FileType mail setlocal spell
