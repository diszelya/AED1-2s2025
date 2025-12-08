//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>
#include <string.h>

char preStr[27], inStr[27];
int preIndex;

void postOrder(int start, int end) {
    if (start > end) return;

    char root = preStr[preIndex++];
    int pos;

    for (int i = start; i <= end; i++) {
        if (inStr[i] == root) {
            pos = i;
            break;
        }
    }

    postOrder(start, pos - 1);
    postOrder(pos + 1, end);
    printf("%c", root);
}

int main() {
    while (scanf("%s %s", preStr, inStr) != EOF) {
        preIndex = 0;
        int len = strlen(inStr);
        postOrder(0, len - 1);
        printf("\n");
    }
    return 0;
}
