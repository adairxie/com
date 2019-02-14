
#!/bin/bash

yum groupinstall 'Development tools' -y
yum install ncurses ncurses-devel wget git -y

cd /usr/local/src
wget ftp://ftp.vim.org/pub/vim/unix/vim-8.1.tar.bz2
tar -xjf vim-8.1.tar.bz2

cd vim81
./configure --prefix=/usr --with-features=huge --enable-rubyinterp --enable-pythoninterp
make && make install

vim --version
