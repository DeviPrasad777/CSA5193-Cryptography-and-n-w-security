#include <stdio.h>
#include <string.h>

int main() {
    unsigned int a[3][3] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}}; // Encryption matrix
    unsigned int b[3][3] = {{8, 5, 10}, {21, 8, 21}, {21, 12, 8}};   // Decryption matrix
    int i, j, t = 0;
    unsigned int c[20], d[20];
    char msg[20];

    printf("Enter a plain text of length 3 (only uppercase letters): ");
    scanf("%3s", msg); // Accept only 3 characters (limitation due to the 3x3 matrix)

    if (strlen(msg) != 3) {
        printf("Error: Please enter exactly 3 uppercase letters.\n");
        return 1;
    }

    // Convert plain text to numerical values (A=0, B=1, ..., Z=25)
    for (i = 0; i < 3; i++) {
        if (msg[i] < 'A' || msg[i] > 'Z') {
            printf("Error: Only uppercase letters are allowed.\n");
            return 1;
        }
        c[i] = msg[i] - 'A';
    }

    // Encryption
    for (i = 0; i < 3; i++) {
        t = 0;
        for (j = 0; j < 3; j++) {
            t += a[i][j] * c[j];
        }
        d[i] = t % 26; // Modular arithmetic for alphabet range
    }

    printf("\nEncrypted Cipher Text: ");
    for (i = 0; i < 3; i++) {
        printf("%c", d[i] + 'A'); // Convert back to characters
    }

    // Decryption
    for (i = 0; i < 3; i++) {
        t = 0;
        for (j = 0; j < 3; j++) {
            t += b[i][j] * d[j];
        }
        c[i] = t % 26; // Modular arithmetic for alphabet range
    }

    printf("\nDecrypted Cipher Text: ");
    for (i = 0; i < 3; i++) {
        printf("%c", c[i] + 'A'); // Convert back to characters
    }

    printf("\n");
    return 0;
}
