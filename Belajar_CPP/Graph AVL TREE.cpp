/* Kode C++ untuk impelementasi Penambahan/Insertion dari AVL Tree
 (dari berbagai sumber)
*/
#include <iostream>
#include <cstdlib>
using namespace std;

struct avl_node
{ // deklarasi node pada AVL
    int data;
    struct avl_node *left;
    struct avl_node *right;
} * root;
class avlTree
{ // Deklarasi Class node AVL Tree
public:
    int height(avl_node *);
    int diff(avl_node *);
    avl_node *fun1(avl_node *);
    avl_node *fun2(avl_node *);
    avl_node *fun3(avl_node *);
    avl_node *fun4(avl_node *);
    avl_node *balance(avl_node *);
    avl_node *insert(avl_node *, avl_node *);
    void display(avl_node *, int);
    avlTree()
    {
        root = NULL;
    }
};

int main()
{
    int choice, item;
    avlTree avl;
    avl_node *temp;
    while (1)
    {
        cout << "\n---------------------" << endl;
        cout << " Implementasi AVL Tree" << endl;
        cout << "\n---------------------" << endl;
        cout << "1.Tambah Node pada AVL Tree " << endl;
        cout << "2.Tampilkan AVL Tree" << endl;
        cout << "3.Keluar" << endl;
        cout << "Ketik opsi yang anda pilih: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            temp = new avl_node;
            cout << "Ketik angka yang akan ditambahkan ke AVL Tree: ";
            cin >> item;
            temp->data = item;
            root = avl.insert(root, temp);
            break;
        case 2:
            if (root == NULL)
            {
                cout << "Tree kosong, tidak dapat menampilkan Tree" << endl;
                continue;
            }
            cout << "AVL Tree yang Seimbangnya adalah:" << endl;
            avl.display(root, 1);
            break;
        case 3:
            exit(1);
            break;
        default:
            cout << "Pilihan yang anda masukkan tidak ada!" << endl;
        }
    }
    return 0;
}

avl_node *avlTree::fun1(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

avl_node *avlTree::fun2(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

avl_node *avlTree::fun3(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = fun1(temp);
    return fun2(parent);
}

avl_node *avlTree::fun4(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = fun2(temp);
    return fun1(parent);
}

//Fungsi fun1 digunakan untuk melakukan rotasi subtree kanan-dalam ke kiri ketika kondisi subtree kanan lebih tinggi daripada subtree kiri dan subtree kanan-luar lebih tinggi daripada subtree kanan-dalam.

//Fungsi fun2 digunakan untuk melakukan rotasi subtree kiri-dalam ke kanan ketika kondisi subtree kiri lebih tinggi daripada subtree kanan dan subtree kiri-luar lebih tinggi daripada subtree kiri-dalam.

//Fungsi fun3 digunakan untuk melakukan rotasi subtree kiri-dalam ke kanan ketika kondisi subtree kiri lebih tinggi daripada subtree kanan dan subtree kiri-dalam lebih tinggi daripada subtree kiri-luar.

//Fungsi fun4 digunakan untuk melakukan rotasi subtree kanan-dalam ke kiri ketika kondisi subtree kanan lebih tinggi daripada subtree kiri dan subtree kanan-dalam lebih tinggi daripada subtree kanan-luar.

avl_node *avlTree::insert(avl_node *root, avl_node *newnode)
{
    if (root == NULL)
    {
        root = new avl_node;
        root->data = newnode->data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (newnode->data == root->data)
    {
        cout << "Node yang akan ditambahkan sudah berada di dalam tree" << endl;
        return 0;
    }
    else if (newnode->data < root->data)
    {
        root->left = insert(root->left, newnode);
        root = balance(root);
    }
    else if (newnode->data >= root->data)
    {
        root->right = insert(root->right, newnode);
        root = balance(root);
    }
    return root;
}
