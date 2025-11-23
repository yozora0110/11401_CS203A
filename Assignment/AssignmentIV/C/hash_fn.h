#ifndef HASH_FN_H
#define HASH_FN_H

// 整數哈希函數
int hash_int_division(int key, int m);
int hash_int_multiplication(int key, int m);

// 字符串哈希函數
int hash_string_simple(const char* key, int m);
int hash_string_djb2(const char* key, int m);

#endif
