rm -rf *.o
rm -rf ./*/*.o
rm -rf main

gcc -c ./lib/rubro-negra.c
gcc -c main.c

gcc -o main ./*.o