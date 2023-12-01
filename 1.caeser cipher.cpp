#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plain[10], cipher[10];
    int key, i, length;

    printf("\n Enter the plain text:");
    scanf("%s", plain);

    printf("\n Enter the key value:");
    scanf("%d", &key);

    printf("\n \n \t PLAIN TEXT: %s", plain);

    length = strlen(plain);

    printf("\n \n \t ENCRYPTED TEXT: ");
    for (i = 0; i < length; i++) {
        cipher[i] = plain[i] + key;
        if (isupper(plain[i]) && (cipher[i] > 'Z'))
            cipher[i] -= 26;
        if (islower(plain[i]) && (cipher[i] > 'z'))
            cipher[i] -= 26;
        printf("%c", cipher[i]);
    }

    printf("\n \n \t AFTER DECRYPTION : ");
    for (i = 0; i < length; i++) {
        plain[i] = cipher[i] - key;
        if (isupper(cipher[i]) && (plain[i] < 'A'))
            plain[i] += 26;  
        if (islower(cipher[i]) && (plain[i] < 'a'))
            plain[i] += 26;
        printf("%c", plain[i]);
    }

    printf("\n");
    return 0;
}
