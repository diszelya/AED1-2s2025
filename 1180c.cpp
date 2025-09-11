//RA: 177065 UNIFESP AED 2s2025

#include <iostream>
#include <cstdlib>

typedef struct{
    int position;
    int value;
} smallestnumber;

using std::string;

int main(){
    int *n = (int*)malloc(sizeof(int));
    int *i = (int*)malloc(sizeof(int));
    
    std::cin >> *n;
    
    int *array = (int*)malloc(*n * sizeof(int));
    
    for (*i = 0; *i < *n; (*i)++){
        std::cin >> array[*i];
    }
    
    smallestnumber *s = (smallestnumber*)malloc(sizeof(smallestnumber));
    s->position = 0;
    s->value = array[0];
    
    for (*i = 0; *i < *n; (*i)++){
        if (s->value >= array[*i]){
            s->value = array[*i];
            s->position = *i;
        }
    }
    
    std::cout << "Menor valor: " << s->value << std::endl;
    std::cout << "posicao: " << s->position << std::endl;
    
    free(s);
    free(array);
    free(i);
    free(n);
    
    return 0;
}
