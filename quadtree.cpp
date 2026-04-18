#include <iostream>
using namespace std;

struct Node {
    int x, y;
    Node *nw, *ne, *sw, *se;

    Node(int x, int y) {
        this->x = x;
        this->y = y;
        nw = ne = sw = se = NULL;
    }
};

class QuadTree {
    Node* root;

public:
    QuadTree() {
        root = NULL;
    }

    void insert(Node*& node, int x, int y) {
        if (node == NULL) {
            node = new Node(x, y);
            return;
        }

        if (x < node->x) {
            if (y < node->y)
                insert(node->sw, x, y);
            else
                insert(node->nw, x, y);
        } else {
            if (y < node->y)
                insert(node->se, x, y);
            else
                insert(node->ne, x, y);
        }
    }

    void insert(int x, int y) {
        insert(root, x, y);
    }

    bool search(Node* node, int x, int y) {
        if (node == NULL)
            return false;

        if (node->x == x && node->y == y)
            return true;

        if (x < node->x) {
            if (y < node->y)
                return search(node->sw, x, y);
            else
                return search(node->nw, x, y);
        } else {
            if (y < node->y)
                return search(node->se, x, y);
            else
                return search(node->ne, x, y);
        }
    }

    bool search(int x, int y) {
        return search(root, x, y);
    }
};

int main() {
    QuadTree qt;

    qt.insert(5, 5);
    qt.insert(2, 8);
    qt.insert(8, 3);
    qt.insert(1, 1);

    cout << qt.search(2, 8) << endl;
    cout << qt.search(4, 4) << endl;

    return 0;
}
