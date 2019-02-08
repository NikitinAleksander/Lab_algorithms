#include <fstream>

using namespace std;

struct tree_node {
    int value;
    tree_node *left, *right;
};

tree_node *insert(tree_node *temp_root, int value) {
    if (temp_root == nullptr) {
        auto *node = new tree_node;
        node->value = value;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    } else if (value < temp_root->value) {
        temp_root->left = insert(temp_root->left, value);
    } else if (value > temp_root->value) {
        temp_root->right = insert(temp_root->right, value);
    }
    return temp_root;
}

tree_node *remove(tree_node *temp_root, int value) {
    if (temp_root == nullptr) return temp_root;

    if (value < temp_root->value) {
        temp_root->left = remove(temp_root->left, value);
    } else if (value > temp_root->value) {
        temp_root->right = remove(temp_root->right, value);
    } else if (temp_root->left != nullptr && temp_root->right != nullptr) {
        tree_node *min_node = temp_root->right;
        while (min_node->left != nullptr) min_node = min_node->left;

        temp_root->value = min_node->value;
        temp_root->right = remove(temp_root->right, temp_root->value);
    } else if (temp_root->left != nullptr) {
        temp_root = temp_root->left;
    } else {
        temp_root = temp_root->right;
    }

    return temp_root;
}

bool contains(tree_node *root, int value) {
    tree_node *node = root;
    while (node != nullptr) {
        if (value == node->value) break;

        if (value < node->value) node = node->left;
        else node = node->right;
    }
    return node != nullptr;
}

int prev(tree_node *root, int value) {
    tree_node *temp = nullptr;
    tree_node *node = root;
    while (node != nullptr) {
        if (value > node->value) {
            temp = node;
            node = node->right;
        } else {
            node = node->left;
        }
    }

    if (temp == nullptr) return INT_MIN;
    return temp->value;
}

int next(tree_node *root, int value) {
    tree_node *temp = nullptr;
    tree_node *node = root;
    while (node != nullptr) {
        if (value < node->value) {
            temp = node;
            node = node->left;
        } else {
            node = node->right;
        }
    }

    if (temp == nullptr) return INT_MIN;
    return temp->value;
}

int main() {
    ifstream fin("bstsimple.in");
    ofstream fout("bstsimple.out");

    tree_node *root = nullptr;
    string s;
    int x;

    while (fin >> s) {
        if (s == "insert") {
            fin >> x;
            root = insert(root, x);
        } else if (s == "delete") {
            fin >> x;
            root = remove(root, x);
        } else if (s == "exists") {
            fin >> x;
            fout << (contains(root, x) ? "true" : "false") << endl;
        } else if (s == "next") {
            fin >> x;
            x = next(root, x);
            if (x == INT_MIN) fout << "none" << endl;
            else fout << x << endl;
        } else if (s == "prev") {
            fin >> x;
            x = prev(root, x);
            if (x == INT_MIN) fout << "none" << endl;
            else fout << x << endl;
        }
    }

    fin.close();
    fout.close();

    return 0;
}
