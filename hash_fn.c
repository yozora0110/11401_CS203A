#include "hash_fn.h"

/**
 * @brief 整數鍵的除法哈希函數
 * @param key 整數鍵
 * @param m 哈希表大小
 * @return 哈希索引
 */
int hash_int_division(int key, int m) {
    if (m <= 0) return 0;  // 錯誤處理
    return key % m;
}

/**
 * @brief 整數鍵的乘法哈希函數
 * @param key 整數鍵
 * @param m 哈希表大小
 * @return 哈希索引
 */
int hash_int_multiplication(int key, int m) {
    if (m <= 0) return 0;
    
    double A = 0.6180339887; // 黃金比例的分数部分
    double product = key * A;
    double fractional = product - (int)product;
    return (int)(m * fractional);
}

/**
 * @brief 字符串鍵的簡單哈希函數
 * @param key 字符串鍵
 * @param m 哈希表大小
 * @return 哈希索引
 */
int hash_string_simple(const char* key, int m) {
    if (key == NULL || m <= 0) return 0;
    
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = hash * 31 + key[i];
    }
    return hash % m;
}

/**
 * @brief 字符串鍵的DJB2哈希算法
 * @param key 字符串鍵
 * @param m 哈希表大小
 * @return 哈希索引
 */
int hash_string_djb2(const char* key, int m) {
    if (key == NULL || m <= 0) return 0;
    
    unsigned long hash = 5381;
    int c;
    
    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    
    return hash % m;
}
