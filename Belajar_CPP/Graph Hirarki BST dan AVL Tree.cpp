#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int info;
    struct node *left;
    struct node *right;
} * root;

class BST
{
public:
    void fun_1(int, node **, node **);
    void fun_2(int);
    void fun_3(node *, node *);
    void fun_4(node *, int);
    void case_a(node *, node *);
    void case_b(node *, node *);
    void case_c(node *, node *);
    BST() { root = NULL; }
};

int main()
{
    int choice, num;
    BST bst;
    node *temp;
    while (1)
    {
        cout << "-----------------"     << endl;
        cout << "Operasi pada Binary Search Tree" << endl;
        cout << "-----------------"     << endl;
        cout << "1. Tampilkan"          << endl;
        cout << "2. Hapus Element"      << endl;
        cout << "3. Insert Element"     << endl;
        cout << "4. Keluar."            << endl;
        cout << "Ketik angka yang akan anda pilih: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Tampilkan BST:" << endl;
            bst.fun_4(root, 1);
            cout << endl;
            break;

        case 2:
            if (root == NULL)
            {
                cout << "Tree kosong" << endl;
                continue;
            }
            cout << "Ketik angka yang akan dihapus dari BST: ";
            cin >> num;
            bst.fun_2(num);
            break;

        case 3:
            temp = new node;
            cout << "Ketik angka yang akan diinsert ke BST: ";
            cin >> temp->info;
            bst.fun_3(root, temp);
            break;

        case 4:
            exit(1);

        default:
            cout << "Tidak ada angka tersebut!" << endl;
        }
    }
}

void BST::fun_1(int item, node **par, node **loc)
{
    node *ptr, *ptrsave;
    if (root == NULL)
    {
        *loc = NULL;
        *par = NULL;
        return;
    }

    if (item == root->info)
    {
        *loc = root;
        *par = NULL;
        return;
    }

    if (item < root->info)
        ptr = root->left;
    else
        ptr = root->right;
    ptrsave = root;

    while (ptr != NULL)
    {
        if (item == ptr->info)
        {
            *loc = ptr;
            *par = ptrsave;
            return;
        }

        ptrsave = ptr;

        if (item < ptr->info)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    *loc = NULL;
    *par = ptrsave;
}

void BST::fun_3(node *tree, node *newnode)
{
    if (root == NULL)
    {
        root = new node;
        root->info = newnode->info;
        root->left = NULL;
        root->right = NULL;
        cout << "Node Root ditambahkan ke dalam Tree" << endl;
        return;
    }

    if (tree->info == newnode->info)
    {
        cout << " Node yang akan ditambahkan sudah berada di dalam tree " << endl;
        return;
    }

    if (tree->info > newnode->info)
    {
        if (tree->left != NULL)
        {
            fun_3(tree->left, newnode);
        }
        else
        {
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            return;
        }
    }
    else
    {
        if (tree->right != NULL)
        {
            fun_3(tree->right, newnode);
        }
        else
        {
            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            return;
        }
    }
}

void BST::fun_2(int item)
{
    node *parent, *location;
    if (root == NULL)
    {
        cout << "Tree dalam keadaan empty" << endl;
        return;
    }

    fun_1(item, &parent, &location);

    if (location == NULL)
    {
        cout << "Node yang dicari tidak dapat ditemukan di dalamtree " << endl;
        return;
    }

    if (location->left == NULL && location->right == NULL)
        case_a(parent, location);

    if (location->left != NULL && location->right == NULL)
        case_b(parent, location);

    if (location->left == NULL && location->right != NULL)
        case_b(parent, location);

    if (location->left != NULL && location->right != NULL)
        case_c(parent, location);

    free(location);
}

void BST::case_a(node *par, node *loc)
{
    if (par == NULL)
    {
        root = NULL;
    }
    else
    {
        if (loc == par->left)
            par->left = NULL;
        else
            par->right = NULL;
    }
}
void BST::case_b(node *par, node *loc)
{
    node *child;
    if (loc->left != NULL)
        child = loc->left;
    else
        child = loc->right;
    if (par == NULL)
    {
        root = child;
    }
    else
    {
        if (loc == par->left)
            par->left = child;
        else
            par->right = child;
    }
}
void BST::case_c(node *par, node *loc)
{
    node *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->right;
    while (ptr->left != NULL)
    {
        ptrsave = ptr;
        ptr = ptr->left;
    }
    suc = ptr;
    parsuc = ptrsave;
    if (suc->left == NULL && suc->right == NULL)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);
    if (par == NULL)
    {
        root = suc;
    }
    else
    {
        if (loc == par->left)
            par->left = suc;
        else
            par->right = suc;
    }
    suc->left = loc->left;
    suc->right = loc->right;
}
void BST::fun_4(node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        fun_4(ptr->right, level + 1);
        cout << endl;
        if (ptr == root)
            cout << "Root->:  ";
        else
        {
            for (i = 0; i < level; i++)
                cout << "       ";
        }
        cout << ptr->info;
        fun_4(ptr->left, level + 1);
    }
}
