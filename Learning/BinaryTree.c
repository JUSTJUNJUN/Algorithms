#include <stdio.h>

/* 二叉树数据结构定义 */
typedef int ElementType;/* 元素类型 */
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

/* 二叉树先序遍历：1.访问结点；2.先序遍历其左子树；3.先序遍历其右子树 */
void PreOrderTraversal(BinTree BT)
{
    if (BT) {
        printf("%d", BT->Data);//访问
        PreOrderTraversal(BT->Left);//左递归
        PreOrderTraversal(BT->Right);//右递归
    }
    return;
}

/* 二叉树中序遍历：1.中序遍历其左子树；2.访问结点；3.中序遍历其右子树 */
void InOrderTraversal(BinTree BT)
{
    if (BT) {
        InOrderTraversal(BT->Left);//左递归
        printf("%d", BT->Data);//访问
        InOrderTraversal(BT->Right);//右递归
    }
    return;
}

/* 二叉树后序遍历：1.后序遍历其左子树；2.后序遍历其右子树；3.访问结点 */
void PostOrderTraversal(BinTree BT)
{
    if (BT) {
        PostOrderTraversal(BT->Left);//左递归
        PostOrderTraversal(BT->Right);//右递归
        printf("%d", BT->Data);//访问
    }
    return;
}

/* 二叉树中序遍历（非递归方法） */
void InOrderTraversalByCircle(BinTree BT)
{
    BinTree T = BT;
    Stack S = CreatStack(MaxSize);/* 创建并初始化堆栈 */
    while (T || !IsEmptyS(S)) {
        while (T) {/* 一直向左并将沿途结点压入堆栈 */
            Push(S, T);/* 第一次访问到结点 */
            T = T->Left;
        }
        if (!IsEmptyS(S)) {
            T = Pop(S);/* 弹出堆栈 *//* 第二次访问到结点 */
            printf("%5d", T->Data);/* 打印结点 */
            T = T->Right;/* 转向右子树 */
        }
        
    }
    if (BT) {
        InOrderTraversal(BT->Left);//左递归
        printf("%d", BT->Data);//访问
        InOrderTraversal(BT->Right);//右递归
    }
    return;
}

/* 层序遍历 */
void LayerTraversal(BinTree BT)
{
    BinTree T;
    Queue Q = CreatQueue(MaxSize);

    if (!BT) return;/* 空树直接返回 */
    InQueue(Q, BT);
    while (!IsEmptyQ(Q)) {
        T = OutQueue(Q);
        printf("%05d\n", T->Data);/*访问出队结点*/
        If (T->Left) InQueue(Q, T->Left);
        If (T->Right) InQueue(Q, T->Right);
    }
    
    return;
}

int binary_search(int *arr, int arr_len, int key)
{
    int left = 0, right = arr_len -1, mid = arr_len/2;
    int tmp = 0;

    do {
        if (arr[left] == key) {
            tmp = left;
        } else if (arr[right] == key) {
            tmp = right;
        } else if (arr[mid] == key) {
            tmp = mid;
        }
            
        break;
    } while (right > left);
    

    return -1;
}