#ifndef _BST_HPP
#define _BST_HPP
#include <iostream>
#include <vector>
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
        if (node == NULL) {
            return h;
        } else {
            h += 1;
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

    int getProfundidad(T val) {
        BTreeNode<T> *ptr = find(val);
        int prof = getSHeight(root) - getSHeight(ptr);
        return prof;
    }

    void yellowPath(BTreeNode<T> *node) {
        cout << node->get_val() << ", ";
        int left;
        int right;
        if (node->get_left() != NULL) {
            left = getSHeight(node->get_left());
        } else {
            left = 0;
        }
        if (node->get_right() != NULL) {
            right = getSHeight(node->get_right());
        } else {
            right = 0;
        }
        if (node->get_left() != NULL || node->get_right() != NULL) {
            getSHeight(node->get_left()) > getSHeight(node->get_right()) ? yellowPath(node->get_left()) : yellowPath(node->get_right());
        }
        /*if (getSHeight(node->get_left()) > getSHeight(node->get_right())) {
            yellowPath(node->get_left())
        } else {
            
        }*/
    }

    void myChildren(BTreeNode<T> *node) {
        if (node->get_left() != NULL) {
            cout << node->get_left()->get_val() << ", ";
            myChildren(node->get_left());
        }
        if (node->get_right() != NULL) {
            cout << node->get_right()->get_val() << ", ";
            myChildren(node->get_right());
        }
    }

    int getLevel(T val) {
        return getProfundidad(val);
    }

    void getAllDecendats(T val) {
        BTreeNode<T> *ptr = find(val);
        myChildren(ptr);
    }

    void longPath() {
        yellowPath(root);
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

    void printSpacesV2(int factor) {
        for (size_t i = 0; i < factor; i++) {
            cout << " ";
        }
    }
    void printLinesV2(int factor) {
        for (size_t i = 0; i < factor; i++) {
            cout << "-";
        }
    }

    vector<vector<string>> getVals(BTreeNode<T> *node, vector<vector<string>> &vals, string desicion) {
        if (node != NULL) {
            int h = getProfundidad(node->get_val());
            string left = "";
            string right = "";
            if (node->get_left() != NULL) {
                left = to_string(node->get_left()->get_val());
            }
            if (node->get_right() != NULL) {
                right = to_string(node->get_right()->get_val());
            }
            vector temp{desicion, to_string(h), left, right};
            vals.insert(vals.begin() + h, temp);

            getVals(node->get_left(), vals, "L");
            getVals(node->get_right(), vals, "R");
        }

        return (vals);
    }

    void v1Print(int h, BTreeNode<T> *node) {
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
            v1Print(h, node->get_left());
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

            v1Print(h, node->get_right());

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

            v1Print(h, node->get_right());
        }
    }

    void printV1() {
        int h = getHeight();
        cout << "└";
        cout << "-";
        cout << "-";
        cout << root->get_val() << endl;

        v1Print(h, root);
    }

    void printArco(int factL, int factEsp, int numOfArcos) {
        if (numOfArcos == 1) {
            printSpacesV2(3);
        }
        for (size_t i = 0; i < numOfArcos; i++) {
            if (i == 0) {
                printSpacesV2(factEsp);
            }
            if (i % 2 != 0) {
                printSpacesV2(factEsp);
            }

            cout << "┌";
            printLinesV2(factL);
            cout << "┴";
            printLinesV2(factL);
            cout << "┐";
            printSpacesV2(getHeight());
        }
    }

    void printArcoVals(int factL, int factEsp, int numOfArcoVals, vector<vector<string>> vals, int h) {
        vector<vector<string>> ImportantVals;
        string searchingSide = "L";
        if (numOfArcoVals == 1) {
            printSpacesV2(3);
        }
        for (size_t i = 0; i < vals.size(); i++) {
            if (vals[i][1] == to_string(h)) {
                ImportantVals.push_back(vals[i]);
            }
        }
        for (size_t i = 0; i < numOfArcoVals; i++) {
            int index = 0;
            for (size_t j = 0; j < ImportantVals.size(); j++) {
                if (ImportantVals[j][0] == searchingSide) {
                    index = j;
                }
            }
            if (ImportantVals[index][0] == searchingSide) {
                printSpacesV2(factEsp);
                cout << ImportantVals[index][2];
                printSpacesV2(factEsp * 2);
                cout << ImportantVals[index][3];
            } else {
                printSpacesV2(factEsp);
                cout << "  ";
                printSpacesV2(factEsp * 2);
                cout << "  ";
            }
            if (i % 2 == 0) {
                printSpacesV2(numOfArcoVals + 3);
            }

            if (!ImportantVals.empty()) {
                ImportantVals.erase(ImportantVals.begin() + index);
            }
            if (searchingSide == "L") {
                searchingSide = "R";
            } else {
                searchingSide = "L";
            }
        }
    }

    void printV2() {
        int h = getSHeight(root);
        int deep = getProfundidad(root->get_val());
        int factorEsp = h * h;
        int factorLinea = h * h;
        vector<vector<string>> vals;

        if (h > 1) {
            cout << endl;
            printSpacesV2(factorEsp * 2 + 3);
            cout << root->get_val() << endl;

            getVals(root, vals, "L");

            int factorDeCresimiento = 1;

            for (size_t i = 1; i < h; i++) {
                printArco(factorEsp, factorLinea, factorDeCresimiento);
                cout << endl;
                printArcoVals(factorEsp, factorLinea, factorDeCresimiento, vals, i - 1);
                cout << endl;
                factorEsp = (h - i) * (h - i);
                factorLinea = (h - i) * (h - i);
                factorDeCresimiento *= 2;
            }
        }
    }
};

#endif