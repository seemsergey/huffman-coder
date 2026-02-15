//
// Created by SeemS on 15.02.2026.
// Main entry point for Huffman encoder/decoder
//

#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"

int main() {
    // Пример инициализации
    TreeNode *heap[256];
    size_t heapSize = 0;
    size_t freq[256] = {0};

    printf("Huffman Encoder/Decoder\n");
    printf("======================\n\n");

    // TODO: заполнить частоты символов из входного потока/файла
    // TODO: создать ноды для каждого символа с ненулевой частотой
    // TODO: вставить ноды в кучу
    // TODO: построить дерево Хаффмана
    // TODO: сгенерировать коды для каждого символа
    // TODO: реализовать кодирование и декодирование

    // Пример использования:
    // freq['A'] = 5;
    // freq['B'] = 9;
    // freq['C'] = 12;
    // freq['D'] = 13;
    // freq['E'] = 16;
    // freq['F'] = 45;
    //
    // for (int i = 0; i < 256; i++) {
    //     if (freq[i] > 0) {
    //         TreeNode *node = createNode(i, freq[i], NULL, NULL, 0);
    //         if (node != NULL) {
    //             heapInsert(heap, &heapSize, node);
    //         }
    //     }
    // }
    //
    // TreeNode *root = createHuffmanTree(heap, &heapSize);
    // if (root != NULL) {
    //     // Обработка дерева
    //     clearTree(root);
    // }

    return 0;
}