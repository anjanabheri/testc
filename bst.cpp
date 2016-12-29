
#include <stdio.h>
#include <malloc.h>

#include "include.h"

typedef struct _node
{
    int data;
    struct _node* left;
    struct _node* right;
} node;

/*Function protoypes*/
void printGivenLevel(node* root, int level);
int height(node* node);
void printLevelOrder(node* root);
void inOrder(node* root);
node* LowestData(node* root);
node* find(node* tree, int data);
void inOrderSuccessor(node *root, int data);

node* new_node(int value)
{
    node* n;
    n = (node*)malloc(sizeof(node));
    n->data = value;
    n->left = 0;
    n->right = 0;

    cout << "New node, data; " << value << ", at: " << n << endl;

    return n;
}

node* insert(node* n, int value)
{
    if (n == 0)
    {
        return(new_node(value));
    }
    if (value < n->data)
    {
        n->left  = insert(n->left, value);
    }
    else
    {
        n->right = insert(n->right, value);
    }
    return n;
}

main()
{
    node* tree = 0;
    int depth = 0;
    tree = insert(tree, 42);
    insert(tree, 44);
    insert(tree, 50);
    insert(tree, 5);
    insert(tree, 10);
    insert(tree, 15);

    depth = height(tree);

    cout << endl;
    cout << "Height of the tree: " << depth << endl;

    cout << endl;
    cout << "Level Order traversal of binary tree is " << endl;
    printLevelOrder(tree);

    cout << endl;

    int dataToFind = 5;
    cout << "Finding data: " << dataToFind << endl;
    find(tree, dataToFind);
    dataToFind = 10;
    cout << "Finding data: " << dataToFind << endl;
    find(tree, dataToFind);
    dataToFind = 15;
    cout << "Finding data: " << dataToFind << endl;
    find(tree, dataToFind);
    dataToFind = 42;
    cout << "Finding data: " << dataToFind << endl;
    find(tree, dataToFind);
    dataToFind = 44;
    cout << "Finding data: " << dataToFind << endl;
    find(tree, dataToFind);
    dataToFind = 50;
    cout << "Finding data: " << dataToFind << endl;
    find(tree, dataToFind);
    dataToFind = 60;
    cout << "Finding data: " << dataToFind << endl;
    find(tree, dataToFind);

    cout << endl;
    cout << "InOrder Traversal: " << endl;
    inOrder(tree);

    cout << endl;
    cout << "Finding Lowest Data: " << endl;
    LowestData(tree);

    cout << endl;
    cout << "Finding InOrder Successor" << endl;
    inOrderSuccessor(tree, 5);
#if 1
    inOrderSuccessor(tree, 10);
    inOrderSuccessor(tree, 15);
    inOrderSuccessor(tree, 42);
    inOrderSuccessor(tree, 44);
    inOrderSuccessor(tree, 50);
    inOrderSuccessor(tree, 60);
#endif

    return 0;
}

node* find(node* tree, int data)
{
    while (tree)
    {
        if (data > tree->data)
            tree = tree->right;
        else if (data < tree->data)
            tree = tree->left;
        else
            break;
    }

    if (tree)
        cout << "Data " << data << " found at: " << tree << endl;
    else
        cout << "Data " << data << " not found" << endl;

    return tree;
}

/* Function to print level order traversal a tree*/
void printLevelOrder(node* root)
{
    int h = height(root);
    int i;
    printf("\n");
    for (i = 1; i <= h; i++)
    {
        printGivenLevel(root, i);
        printf("\n");
    }
}

/* Print nodes at a given level */
void printGivenLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

/* Compute the "height" of a tree -- the number of
 *     nodes along the longest path from the root node
 *         down to the farthest leaf node.*/
int height(node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
            return(lheight + 1);
        else return(rheight + 1);
    }
}

void inOrder(node* root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << "data: " << root->data << ", node: " << root << endl;
    inOrder(root->right);

    return;
}

node* LowestData(node* root)
{
    if (root == NULL)
        return NULL;

    while (root)
    {
        if (root->left == NULL)
        {
            cout << "Lowest Data: " << root->data << endl;
            break;
        }
        root = root->left;
    }

    return root;
}

void deleteData(node* root, int data)
{
    node* findNode;

    //findNode = find(data);

}

void inOrderSuccessor(node *tree, int data)
{
    node* findNode = NULL;
    node* successor = NULL;

    findNode = find(tree, data);

    if (findNode == NULL)
    { 
        cout << "Data: " << data << " not found" << endl;
        return;
    }

    cout << "Data: " << data << ", found at: " << findNode << endl;

    if (findNode->right != NULL)
    {
        successor = LowestData(findNode->right);
        cout << "Successor of data: " << data << ", is: " << successor->data << ", at: " << successor << endl;
        return;
    }

    while(tree != NULL)
    {
        if (findNode->data < tree->data)
        {
            successor = tree;
            tree = tree->left;
        }
        else if (findNode->data > tree->data)
        {
            tree = tree->right;
        }
        else
            break;
    }

    if (successor)
        cout << "Successor of data: " << data << ", is: " << successor->data << ", at: " << successor << endl;
    else
        cout << "Successor not found " << endl;

    return;
}
