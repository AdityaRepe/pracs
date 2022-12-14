#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};
struct Node *root;

void insert(int val)
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;
    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        struct Node *par, *temp = root;
        while (temp != NULL)
        {
            par = temp;
            if (val == temp->data)
            {
                printf("%d already present!!", val);
                return;
            }
            else if (val < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        if (val < par->data)
        {
            par->left = newnode;
        }
        else
        {
            par->right = newnode;
        }
    }
}

void deleteNode(int val)
{
    struct Node *temp = root, *par;
    while (temp != NULL && temp->data != val)
    {
        par = temp;
        if (val < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (temp != NULL)
    {
        if (temp->right == NULL && temp->left == NULL)
        {
            if (par->right == temp)
                par->right = NULL;
            else
                par->left = NULL;
            free(temp);
            temp = NULL;
        }
        else if (temp->right == NULL)
        {
            temp->data = temp->left->data;
            temp->right = temp->left->right;
            temp->left = temp->left->left;
            free(temp->left);
        }
        else if (temp->left == NULL)
        {
            temp->data = temp->right->data;
            temp->left = temp->right->left;
            temp->right = temp->right->right;
            free(temp->right);
        }
        else
        {
            printf("has 2 children!");
            struct Node *prev, *prece;
            prece = temp->left;
            while (prece->right != NULL)
            {
                prev = prece;
                prece = prece->right;
            }
            temp->data = prece->data;
            prev->right = prece->left;
            free(prece);
        }
    }
    else
    {
        printf("Value not found!\n");
    }
}

void inorder(struct Node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

void preorder(struct Node *temp)
{
    if (temp != NULL)
    {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}
void postorder(struct Node *temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ",temp->data);
    }
}
int main()
{
    int choice;
    do
    {
        printf("\n1. Insert\n2. Delete\n3. Inorder Traversal\n4. Preorder Traversal \n5. Postorder Traversal \n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number of values to insert: ");
            int n;
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                int x;
                printf("Enter a value: ");
                scanf("%d", &x);
                insert(x);
            }
            break;
        case 2:
            // Delete
            if (root == NULL)
            {
                printf("BST is empty\n");
            }
            else
            {
                int x;
                printf("Enter a value to delete: ");
                scanf("%d", &x);
                deleteNode(x);
            }
            break;
        case 3:
            // Inorder
            if (root == NULL)
            {
                printf("BST is empty\n");
            }
            else
            {
                inorder(root);
                printf("\n");
            }
            break;
        case 4:
            // Preorder
            if (root == NULL)
            {
                printf("BST is empty\n");
            }
            else
            {
                preorder(root);
                printf("\n");
            }
            break;
        case 5:
            //Postorder
            if(root==NULL)
            {
                printf("BST is empty\n");
            }
            else
            {
                postorder(root);
                printf("\n");
            }
        case 6:
            break;
        default:
            printf("Enter a valid choice!!\n");
        }
    } while (choice != 6);

    return 0;
}
