//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>
#include <stdlib.h>

typedef struct tNode {
    struct tNode *next;
    int value;
} tNode;

typedef tNode *pNode;

pNode push(pNode queue, int v) {
    pNode new = (pNode)malloc(sizeof(tNode));
    new->value = v;
    new->next = NULL;

    pNode aux = queue;
    while (aux->next != NULL) {
        aux = aux->next;
    }
    aux->next = new;
    return (queue);
}

pNode pop(pNode queue) {
    if (queue->next == NULL) {
        return queue;
    }
    pNode aux = queue->next;
    queue->next = aux->next;
    free(aux);
    return (queue);
}

pNode shufle(pNode queue) {
    if (queue->next == NULL || queue->next->next == NULL) {
        return queue;
    }

    pNode aux = queue;
    pNode aux2 = queue->next;

    while (aux->next != NULL) {
        aux = aux->next;
    }

    queue->next = aux2->next;
    aux2->next = aux->next;
    aux->next = aux2;

    return (queue);
}

void free_deck(pNode queue) {
    pNode aux;
    while (queue != NULL) {
        aux = queue->next;
        free(queue);
        queue = aux;
    }
}

int main() {
    pNode deck;
    int i, j;

    scanf("%d", &i);

    while (i != 0) {
        deck = (pNode)malloc(sizeof(tNode));
        deck->next = NULL;

        if (i == 1) {
            printf("Discarded cards:\n");
            printf("Remaining card: 1\n");
            free_deck(deck);
            scanf("%d", &i);
            continue;
        }

        int discarded[i - 1];

        for (j = 1; j <= i; j++) {
            deck = push(deck, j);
        }

        for (j = 0; j < i - 1; j++) {
            discarded[j] = deck->next->value;
            deck = pop(deck);
            deck = shufle(deck);
        }

        printf("Discarded cards: %d", discarded[0]);
        for (j = 1; j < i - 1; j++) {
            printf(", %d", discarded[j]);
        }
        printf("\nRemaining card: %d\n", deck->next->value);

        free_deck(deck);
        scanf("%d", &i);
    }

    return 0;
}
