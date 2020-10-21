#include "arbolBinario.hpp"

int main() {
    BinarySearchTree<int> btree;
    btree.insertNodeRecursive(12);
    btree.insertNodeRecursive(7);
    btree.insertNodeRecursive(4);
    btree.insertNodeRecursive(2);
    btree.insertNodeRecursive(9);
    btree.insertNodeRecursive(8);
    btree.insertNodeRecursive(11);
    btree.insertNodeRecursive(21);
    btree.insertNodeRecursive(16);
    btree.insertNodeRecursive(19);
    btree.insertNodeRecursive(25);
    btree.print_preorder();
    btree.printV2();

    return 0;
}