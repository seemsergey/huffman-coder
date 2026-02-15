//
// huffman.h - структуры и функции для дерева Хаффмана
//

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stddef.h>

typedef struct {
    unsigned char ch;      // символ
    char code[256];        // строка вида "0101010"
    size_t codeLen;        // длина кода в битах
} HuffmanCode;

typedef struct TreeNode {
    unsigned char ch; // символ (только для листьев)
    size_t freq; // частота (вес узла)
    struct TreeNode *left; // левый потомок
    struct TreeNode *right; // правый потомок
    size_t height; // высота поддерева (для детерминированности)
} TreeNode;

// Функции работы с деревом
TreeNode *createNode(unsigned char symbol, size_t freq, TreeNode *left, TreeNode *right, size_t height);
void clearTree(TreeNode *root);

// Функции работы с кучей
void heapInsert(TreeNode **heap, size_t *heapSize, TreeNode *node);
TreeNode *minSearch(TreeNode **heap, size_t *heapSize);

// Построение дерева и кодовой таблицы
void buildCodeTree(TreeNode **heap, size_t *heapSize);
TreeNode *createHuffmanTree(TreeNode **heap, size_t *heapSize);

#endif // HUFFMAN_H
