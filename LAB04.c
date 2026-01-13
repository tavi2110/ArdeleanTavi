#include <stdio.h>
#include <stdlib.h>

//structura unui nod
typedef struct node_type
{
int id;
struct node_type *left, *right;
} NodeT;


/1
NodeT *createBinTreeFromFile(FILE *f)
{
    int c;
    fscanf(f, "%d", &c);
    if (c==0)
        return NULL;
    NodeT *p = (NodeT *)malloc(sizeof(NodeT));
    p->id=c;
    p->left=createBinTreeFromFile(f);
    p->right=createBinTreeFromFile(f);
    return p;
}

/2
void inorder(NodeT *p) //parcurgere in inordine
{
    if (p!=NULL)
    {
        inorder(p->left);
        printf("%d ", p->id);
        inorder(p->right);
    }
}

void postorder(NodeT *p) //parcurgere in postordine
{
    if (p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->id);
    }
}

/3
int leaf_node(NodeT *node)
{
    if (node==NULL)
        return 0;

    if (node->left==NULL && node->right==NULL)
    {
        printf("%d ", node->id);
        return 1;
    }
    return leaf_node(node->left)+leaf_node(node->right);
}

/4
int internal_nodes(NodeT *node)
{
    if (node==NULL)
        return 0;
    if (node->left==NULL && node->right==NULL)
        return 0;
    return 1+internal_nodes(node->left)+internal_nodes(node->right);
}

/5
int height(NodeT *node)
{
    int hL, hR;
    if (node==NULL)
        return -1;
    hL=height(node->left);
    hR=height(node->right);
    if (hL>hR)
        return 1+hL;
    else
        return 1+hR;
}

/6
NodeT *search(NodeT *root, int key)
{
    if (root==NULL)
        return NULL;

    if (root->id==key)
        return root;

    NodeT *left=search(root->left, key);
    if (left!=NULL)
        return left;
    return search(root->right, key);
}
//utlizare
/*NodeT *p = search(root, 9);
if (p != NULL)
    printf("Inaltime nod: %d\n", height(p));*/

/7
NodeT *creBalBinTree(int nbNodes)
{
    if (nbNodes<=0)
        return NULL;
    NodeT *p=(NodeT *)malloc(sizeof(NodeT));

    int nLeft=nbNodes/2;
    int nRight=nbNodes-nLeft-1;

    printf("Valoare nod: ");
    scanf("%d", &p->id);

    p->left=creBalBinTree(nLeft);
    p->right=creBalBinTree(nRight);

    return p;
}



int main()
{
    FILE *f = fopen("ArboreBinar.txt", "r");
    NodeT *root = createBinTreeFromFile(f);
    fclose(f);

    printf("Inordine: ");
    inorder(root);

    printf("\nPostordine: ");
    postorder(root);

    printf("\nFrunze: ");
    printf("\nNumar frunze = %d\n", leaf_node(root));

    printf("Noduri interne = %d\n", internal_nodes(root));
    printf("Inaltime arbore = %d\n", height(root));

    return 0;
}
