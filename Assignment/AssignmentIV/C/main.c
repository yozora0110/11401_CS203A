#include <stdio.h>
#include "hash_fn.h"

void test_int_hash() {
    printf("=== Testing Integer Hash Functions ===\n");
    
    int keys[] = {10, 25, 37, 42, 58, 63, 79, 84, 91, 105};
    int m = 10; // 哈希表大小
    
    printf("Key\tDivision\tMultiplication\n");
    printf("---\t--------\t-------------\n");
    
    for (int i = 0; i < 10; i++) {
        int div_hash = hash_int_division(keys[i], m);
        int mult_hash = hash_int_multiplication(keys[i], m);
        printf("%d\t%d\t\t%d\n", keys[i], div_hash, mult_hash);
    }
    printf("\n");
}

void test_string_hash() {
    printf("=== Testing String Hash Functions ===\n");
    
    const char* strings[] = {"hello", "world", "hash", "function", "test"};
    int m = 10;
    
    printf("String\t\tSimple\tDJB2\n");
    printf("------\t\t------\t----\n");
    
    for (int i = 0; i < 5; i++) {
        int simple_hash = hash_string_simple(strings[i], m);
        int djb2_hash = hash_string_djb2(strings[i], m);
        printf("%s\t\t%d\t%d\n", strings[i], simple_hash, djb2_hash);
    }
    printf("\n");
}

int main() {
    printf("Hash Function Testing Program\n\n");
    
    test_int_hash();
    test_string_hash();
    
    return 0;
}
