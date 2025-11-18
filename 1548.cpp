//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>
#include <stdlib.h>

typedef struct tNode {
    int grade;
    struct tNode *next;
} tNode;

typedef tNode *pNode;

pNode pushTail(pNode arrivalOrder, int v) {
    pNode newNode = (pNode)malloc(sizeof(tNode));
    newNode->grade = v;
    newNode->next = NULL;

    if (arrivalOrder == NULL) {
        return newNode;
    }

    pNode aux = arrivalOrder;
    while (aux->next != NULL) {
        aux = aux->next;
    }
    aux->next = newNode;
    return arrivalOrder;
}

pNode insertSorted(pNode sortedOrder, int v) {
    pNode newNode = (pNode)malloc(sizeof(tNode));
    newNode->grade = v;
    newNode->next = NULL;

    if (sortedOrder == NULL || v > sortedOrder->grade) {
        newNode->next = sortedOrder;
        return newNode;
    }

    pNode aux = sortedOrder;
    while (aux->next != NULL && aux->next->grade > v) {
        aux = aux->next;
    }

    newNode->next = aux->next;
    aux->next = newNode;
    return sortedOrder;
}

void freeList(pNode list) {
    pNode aux;
    while (list != NULL) {
        aux = list->next;
        free(list);
        list = aux;
    }
}

int main() {
    int n, m, i, grade, count;
    
    scanf("%d", &n);

    while (n > 0) {
        scanf("%d", &m);

        pNode arrivalOrder = NULL;
        pNode sortedOrder = NULL;

        for (i = 0; i < m; i++) {
            scanf("%d", &grade);
            arrivalOrder = pushTail(arrivalOrder, grade);
            sortedOrder = insertSorted(sortedOrder, grade);
        }

        count = 0;
        pNode auxArrival = arrivalOrder;
        pNode auxSorted = sortedOrder;

        while (auxArrival != NULL) {
            if (auxArrival->grade == auxSorted->grade) {
                count++;
            }
            auxArrival = auxArrival->next;
            auxSorted = auxSorted->next;
        }

        printf("%d\n", count);

        freeList(arrivalOrder);
        freeList(sortedOrder);
        
        n--;
    }

    return 0;
}
