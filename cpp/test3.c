#include <stdio.h>
#include <string.h>

int main()
{
    int n,m = 0;
    char str1[100] = { 0 };
    char str2[100][100] = { 0 };
    char str3[100][100] = {0};


    // 输入字符串 str1

    fgets(str1, sizeof(str1), stdin);  // 使用 fgets 代替 gets
    str1[strcspn(str1, "\n")] = 0;



    // 输入整数 n
    scanf_s("%1d", &m);

    scanf_s("%1d", &n);

    while (getchar() != '\n');


    // 输入 n 个字符串

    
    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < 100; j++)
        {
           
            str2[i][j] = (char)getchar(); // 读取字符

            
            if (str2[i][j] == '\n') // 遇到换行符，结束读取
            {
                str2[i][j] = '\0';
                break;
            }
        }   
       
    }
    memcpy(str3, str2, sizeof(str2)); // 复制 str2 到 str3
    
    
    // 查找并打印包含 str1 的 str2[i]
    if (m)
    {
        for (int i = 0; i < n; i++)
        {
            if (strstr(str2[i], str1) != NULL)
            {
                printf("%s\n", str2[i]); // 打印字符串
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                if (str2[i][j] >= 'a' && str2[i][j] <= 'z')
                {
                    str2[i][j] = str2[i][j] - ('a'- 'A'); // 转换为小写字母
                }
                if(str1[j] >= 'a' && str1[j] <= 'z')
                {
                    str1[j] = str1[j] - ('a'- 'A'); // 转换为小写字母
                }
            }
            if (strstr(str2[i], str1) != NULL)
            {
                printf("%s\n", str3[i]); // 打印字符串
            }
        }
    }
    return 0;
}