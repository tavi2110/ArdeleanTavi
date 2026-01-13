#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    int id;
    struct nodetype *left, *right;
} NodeT;

void preorder(NodeT *p)
{
    if (p != NULL)
    {
        printf("%d ", p->id);
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(NodeT *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        printf("%d ", p->id);
        inorder(p->right);
    }
}

void postorder(NodeT *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->id);
    }
}

NodeT *insertNode(NodeT *root, int key)
{
    /*NodeT *newNode=(NodeT*)malloc(sizeof(NodeT));
    newNode->key=key;
    newNode->left=NULL;
    newNode->right=NULL;
    if (root==NULL)
        return newNode;

    NodeT *current=root;
    NodeT *parent=NULL;

    while (current!=NULL)
    {
        parent=current;
        if (key<current->key)
            current=current->left;
        else if (key>current->key)
            current=current->right;
        else
        {
            free(newNode);
            return root;
        }
    }
    if (key<parent->key)
        parent->left=newNode;
    else
        parent->right=newNode;

    return root;*/
    if (root == NULL)
    {
        root = (NodeT *)malloc(sizeof(NodeT));
        root->id = key;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (key < root->id)
    {
        root->left = insertNode(root->left, key);
    }
    else
    {
        root->right = insertNode(root->right, key);
    }
    return root;
}

NodeT* searchKey(NodeT* root, int key) {
    while (root != NULL) {
        if (key == root->key)
            return root;
        if (key < root->key)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

NodeT* findMin(NodeT* node)
{
    if  (node==NULL)
        return NULL; //arbore gol
    while (node->left!=NULL)
        node=node->left;
    return node;
}
//recursiv
NodeT* findMinRec(NodeT* node)
{
    if ((node==NULL)||(node->left==NULL))
        return node;
    return findMinRec(node->left);
}

NodeT* findMax(NodeT* node)
{
    if  (node==NULL)
        return NULL; //arbore gol
    while(node->right!=NULL)
        node=node->right;
    return node;
}
//recursiv
NodeT* findMaxRec(NodeT* node)
{
    if ((node==NULL)||(node->right==NULL))
        return node;
    return findMaxRec(node->right);
}

NodeT* succesor(NodeT* node)
{
    if (node == NULL)
        return NULL;

    if (node->right!=NULL)
        return findMin(node->right);

    return NULL;
}

NodeT* predecesor(NodeT* node)
{
    if (node == NULL)
        return NULL;

    if (node->left!=NULL)
        return findMax(node->left);

    return NULL;
}

NodeT* deleteNode(NodeT* root, int key)
{
    if (root==NULL)
        return root; // arbore gol

    //Cautam nodul care trebuie sters
    if (key<root->key)
        root->left=deleteNode(root->left, key);
    else if (key>root->key)
        root->right=deleteNode(root->right, key);

    // Am gasit nodul de sters
    else
    {
        // 1: nod fara fiu stang
        if (root->left==NULL)
        {
            NodeT *temp=root->right;
            free(root);
            return temp;
        }
        // 2: nod fara fiu drept
        else if (root->right==NULL)
        {
            NodeT *temp = root->left;
            free(root);
            return temp;
        }

        // 3: are doi fii
        NodeT *temp=findMin(root->right); // succesorul
        root->key=temp->key;              // copiem cheia
        root->right=deleteNode(root->right, temp->key); // stergem succesorul
    }

    return root;
}

int main(void)
{
    NodeT *root=NULL,*p,*q;
    root=insertNode(root,31);
    root=insertNode(root,16);
    root=insertNode(root,45);
    root=insertNode(root,24);
    root=insertNode(root,7);
    root=insertNode(root,19);
    root=insertNode(root,29);


    //////
    inorder(root);//verificare e in ordine, crescator
    printf("\n");
    //p= findMin(root);
    //printf("%d",p->id);
    //printf("\n");
    //q= findMax(root);
    //printf("%d",q->id);

    return 0;
}

