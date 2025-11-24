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

## 開發與測試環境
- **作業系統：** Windows 11
- **開發工具：** GitHub網頁編輯器 + 線上編譯器 (OnlineGDB)
- **測試環境：** OnlineGDB C/C++ 編譯器
- **版本控制：** GitHub網頁界面

## 學生資訊
- **姓名：** 徐婕恩
- **學號：** s1131515

## 完成進度
- [x] C語言哈希函數實現
- [x] C++哈希函數實現
- [x] 編譯配置文件 (Makefile, Makefile.bat)
- [x] README文檔
- [x] 測試與分析

## 我的哈希函數設計

### 整數鍵哈希函數
1. **除法哈希 (Division Hash)**
   ```c
   int myHashInt(int key, int m) {
       if (m <= 0) return 0;
       return key % m;
   }
設計理念： 最簡單直接的哈希方法，計算快速，適合均勻分布的整數鍵

虛擬碼： hash = key MOD m

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

虛擬碼： hash = floor(m * (key * A MOD 1))

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

虛擬碼： hash = (hash * 31 + char) MOD m

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

虛擬碼： hash = hash * 33 + char

實驗設置
測試表格大小 (m): 10, 11, 37

測試數據集:

整數鍵: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60

字符串鍵: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"

編譯器: GCC 和 G++

語言標準: C23 和 C++23

Compilation, Build, Execution and Output
Linux 環境編譯測試
bash
# 編譯所有版本
make all

# 只編譯C版本
make c

# 只編譯C++版本  
make cxx

# 清理編譯文件
make clean
Windows 環境編譯測試
batch
# 編譯所有版本
Makefile.bat

# 只編譯C版本
Makefile.bat c

# 只編譯C++版本
Makefile.bat cxx

# 清理編譯文件
Makefile.bat clean
Output
程式執行後會輸出整數鍵和字符串鍵在不同表格大小下的哈希索引值，用於後續分析key、table size與index value間的關係。

Results
基於測試結果觀察到以下關鍵關係：

Key 與 Index 關係
整數鍵： 當表格大小為非質數時，連續整數鍵會產生規律性的索引分布；使用質數表格大小能打破這種規律性

字符串鍵： 不同哈希算法對字符串的處理效果各異，DJB2算法通常能提供較均勻的分布

Index 與 Table Size (m) 關係
質數優勢： 質數表格大小能有效減少碰撞，提供更均勻的索引分布

大小選擇： 較大的質數提供更多的索引空間，但需要權衡記憶體使用效率

Analysis
哈希函數設計比較
透過比較不同哈希函數的表現，觀察到：

除法哈希計算效率高，但對特定輸入模式敏感

乘法哈希能提供更好的隨機分布，適合處理有規律的輸入數據

字符串哈希中，DJB2算法在分布均勻性方面表現優異

碰撞分析
非質數表格大小容易導致較高的碰撞率

質數表格大小能顯著降低碰撞發生機率

哈希算法的選擇對碰撞率有直接影響

性能權衡
在哈希函數設計中需要在計算複雜度、分布均勻性和碰撞率之間取得平衡。簡單的算法計算快但可能碰撞多，複雜的算法分布好但計算成本高。

參考資料
DJB2 Hash Algorithm

哈希函數設計原則 - Wikipedia

質數在哈希表中的應用 - CP Algorithms

Reflection
1. 哈希函數設計特性拿捏
在設計哈希函數時，發現需要在計算效率與分布質量間取得平衡。簡單的除法哈希雖然計算快速，但對特定輸入模式會產生規律性分布；而複雜的算法雖能提供更好分布，但計算成本較高。

2. 減少碰撞的設計策略
透過實驗學習到幾個有效減少碰撞的策略：

選擇質數作為表格大小，能有效打破輸入數據的規律性

在字符串哈希中，使用適當的乘數常數（如31、33）能改善分布均勻性

較大的表格大小能提供更多索引空間，直接降低碰撞機率

3. 實踐學習收穫
這次作業讓我體會到理論分析與實際測試的差異。在實際實現哈希函數時，需要考慮數據特性、應用場景和性能要求。透過親手實現和測試，對哈希表的工作原理有了更深入的理解，這對於未來在實際項目中選擇合適的數據結構具有重要意義。

最後更新： 2025年11月24
