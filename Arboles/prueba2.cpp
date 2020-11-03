#include <iostream>
using namespace std;

void imprimir(BTreeNode<T> *node) {
    if (node != NULL) {
        cout << "└--";
        cout << "12";
        cout << "├--";
        cout << node->get_left()->get_val();
        cout << "├--";
        cout << node->get_right()->get_val();
        imprimir(node->get_left());
        imprimir(node->get_right());
    }
}

int main() {
    imprimir(root);
}