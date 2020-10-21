#ifndef _BST_HPP
#define _BST_HPP
#include <iostream>
using namespace std;

template <class T>
class BTreeNode {
   protected:
    T val;
    BTreeNode<T> *left;
    BTreeNode<T> *right;

   public:
    ~BTreeNode<T>(){};
    BTreeNode<T>() = default;
    BTreeNode<T>(T _val) {
        this->val = _val;
        this->left = NULL;
        this->right = NULL;
    }
    BTreeNode<T>(T _val, BTreeNode<T> *_left, BTreeNode<T> *_right) {
        this->val = _val;
        this->left = _left;
        this->right = _right;
    };

    T get_val() { return val; };
    BTreeNode<T> *get_left() { return left; };
    BTreeNode<T> *get_right() { return right; };
    void set_val(T _val) { val = _val; };
    void set_left(BTreeNode<T> *node) { left = node; };
    void set_right(BTreeNode<T> *node) { right = node; };
};

template <class T>
class BinarySearchTree {
   protected:
    BTreeNode<T> *root;

   public:
    ~BinarySearchTree<T>() {}
    BinarySearchTree<T>() { root = NULL; }

    BTreeNode<T> *find(T val) {
        BTreeNode<T> *ptr = root;
        while (ptr != NULL) {
            if (ptr->get_val() == val) {
                return ptr;
            }
            ptr = ptr->get_val() > val ? ptr->get_left() : ptr->get_right();
        }
        return NULL;
    }

    bool insertNode(T val) {
        BTreeNode<T> *ptr = root;
        BTreeNode<T> *pre = NULL;

        while (ptr != NULL) {
            if (ptr->get_val() == val) {
                return false;
            }
            pre = ptr;
            ptr = ptr->get_val() > val ? ptr->get_left() : ptr->get_right();
        }
        BTreeNode<T> *newNode = new BTreeNode<T>(val);
        if (pre == NULL) {
            root = newNode;
        } else {
            ptr->get_val() < val ? pre->set_right(newNode) : pre->set_left(newNode);
        }
        return true;
    }

    BTreeNode<T> *insertNodeR(BTreeNode<T> *node, T val) {
        if (node == NULL) {
            return new BTreeNode<T>(val);
        }
        if (val < node->get_val()) {
            node->set_left(insertNodeR(node->get_left(), val));
        } else {
            node->set_right(insertNodeR(node->get_right(), val));
        }
        return node;
    }
    bool insertNodeRecursive(T val) {
        root = insertNodeR(root, val);
        return true;
    };

    BTreeNode<T> *sucessor(BTreeNode<T> *node) {
        BTreeNode<T> *ptr = node->get_right();
        while (ptr->get_left() != NULL) {
            ptr = ptr->get_left();
        }
        return ptr;
    };

    BTreeNode<T> *delete_node(BTreeNode<T> *node, int key) {
        // caso base
        if (node == NULL) return node;

        // si el valor a eliminar es menor que el valor del nodo
        // entonces está en el subarbol izquierdo
        if (key < node->get_val())
            node->set_left(delete_node(node->get_left(), key));

        // si el valor a eliminar es mayor que el valor del nodo
        // entonces está en el subarbol derecho
        else if (key > node->get_val())
            node->set_right(delete_node(node->get_right(), key));

        // si el valor a eliminar es igual que el valor del nodo
        // entonces este es el elemento que queremos eliminar
        else {
            // nodos con solo un hijo o sin hijos
            if (node->get_left() == NULL) {
                BTreeNode<T> *temp = node->get_right();
                delete node;
                return temp;
            } else if (node->get_right() == NULL) {
                BTreeNode<T> *temp = node->get_left();
                delete node;
                return temp;
            }

            // nodo con dos hijos, entonces obtener el sucesor
            BTreeNode<T> *temp = sucessor(node);

            // copiar el valor del sucesor al nodo que contiene el elemento a borrar
            node->set_val(temp->get_val());

            // borrar el sucesor
            node->set_right(delete_node(node->get_right(), temp->get_val()));
        }
        return node;
    };

    void delete_node(T val) {
        root = delete_node(root, val);
    };

    void print_preorder(BTreeNode<T> *node) {
        if (node != NULL) {
            cout << node->get_val() << ", ";
            print_preorder(node->get_left());
            print_preorder(node->get_right());
        }
    };

    int heightR(int h, BTreeNode<T> *node) {
        h += 1;
        if (node == NULL) {
            return h;
        } else {
            int hIzquierda = heightR(h, node->get_left());
            int hDerecha = heightR(h, node->get_right());
            return hIzquierda > hDerecha ? hIzquierda : hDerecha;
        }
    }

    int getHeight() {
        int h = 0;
        h = heightR(h, root);
        return h;
    }

    int getSHeight(BTreeNode<T> *node) {
        int h = 0;
        h = heightR(h, node);
        return h;
    }

    void print_preorder() {
        print_preorder(root);
        cout << endl;
    };

    void printSpaces() {
        for (size_t i = 0; i < 3; i++) {
            cout << " ";
        }
    }
    void printLines() {
        cout << "--";
    }

    void v2Print(int h, BTreeNode<T> *node) {
        if (node != NULL && node->get_left() != NULL) {
            int hMe = h - getSHeight(node);
            for (size_t i = 0; i < hMe + 1; i++) {
                printSpaces();
                if (i < hMe) {
                    cout << "|";
                }
            }
            cout << "├";
            printLines();
            cout << node->get_left()->get_val() << endl;
            v2Print(h, node->get_left());
            if (node->get_right() != NULL) {
                for (size_t i = 0; i <= hMe; i++) {
                    //cout << i << " " << hMe;
                    printSpaces();
                    if (i < hMe && hMe != 0) {
                        cout << "|";
                    } else if (i == hMe - 1) {
                        cout << " ";
                    }
                }
                cout << "└--" << node->get_right()->get_val() << endl;
            } else {
                //cout << endl;
            }

            v2Print(h, node->get_right());

        } else if (node != NULL && node->get_right() != NULL) {
            int hMe = h - getSHeight(node);
            if (node->get_right() != NULL) {
                for (size_t i = 0; i <= hMe; i++) {
                    //cout << i << " " << hMe;
                    printSpaces();
                    if (i < hMe && hMe != 0) {
                        cout << "|";
                    } else if (i == hMe - 1) {
                        cout << " ";
                    }
                }
                cout << "└--" << node->get_right()->get_val() << endl;
            } else {
                //cout << endl;
            }

            v2Print(h, node->get_right());
        }
    }

    void printV2() {
        int h = getHeight();
        cout << "└";
        cout << "-";
        cout << "-";
        cout << root->get_val() << endl;

        v2Print(h, root);
    }
};

#endif