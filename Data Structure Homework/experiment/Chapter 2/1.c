#include <stdio.h>

void Merge(int m, int arr1[], int n, int arr2[], int merged[]);

int main(void)
{
    // 声明并读取第一个数组的长度
    int m;
    scanf("%d", &m);

    // 声明并读取第一个数组
    int arr1[m];
    for (size_t i = 0; i < m; i++)
    {
        scanf("%d", &arr1[i]);
    }
    
    // 声明并读取第二个数组的长度
    int n;
    scanf("%d", &n);

    // 声明并读取第二个数组
    int arr2[n];
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }

    // 声明第三个数组，然后将合并后的数组保存进来
    int arr3[m + n];
    Merge(m, arr1, n, arr2, arr3);
    
    // 按行打印第三个数组
    for (size_t i = 0; i < m + n; i++)
    {
        printf("%d\n", arr3[i]);
    }

    return 0;
}

void Merge(int m, int arr1[], int n, int arr2[], int merged[])
{
    int i = 0; // arr1 的索引
    int j = 0; // arr2 的索引
    int k = 0; // merged 的索引

    // 同时遍历两个数组，选择较小的元素放入 merged
    while (i < m && j < n)
    {
        if (arr1[i] <= arr2[j])
        {
            merged[k++] = arr1[i++];
        }
        else
        {
            merged[k++] = arr2[j++];
        }
    }

    // 如果 arr1 还有剩余元素，全部放入 merged
    while (i < m)
    {
        merged[k++] = arr1[i++];
    }

    // 如果 arr2 还有剩余元素，全部放入 merged
    while (j < n)
    {
        merged[k++] = arr2[j++];
    }
}