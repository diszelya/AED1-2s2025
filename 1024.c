//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char text[1005];
    int length;
    int i;
    char temp;

    scanf("%d", &n);
    getchar();

    while (n > 0) {
        fgets(text, 1005, stdin);
        length = strlen(text);

        if (length > 0 && text[length - 1] == '\n') {
            text[length - 1] = '\0';
            length--;
        }

        for (i = 0; i < length; i++) {
            if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
                text[i] = text[i] + 3;
            }
        }

        for (i = 0; i < length / 2; i++) {
            temp = text[i];
            text[i] = text[length - 1 - i];
            text[length - 1 - i] = temp;
        }

        for (i = length / 2; i < length; i++) {
            text[i] = text[i] - 1;
        }

        printf("%s\n", text);
        n--;
    }

    return 0;
}
