# CS203A – Data Structures

## Course Information
- **Course Title:** Data Structures
- **Course Code:** CS203A
- **Target Audience:** Undergraduate Students
- **Duration:** 18 Weeks (including Midterm and Final exams)
- **Semester:** 11401
- **Credits:** 3
- **Instructor:** Yu-Feng Huang
- **Course Time(Classroom):**
  - Monday 09:10–10:00 (R60104)
  - Tuesday 15:10–17:00 (R1102)
- **Contact:** [Yu-Feng Huang](mailto:yfhuang@saturn.yzu.edu.tw)  
- **Teaching Assistant:** To be announced
- **Office Hours:**
  - Monday 14:00-16:00 (R1310)
  - Wednesday 14:00–16:00 (R1310)

## personal information
- **name:** 徐婕恩
- **student ID:** s1131515

## Repository description
This repository will document my learning journey in this course and how I overcome various challenges, making it easier to review and reflect on later.

# Assignment IV: Hash Function Design & Observation

## 學生資訊
- **姓名：** 徐婕恩
- **學號：** s1131515

## 完成進度
- [x] C語言哈希函數實現
- [x] C++哈希函數實現
- [x] 編譯配置文件 (Makefile, Makefile.bat)
- [x] README文檔
- [ ] 測試與分析（待實際運行後完成）

## 我的哈希函數設計

### 整數鍵哈希函數
1. **除法哈希 (Division Hash)**
   ```c
   int myHashInt(int key, int m) {
       if (m <= 0) return 0;
       return key % m;
   }
設計理念： 最簡單直接的哈希方法，計算快速，適合均勻分布的整數鍵

乘法哈希 (Multiplication Hash)

c
int myHashIntMulti(int key, int m) {
    if (m <= 0) return 0;
    double A = 0.6180339887; // 黃金比例常數
    double product = key * A;
    double fractional = product - (int)product;
    return (int)(m * fractional);
}
設計理念： 利用黃金比例常數獲得更好的隨機分布，減少規律性

字符串鍵哈希函數
簡單哈希 (Simple Hash)

c
int myHashString(const char* str, int m) {
    if (str == NULL || m <= 0) return 0;
    unsigned long hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = hash * 31 + str[i];
    }
    return hash % m;
}
設計理念： 使用質數31作為乘數，有效減少哈希碰撞

DJB2算法

c
int myHashStringDJB2(const char* str, int m) {
    if (str == NULL || m <= 0) return 0;
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % m;
}
設計理念： 經典的DJB2算法，在實際應用中表現優異，分布均勻

簡單加法哈希

c
int myHashStringSimple(const char* str, int m) {
    if (str == NULL || m <= 0) return 0;
    unsigned int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash += str[i];
    }
    return hash % m;
}
設計理念： 最簡單的實現，計算速度快但可能碰撞較多

實驗設置
測試表格大小 (m): 10, 11, 37

測試數據集:

整數鍵: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60

字符串鍵: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"

編譯器: GCC 和 G++

語言標準: C23 和 C++23

編譯與執行
編譯指令
bash
# Linux/Mac - 編譯兩個版本
make all

# Linux/Mac - 只編譯C版本
make c

# Linux/Mac - 只編譯C++版本
make cxx

# Windows
Makefile.bat
執行指令
bash
# C版本執行
./C/hash_function

# C++版本執行
./CXX/hash_function_cpp
清理編譯文件
bash
# Linux/Mac
make clean

# Windows
Makefile.bat clean
測試結果
待實際運行測試程式後，在此處貼上程式輸出結果和觀察數據

觀察與分析
待實際運行測試程式後，在此處填寫詳細的觀察和分析

開發心得與反思
技術收穫
哈希函數設計原則： 理解了好的哈希函數需要在計算效率、分布均勻性和碰撞率之間取得平衡

表格大小選擇： 認識到質數作為表格大小能有效改善哈希分布，減少規律性

算法比較： 通過實現多種哈希算法，了解了各自適用的場景和優缺點

實踐經驗
C/C++差異： 在實現過程中體會了C和C++在字符串處理、內存管理等方面的差異

錯誤處理： 學習了在哈希函數中加入邊界條件檢查的重要性

代碼組織： 通過頭文件和實現文件的分離，理解了模塊化編程的好處

學習反思
這次作業讓我深刻體會到理論與實踐的結合。在課堂上學習哈希表的概念時，可能只停留在理論層面，但通過實際設計和實現哈希函數，才能真正理解不同設計選擇對性能的影響。特別是看到不同表格大小對分布效果的顯著影響，讓我對數據結構的底層實現有了更直觀的认识。

最後更新： 2025年11月24
