#include <stdio.h>
#include <string.h>

int main(void) {
    int i, j, k, l;
    char a[100], c[100], d[100];

    printf("\n\t\t RAIL FENCE TECHNIQUE\n\nEnter the input string: ");
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n")] = '\0'; 

    l = strlen(a);

    
    for (i = 0, j = 0; i < l; i += 2) {
        c[j++] = a[i];
    }
    for (i = 1; i < l; i += 2) {
        c[j++] = a[i];
    }
    c[j] = '\0';

    printf("\nCipher text after applying rail fence: %s\n", c);

    
    if (l % 2 == 0) k = l / 2;
    else k = (l / 2) + 1;

    for (i = 0, j = 0; i < k; i++) {
        d[j] = c[i];
        j += 2;
    }
    for (i = k, j = 1; i < l; i++) {
        d[j] = c[i];
        j += 2;
    }
    d[l] = '\0';

    printf("Text after decryption: %s\n", d);

    return 0;
}
