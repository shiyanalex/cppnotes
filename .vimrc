"Use vim settings, rather then vi settings (much better!)
"This must be first, because it changes other options as a side effect.
set nocompatible

set t_Co=256
set termguicolors
set background=dark
colorscheme deus
let g:deus_termcolors=256
syntax on                   " syntax highlighting
set ruler              		" show the cursor position
filetype plugin indent on   " use the file type plugins 
"set smartindent

set showmode               	" always show what mode we're currently editing in
set number
set mouse=a

set tabstop=4               " a tab is four spaces
set shiftwidth=4        	" number of spaces to use for autoindenting
set smarttab
set expandtab

set showmatch                   " set show matching parenthesis
set scrolloff=4                 " keep 4 lines off the edges of the screen when scrolling
set hlsearch                    " highlight search terms
set incsearch                   " show search matches as you type

"autocmd InsertLeave * write	 " write on exiting Insert
set selection=exclusive
set virtualedit=onemore
set tw=120                      "set text width to 72

noremap gb gT
noremap gf :execute "tabmove" tabpagenr() - 2 <CR>
noremap gh :execute "tabmove" tabpagenr() + 1 <CR>
noremap tp :tabedit 
cnoremap help vert help

set clipboard=unnamed           " so you can actually copy things 
set whichwrap+=<,>,[,]          " arrow keys can move between lines
set nobackup                    " do not keep backup files, it's 70's style cluttering
set noswapfile                  " do not write annoying intermediate swap files

" status bar colors
" ctermbg - background color, and ctermfg - text color. #8fbfdc
highlight statusline ctermfg=black ctermbg=cyan
au InsertEnter * highlight statusline ctermfg=black ctermbg=DarkGreen
au InsertLeave * highlight statusline ctermfg=black ctermbg=Cyan

" Status Line Custom
let g:currentmode={
                \ 'n'  : 'NORMAL ',
                \ 'v'  : 'VISUAL ',
                \ 'V'  : 'V·Line ',
                \ "\<C-V>" : 'V·Block ',
                \ 'i'  : 'INSERT ',
                \ 'R'  : 'R ',
                \ 'Rv' : 'V·Replace ',
                \ 'c'  : 'Command ',
                \}

set laststatus=2
set noshowmode
set statusline=
set statusline+=%0*\ %n\                                 " Buffer number
set statusline+=%1*\ %<%F%m%r%h%w\                       " File path, modified, readonly, helpfile, preview
set statusline+=%3*│                                     " Separator
set statusline+=%2*\ %Y\                                 " FileType
set statusline+=%3*│                                     " Separator
set statusline+=%2*\ %{''.(&fenc!=''?&fenc:&enc).''}     " Encoding
set statusline+=\ (%{&ff})                               " FileFormat (dos/unix..)
set statusline+=%=                                       " Right Side
set statusline+=%2*\ col:\ %02v\                         " Colomn number
set statusline+=%3*│                                     " Separator
set statusline+=%1*\ ln:\ %02l/%L\ (%3p%%)\              " Line number / total lines, percentage of document
set statusline+=%0*\ %{toupper(g:currentmode[mode()])}\  " The current mode

" User 1 - left & right User2 - mid User3 - separators
hi User1 ctermfg=007 ctermbg=239 
hi User2 ctermfg=007 ctermbg=236
hi User3 ctermfg=236 ctermbg=236
