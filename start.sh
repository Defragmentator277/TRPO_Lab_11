rm -f app
gcc -O3 -Wall Lab_11_C.c -o app -llua5.3 -lm -I/usr/include/lua5.3
./app
