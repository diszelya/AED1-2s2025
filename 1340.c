//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>

int s[1005], stop;
int q[1005], qfront, qrear;
int pq[1005], pqlen;

int isstack, isqueue, ispq;

void start() {
    stop = 0;
    qfront = 0; qrear = 0;
    pqlen = 0;
    isstack = 1; isqueue = 1; ispq = 1;
}

void pushall(int v) {
    if (isstack) s[stop++] = v;
    if (isqueue) q[qrear++] = v;
    if (ispq) pq[pqlen++] = v;
}

void popall(int v) {
    if (isstack) {
        if (stop == 0 || s[--stop] != v) {
            isstack = 0;
        }
    }

    if (isqueue) {
        if (qfront == qrear || q[qfront++] != v) {
            isqueue = 0;
        }
    }

    if (ispq) {
        if (pqlen == 0) {
            ispq = 0;
        } else {
            int maxidx = 0;
            int maxval = pq[0];
            for (int i = 1; i < pqlen; i++) {
                if (pq[i] > maxval) {
                    maxval = pq[i];
                    maxidx = i;
                }
            }

            if (maxval != v) {
                ispq = 0;
            } else {
                pq[maxidx] = pq[--pqlen];
            }
        }
    }
}

int main() {
    int n, command, x;

    while (scanf("%d", &n) != EOF) {
        start();

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &command, &x);
            
            if (command == 1) {
                pushall(x);
            } else {
                popall(x); 
            }
        }

        if (isstack + isqueue + ispq == 0)
            printf("impossible\n");
        else if (isstack + isqueue + ispq > 1)
            printf("not sure\n");
        else if (isstack)
            printf("stack\n");
        else if (isqueue)
            printf("queue\n");
        else
            printf("priority queue\n");
    }

    return 0;
}
