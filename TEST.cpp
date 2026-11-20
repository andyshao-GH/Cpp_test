#include <iostream>                           // 引入 cout 和 endl 等輸出工具
#include <iomanip>                            // 引入 setw 欄位寬度設定工具
#ifdef _WIN32                                 // 以下程式碼只在 Windows 上編譯
#include <windows.h>                          // 引入 Windows 主控台 API
#endif                                        // 結束 Windows 專用的標頭區塊
using namespace std;                          // 讓程式可直接使用 cout 等標準函式庫名稱


void select (int *);                          // 宣告排序函式，接收陣列首元素的指標
void showdata (int *);                        // 宣告列印函式，接收陣列首元素的指標
int main(void)                                // 定義程式的進入點，無須傳入參數
{                                             // 開始主程式
#ifdef _WIN32                                 // 以下設定只在 Windows 上執行
    SetConsoleOutputCP(CP_UTF8);              // 將主控台輸出代碼頁設為 UTF-8，讓中文正確顯示
#endif                                        // 結束 Windows 專用的設定區塊
    int data[6]={9,7,5,3,4,6};                // 建立包含 6 個整數的陣列
    cout<<"原始資料為：";                     // 印出原始資料的提示文字
    showdata(data);                           // 呼叫函式印出陣列的初始內容
    select(data);                             // 呼叫函式將陣列由小到大排序
    return 0;                                 // 回傳 0 表示程式正常結束
}                                             // 結束主程式
void showdata (int data[])                    // 定義列印陣列的函式
{                                             // 開始列印函式
    for (int i=0;i<6;i++)                     // 依序走訪索引 0 到 5
        cout<<setw(3)<<data[i];               // 以至少 3 個字元的欄寬印出目前的元素
    cout<<endl;                               // 印完所有元素後換行並清空輸出緩衝區
}                                             // 結束列印函式

void select (int data[])                      // 定義由小到大排序的函式
{                                             // 開始排序函式
    for(int i=0;i<5;i++)                      // 依序處理索引 0 到 4，第 6 個元素會自然就位
    {                                         // 開始本輪排序
        for(int j=i+1;j<6;j++)                // 從 i 的下一個位置開始，比較到陣列的最後一個元素
        {                                     // 開始處理目前的比較對象
            if(data[i]>data[j])               // 若位置 i 的值大於位置 j 的值，就交換兩者
            {                                 // 開始交換兩個元素
                int tmp;                      // 宣告暫存變數
                tmp=data[i];                  // 先保存位置 i 的原值
                data[i]=data[j];              // 將位置 j 的較小值放到位置 i
                data[j]=tmp;                  // 將暫存的原值放回位置 j，完成交換
            }                                 // 結束交換區塊
        }                                     // 結束內層迴圈，此時位置 i 已放入剩餘元素中的最小值
        cout<<"第 "<<i+1<<" 次排序結果：";    // 印出本輪的排序次數與提示文字
        for (int k=0;k<6;k++) {               // 依序走訪 6 個元素，準備印出本輪結果
            if (k > 0)                        // 從第二個元素開始，每個元素前面加上分隔符號
                cout<<", ";                   // 印出逗號和空格
            cout<<data[k];                    // 印出目前的元素
        }                                     // 結束列印本輪結果的迴圈
        cout<<endl;                           // 印完本輪結果後換行
    }                                         // 結束外層迴圈
    cout<<endl;                               // 所有排序輪次結束後再印一個空行
}                                             // 結束排序函式
