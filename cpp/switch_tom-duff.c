#include <stdio.h>

void send(u_int8_t* to, u_int8_t* from, u_int16_t count) {
    u_int16_t n = (count + 7)/8;

    switch (count % 8) {
        case 0: do { *to = *from++;
        case 7:      *to = *from++;
        case 6:      *to = *from++;
        case 5:      *to = *from++;
        case 4:      *to = *from++;
        case 3:      *to = *from++;
        case 2:      *to = *from++;
        case 1:      *to = *from++;
                }while(--n > 0);
    }
}

int test(int count)
{
    int i = 0;
    int n = (count + 7)/8; // supose coutn > 0
    
    switch(count % 8) {
        case 0: do{ i++;
        case 7:     i++;
        case 6:     i++;
        case 5:     i++;
        case 4:     i++;
        case 3:     i++;
        case 2:     i++;
        case 1:     i++;
                }while( --n > 0);
    }
    return i;
}

int main(int argc, char* argv[])
{
    printf("%d\n", test(20));
    return 0;
}