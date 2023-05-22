# /bin/bash
rm ./build/app
ulimit -S -c unlimited
gcc -o build/app src/main.c -w -lm -ggdb -I /usr/include/X11 -L /usr/X11/lib -lX11 -fcond-mismatch -g;
chmod +x build/app;
./build/app
