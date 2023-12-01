#include <stdio.h>
#include <string.h>
#include <math.h>

typedef union {
    unsigned w;
    unsigned char b[4];
} MD5union;

typedef unsigned DigestArray[4];
typedef unsigned (*DgstFctn)(unsigned a[]);

unsigned *calctable(unsigned *k) {
    double s;
    int i;
    for (i = 0; i < 64; i++) {
        s = fabs(sin(1 + i));
        k[i] = (unsigned)(s * pow(2, 32));
    }
    return k;
}

unsigned rol(unsigned r, short N) {
    unsigned mask1 = (1u << N) - 1;
    return ((r >> (32 - N)) & mask1) | ((r << N) & ~mask1);
}

unsigned *md5(const char *msg, int mlen) {
    // (unchanged code)
}

int main() {
    int j, k;
    const char *msg = "The quick brown fox jumps over the lazy dog";
    unsigned *d = md5(msg, strlen(msg));
    MD5union u;

    printf("\t MD5 ENCRYPTION ALGORITHM IN C \n\n");
    printf("Input String to be Encrypted using MD5 :\n\t%s", msg);
    printf("\n\nThe MD5 code for input string is: \n");
    printf("\t= 0x");
    for (j = 0; j < 4; j++) {
        u.w = d[j];
        for (k = 0; k < 4; k++)
            printf("%02x", u.b[k]);
    }
    printf("\n");
    printf("\n\t MD5 Encryption Successfully Completed!!!\n\n");
    return 0;
}
