#include <iostream>
using namespace std;

void printSpaces(int factor) {
    for (size_t i = 0; i < factor; i++) {
        cout << " ";
    }
}
void printLines(int factor) {
    for (size_t i = 0; i < factor; i++) {
        cout << "-";
    }
}

void v2Print(int h) {
    if (h > 1) {
        int fectorEsp = h * 11 - 1 * 11;
        int fectorLinea = h * (9 / 2) + (-1 / 3) * (9 / 2);
        printSpaces(fectorEsp - 1);
        cout << "7";
        printSpaces(fectorEsp * 2 + 3);
        cout << "19" << endl;
        printSpaces(fectorEsp / 2);
        cout << "┌";
        printLines(fectorLinea / 2);
        cout << "┴";
        printLines(fectorLinea / 2);
        cout << "┐";
        printSpaces(fectorEsp * 2 - fectorLinea / 2 - 3);
        cout << "┌";
        printLines(fectorLinea / 2);
        cout << "┴";
        printLines(fectorLinea / 2);
        cout << "┐" << endl;
        h--;
        v2Print(h);
    } else {
        cout << h << endl;
        int fectorEsp = h * 11 - 1 * 11;
        int fectorLinea = h * (9 / 2) + (-1 / 3) * (9 / 2);
        printSpaces(fectorEsp);
        cout << "7";
        printSpaces(fectorEsp);
        cout << "19" << endl;
        printSpaces(fectorEsp);
        cout << "┌";
        printLines(fectorLinea);
        cout << "┴";
        printLines(fectorLinea);
        cout << "┐";
        printSpaces(fectorEsp);
        cout << "┌";
        printLines(fectorLinea);
        cout << "┴";
        printLines(fectorLinea);
        cout << "┐" << endl;
    }
}

void printV2() {
    int h = 3;
    int fectorEsp = h * 11 - 1 * 11;
    int fectorLinea = h * (9 / 2) + (-1 / 3) * (9 / 2);

    printSpaces(fectorEsp);
    cout << "12" << endl;
    printSpaces(fectorEsp / 2 - 1);
    cout << "┌";
    printLines(fectorLinea);
    cout << "┴";
    printLines(fectorLinea);
    cout << "┐" << endl;
    /*for (size_t i = 0; i < 3; i++) {
        printSpaces(fectorEsp / 2 - 1);
        cout << "|";
        printSpaces(fectorEsp + 3);
        cout << "|" << endl;
    }*/
    h--;
    v2Print(h);
}

int main() {
    printV2();
}