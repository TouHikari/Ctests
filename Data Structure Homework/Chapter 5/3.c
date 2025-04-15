#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { ATOM, LIST } ElemTag; // ATOM：原子，LIST：子表

typedef struct GLNode {
    ElemTag tag;                    // 用于区分原子结点和表结点
    union {
        char atom;                  // 原子的值域
        struct {
            struct GLNode *hp;     // 指向表头
            struct GLNode *tp;     // 指向表尾
        } ptr;
    };
} GLNode, *GList;

GList CreateGList(const char **s);  // 解析下一个广义表(或原子)
GList CreateList(const char **s);   // 解析用逗号分隔的一系列表元素
int DepthByHead(GList gl);
int DepthByTail(GList gl);

int main(void)
{
    char input[200];
    scanf("%s", input);

    // 将指针指向输入串开头
    const char *s = input;
    // 解析为广义表
    GList gl = CreateGList(&s);

    // 输出深度
    printf("%d\n", DepthByHead(gl));
    printf("%d\n", DepthByTail(gl));

    return 0;
}

/*  
CreateGList: 解析一个广义表或原子
约定： 
- 若遇到 '(' 则创建表节点 LIST，解析内部内容后直到遇到配对的 ')' 才结束 
- 若遇到 ')' 则说明后续无元素，返回 NULL 
- 若既不是 '(' 也不是 ')'，则视为 ATOM 
*/
GList CreateGList(const char **s)
{
    // 跳过可能的空白字符（若有需要可加循环判断）
    while (**s == ' ') (*s)++;

    // 若串已结束，则返回空
    if (**s == '\0') {
        return NULL;
    }

    if (**s == '(') {
        // 创建一个表节点
        GList gl = (GList)malloc(sizeof(GLNode));
        gl->tag = LIST;
        (*s)++; // 跳过 '('

        // 检查是否空表: "()" 表示空表
        if (**s == ')') {
            gl->ptr.hp = NULL;
            gl->ptr.tp = NULL;
            (*s)++; // 跳过 ')'
        } else {
            // 解析表内部多个元素 (用逗号隔开)，得到“头结点”
            gl->ptr.hp = CreateList(s);
            // 到这里我们已经读取了一串元素，直到遇到 ')' 或 '\0'
            gl->ptr.tp = NULL; // 在本实现里，hp 本身就是“头+尾”的链，tp 不再重复使用

            // 若此时遇到 ')', 跳过它
            if (**s == ')') {
                (*s)++;
            }
        }
        return gl;

    } else if (**s == ')') {
        // 如果直接遇到 ')', 说明无元素
        return NULL;
    } else {
        // 否则解析为一个原子
        GList gl = (GList)malloc(sizeof(GLNode));
        gl->tag = ATOM;
        gl->atom = **s;
        (*s)++; // 向后移动一位
        return gl;
    }
}

/*
CreateList: 用于解析表内用逗号分隔的一系列元素。
典型过程：
- 先解析“第一个元素”，存在 head 里
- 若遇到 ','，则继续解析后续元素，并将其挂到 head->ptr.tp 
- 若遇到 ')' 或串结束，则停止解析（剩下的部分由上层处理）
*/
GList CreateList(const char **s)
{
    // 若遇到空或到达 ')'，说明此处没有元素
    if (**s == '\0' || **s == ')') {
        return NULL;
    }

    // 先解析一个元素
    GList head = CreateGList(s);
    // 然后看接下来的字符
    if (**s == ',') {
        (*s)++; // 跳过逗号
        // head 的表尾指向剩余表
        head->ptr.tp = CreateList(s);
    } else {
        // 如果没有逗号，则没有后续元素
        // 是原子时无 ptr.tp；若是 LIST，则 ptr.tp 在本例也置空
        if (head->tag == LIST) {
            head->ptr.tp = NULL;
        }
    }
    return head;
}

// 表头分析法：DepthByHead
// 常用定义：
// - 若 gl == NULL (空表) => depth = 1
// - 若 gl->tag == ATOM => depth = 0
// - 否则 => depth = max(DepthByHead(gl->ptr.hp), DepthByHead(gl->ptr.tp)) + 1
int DepthByHead(GList gl)
{
    if (!gl) return 1;              // 空表深度约定为 1
    if (gl->tag == ATOM) return 0;  // 原子深度为 0

    // 对 LIST，分别递归计算表头 hp 和表尾 tp 的深度，取最大值 + 1
    int hd = DepthByHead(gl->ptr.hp);
    int td = DepthByHead(gl->ptr.tp);
    return (hd > td ? hd : td) + 1;
}

// 表尾分析法：DepthByTail
// 一般教材里也可约定同样的公式，因为最终要算最大嵌套深度：
// - gl == NULL => depth = 1 
// - 原子 => depth = 0
// - 否则 => depth = max(DepthByTail(gl->ptr.hp), DepthByTail(gl->ptr.tp)) + 1
int DepthByTail(GList gl)
{
    if (!gl) return 1;
    if (gl->tag == ATOM) return 0;

    int hd = DepthByTail(gl->ptr.hp);
    int td = DepthByTail(gl->ptr.tp);
    return (hd > td ? hd : td) + 1;
}