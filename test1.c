#include <stdio.h>
#include <time.h>

int main() {
    time_t start_time, end_time;
    double time_diff;

    time(&start_time);
    // 模拟一个耗时操作
    for (int i = 0; i < 100000000; i++)
    {
        int j[1000] = {1};
        
    }

    time(&end_time);
    time_diff = difftime(end_time, start_time);
    printf("Time difference: %.2f seconds\n", time_diff);

    return 0;
}