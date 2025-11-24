/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h
    - 2025/11/23: Implemented multiple hash functions

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
   Student: 徐婕恩 <s1131515>
 */

#include "hash_fn.h"

/**
 * @brief 整數鍵的除法哈希函數
 * @param key 整數鍵
 * @param m 哈希表大小
 * @return 哈希索引
 */
int myHashInt(int key, int m) {
    if (m <= 0) return 0;  // 錯誤處理
    return key % m;  // 除法方法
}

/**
 * @brief 整數鍵的乘法哈希函數
 * @param key 整數鍵
 * @param m 哈希表大小
 * @return 哈希索引
 */
int myHashIntMulti(int key, int m) {
    if (m <= 0) return 0;
    
    // 使用黃金比例常數 (√5-1)/2 ≈ 0.6180339887
    double A = 0.6180339887;
    double product = key * A;
    double fractional = product - (int)product;  // 取小數部分
    return (int)(m * fractional);
}

/**
 * @brief 字符串鍵的簡單哈希函數
 * @param str 字符串鍵
 * @param m 哈希表大小
 * @return 哈希索引
 */
int myHashString(const char* str, int m) {
    if (str == NULL || m <= 0) return 0;
    
    unsigned long hash = 0;
    // 使用乘以31的簡單哈希算法
    for (int i = 0; str[i] != '\0'; i++) {
        hash = hash * 31 + str[i];
    }
    return (int)(hash % m);
}

/**
 * @brief 字符串鍵的DJB2哈希算法
 * @param str 字符串鍵
 * @param m 哈希表大小
 * @return 哈希索引
 */
int myHashStringDJB2(const char* str, int m) {
    if (str == NULL || m <= 0) return 0;
    
    unsigned long hash = 5381;
    int c;
    
    // DJB2算法：hash = hash * 33 + c
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    
    return (int)(hash % m);
}

/**
 * @brief 字符串鍵的簡單加法哈希函數
 * @param str 字符串鍵
 * @param m 哈希表大小
 * @return 哈希索引
 */
int myHashStringSimple(const char* str, int m) {
    if (str == NULL || m <= 0) return 0;
    
    unsigned int hash = 0;
    
    // 簡單的字符相加方法
    for (int i = 0; str[i] != '\0'; i++) {
        hash += str[i];
    }
    
    return hash % m;
}
