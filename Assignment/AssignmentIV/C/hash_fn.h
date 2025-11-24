/*
   ========================================
   hash_fn.h — declare your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/17: Initial implementation
    - 2025/11/23: Added multiple hash function declarations

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
   Student: 徐婕恩 <s1131515>
 */
#ifndef HASH_FN_H
#define HASH_FN_H

#include <stdio.h>
#include <string.h>

/*
 * ===========================================================================
 * Integer Hash Functions
 * ===========================================================================
 */

/**
 * @brief 整數鍵的除法哈希函數
 * @param key 整數鍵
 * @param m 哈希表大小
 * @return 哈希索引
 */
int myHashInt(int key, int m);

/**
 * @brief 整數鍵的乘法哈希函數
 * @param key 整數鍵
 * @param m 哈希表大小
 * @return 哈希索引
 */
int myHashIntMulti(int key, int m);

/*
 * ===========================================================================
 * String Hash Functions  
 * ===========================================================================
 */

/**
 * @brief 字符串鍵的簡單哈希函數
 * @param str 字符串鍵
 * @param m 哈希表大小
 * @return 哈希索引
 */
int myHashString(const char* str, int m);

/**
 * @brief 字符串鍵的DJB2哈希算法
 * @param str 字符串鍵
 * @param m 哈希表大小
 * @return 哈希索引
 */
int myHashStringDJB2(const char* str, int m);

/**
 * @brief 字符串鍵的簡單加法哈希函數
 * @param str 字符串鍵
 * @param m 哈希表大小
 * @return 哈希索引
 */
int myHashStringSimple(const char* str, int m);

#endif
