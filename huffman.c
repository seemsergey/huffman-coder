//
// huffman.c - реализация дерева Хаффмана и кучи
//
#include "huffman.h"
#include <stdlib.h>

TreeNode *createNode(unsigned char symbol, size_t freq, TreeNode *left, TreeNode *right, size_t height) {
    TreeNode *node = malloc(sizeof(TreeNode));
    if (node == NULL) {
        return NULL;
    }
    node->ch = symbol;
    node->freq = freq;
    node->left = left;
    node->right = right;
    node->height = height;
    return node;
}

void clearTree(TreeNode *root) {
    if (root != NULL) {
        clearTree(root->left);
        clearTree(root->right);
        free(root);
    }
}

// Куча (heap) должна быть организована в main или выделена статически пользователем!
// Здесь реализуются только операции.

static void delHeapNode(int minIndx, TreeNode **heap, size_t *heapSize) {
    heap[minIndx] = heap[*heapSize - 1];
    (*heapSize)--;
}

void heapInsert(TreeNode **heap, size_t *heapSize, TreeNode *node) {
    heap[(*heapSize)++] = node;
}

TreeNode *minSearch(TreeNode **heap, size_t *heapSize) {
    if (*heapSize == 0) return NULL;
    int minIndx = 0;
    for (size_t i = 1; i < *heapSize; i++) {
        if (heap[i]->freq < heap[minIndx]->freq) {
            minIndx = i;
        } else if (heap[i]->freq == heap[minIndx]->freq) {
            if (heap[i]->height < heap[minIndx]->height) {
                minIndx = i;
            } else if (heap[i]->height == heap[minIndx]->height) {
                int isLeafI = (heap[i]->left == NULL && heap[i]->right == NULL);
                int isLeafMin = (heap[minIndx]->left == NULL && heap[minIndx]->right == NULL);
                if (!isLeafI && isLeafMin) {
                    minIndx = i;
                } else if (isLeafI == isLeafMin && isLeafI) {
                    if (heap[i]->ch < heap[minIndx]->ch) {
                        minIndx = i;
                    }
                }
            }
        }
    }
    TreeNode *minElem = heap[minIndx];
    delHeapNode(minIndx, heap, heapSize);
    return minElem;
}

void buildCodeTree(TreeNode **heap, size_t *heapSize) {
    TreeNode *left = minSearch(heap, heapSize);
    TreeNode *right = minSearch(heap, heapSize);
    size_t height = ((left->height > right->height) ? left->height : right->height) + 1;
    TreeNode *nodeOver = createNode(0, left->freq + right->freq, left, right, height);
    heap[(*heapSize)++] = nodeOver;
}

TreeNode *createHuffmanTree(TreeNode **heap, size_t *heapSize) {
    if (*heapSize == 0) return NULL;
    if (*heapSize == 1) return heap[0];

    while (*heapSize > 1) {
        buildCodeTree(heap, heapSize);
    }
    return heap[0];
}