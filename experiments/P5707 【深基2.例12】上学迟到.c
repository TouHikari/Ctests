/*
【深基2.例12】上学迟到

## 题目描述
学校和 yyy 的家之间的距离为 s 米，而 yyy 以 v 米每分钟的速度匀速走向学校。
在上学的路上，yyy 还要额外花费 10 分钟的时间进行垃圾分类。
学校要求必须在上午 8:00  到达，请计算在不迟到的前提下，yyy 最晚能什么时候出门。
由于路途遥远，yyy 可能不得不提前一点出发，但是提前的时间不会超过一天。

## 输入格式
一行两个正整数 s, v，分别代表路程和速度。

## 输出格式
输出一个 24 小时制下的时间，代表 yyy 最晚的出发时间。
输出格式为 HH:MM，分别代表该时间的时和分。必须输出两位，不足前面补 0。

## 样例 #1

### 样例输入 #1
    100 99

### 样例输出 #1
    07:48

## 提示
对于 100% 的数据，1 ≥ s, v ≤ 10^4。
*/

#include <stdio.h>
#define MINUTES_PER_HOUR 60     // 每小时的分钟数
#define MINUTES_PER_DAY (24 * 60) // 每天的分钟数
#define HOURS_PER_DAY 24        // 每天的小时数
// 由于垃圾分类 10 分钟，因此简化为从 7:50 开始前推
#define ENDTIME_HOUR 7          // 最晚到达时间的小时部分
#define ENDTIME_MINUTE 50       // 最晚到达时间的分钟部分

int main(void)
{
    /* 声明变量并读取输入 */
    double distance, velocity;              // 路程和速度
    scanf("%lf %lf", &distance, &velocity); // 读取输入

    /* 计算路程总时间 */
    double totalTime = distance / velocity; // 计算所用分钟
    int useMinute = (totalTime - (int)totalTime) > 0 ?  // 判断是否能除尽
                    distance / velocity + 1 : distance / velocity;
    // 除不尽则意味着有余数，所以要再提前 1 分钟出门
    // 注意显式和隐式的强制类型转换，丢弃小数部分

    /* 从 7:50 开始前推最晚出发时间 */
    int startHour, startMinute; // 声明存储最终结果的变量
    // 计算当天开始到到达时间的分钟数
    int todayMinute = ENDTIME_HOUR * MINUTES_PER_HOUR + ENDTIME_MINUTE;
    // 前推出发时间
    if (useMinute <= todayMinute)   // 如果没有到前一天
    {
        startMinute = todayMinute - useMinute;    // 计算当天开始到出发的分钟数
    }
    else                            // 如果到了前一天
    {
        useMinute -= todayMinute;   // 算出从前一天 24 点前推的分钟数
        startMinute = MINUTES_PER_DAY - useMinute;  // 计算前一天开始到出发的分钟数
    }
    // 将分钟转为小时+分钟
    startHour = startMinute / MINUTES_PER_HOUR; // 整型除法
    startMinute %= MINUTES_PER_HOUR;
    
    /* 输出结果 */
    printf("%02d:%02d", startHour, startMinute);

    return 0;
}