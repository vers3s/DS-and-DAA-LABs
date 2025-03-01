#include <bits/stdc++.h>
using namespace std;

class avl_node {
public:
    string word, meaning;
    avl_node *left, *right;
    
    avl_node(string w, string m) {
        word = w;
        meaning = m;
        left = right = NULL;
    }
};

class avlTree {
public:
    avl_node *root;
    avlTree() { root = NULL; }

    int height(avl_node *);
    int diff(avl_node *);
    avl_node *rr_rotation(avl_node *);
    avl_node *ll_rotation(avl_node *);
    avl_node *rl_rotation(avl_node *);
    avl_node *lr_rotation(avl_node *);
    avl_node *balance(avl_node *);
    avl_node *insert(avl_node *, string, string);
    void insert();
    void display(avl_node *, int);
    void inorder(avl_node *);
    void preorder(avl_node *);
    void postorder(avl_node *);
};

avl_node* avlTree::ll_rotation(avl_node *parent) {
    avl_node *temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

avl_node* avlTree::rr_rotation(avl_node *parent) {
    avl_node *temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

avl_node* avlTree::lr_rotation(avl_node *parent) {
    parent->left = rr_rotation(parent->left);
    return ll_rotation(parent);
}

avl_node* avlTree::rl_rotation(avl_node *parent) {
    parent->right = ll_rotation(parent->right);
    return rr_rotation(parent);
}

int avlTree::height(avl_node *temp) {
    if (!temp) return 0;
    return 1 + max(height(temp->left), height(temp->right));
}

int avlTree::diff(avl_node *temp) {
    return height(temp->left) - height(temp->right);
}

avl_node* avlTree::balance(avl_node *temp) {
    int bal_factor = diff(temp);
    if (bal_factor > 1) {
        if (diff(temp->left) > 0)
            temp = ll_rotation(temp);
        else
            temp = lr_rotation(temp);
    } else if (bal_factor < -1) {
        if (diff(temp->right) > 0)
            temp = rl_rotation(temp);
        else
            temp = rr_rotation(temp);
    }
    return temp;
}

void avlTree::insert() {
    char ch;
    do {
        string word, meaning;
        cout << "Enter word and its meaning: ";
        cin >> word >> meaning;
        root = insert(root, word, meaning);
        cout << "Enter 'Y' to continue: ";
        cin >> ch;
    } while (ch == 'Y');
}

avl_node* avlTree::insert(avl_node *root, string word, string meaning) {
    if (!root) return new avl_node(word, meaning);
    
    if (word < root->word)
        root->left = insert(root->left, word, meaning);
    else if (word > root->word)
        root->right = insert(root->right, word, meaning);
    else
        return root;

    return balance(root);
}

void avlTree::display(avl_node *ptr, int level) {
    if (ptr != NULL) {
        display(ptr->right, level + 1);
        cout << endl;
        if (ptr == root)
            cout << "Root -> ";
        for (int i = 0; i < level; i++)
            cout << "        ";
        cout << ptr->word;
        display(ptr->left, level + 1);
    }
}

int main() {
    avlTree tree;
    tree.insert();
    cout << "\nAVL Tree Dictionary:\n";
    tree.display(tree.root, 1);
    return 0;
}
