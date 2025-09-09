//RA: 177065 UNIFESP AED 2s2025

#include <iostream>

typedef struct{
    int position;
    int value;
} smallestnumber;

using std::string;

int main(){
    int n, i;
    
    std::cin >> n;
    
    int array[n];
    
    for (i = 0; i < n; i++){
        std::cin >> array[i];
    }
    
    smallestnumber s;
    s.position = 0;
    s.value = array[0];
    
    for (i = 0; i < n; i++){
        if (s.value >= array[i]){
            s.value = array[i];
            s.position = i;
        }
    }
    
    std::cout << "Menor valor: " << s.value << std::endl;
    std::cout << "posicao: " << s.position << std::endl;
    return 0;
}
