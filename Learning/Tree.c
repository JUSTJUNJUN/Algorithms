#include <stdio.h>

typedef int EleType;
typedef struct TNode *PtrToNode;

struct TNode {
    EleType     Element;/* 数据 */
    PtrToNode       FirstChild;/* 第一个儿子节点 */
    PtrToNode       NextSibling;/* 兄弟节点 */
};

/* 格式化输出Unix系统的根目录树 */
typedef struct TNode *DirFilePtr;

#define DirFormatSpan   "    "
#define DirElementType  "%d"

static void PrintDir(DirFilePtr *D, int Depth)
{
    if (D == NULL || Depth < 0) return;

    while (Depth != 0) {
        printf("DirFormatSpan");
        --Depth;
    }

    printf("DirElementType\n", D->Element);

    return;
}

static int CountDir(DirFilePtr *D)
{
    return sizeof(D);
}

static int IsLegalDir(DirFilePtr *D)
{
    return (D != NULL);
}

static int IsDir(DirFilePtr *D)
{
    return (D->FirstChild != NULL);
}

static void ListDir(DirFilePtr *D, int Depth)
{
    DirFilePtr *tmp = NULL;

    if (IsLegalDir(D)) {
        PrintDir(D);
        if (IsDir(D)) {
            tmp = D->FirstChild;
            while (tmp != NULL) {
                ListDir(tmp, Depth + 1);
                tmp = tmp->NextSibling;
            }
        }
    }

    return;
}

static void CountDirMem(DirFilePtr *D)
{
    int TotalSize = 0;

    if (IsLegalDir(D)) {
        if (IsDir(D)) {
            TotalSize = CountDir(D);
            tmp = D->FirstChild;
            while (tmp != NULL) {
                TotalSize += CountDirMem(tmp);
                tmp = tmp->NextSibling;
            }
        }
    }

    return TotalSize;
}

static void ListRootDir(DirFilePtr *D)
{
    ListDir(D, 0);
    return;
}


