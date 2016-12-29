#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left,*right;
}node;

node *find(node *,int);
node *insert(node *,int);
node *delet(node *,int);
node *create();
void inorder(node *T);
void preorder(node *T);
void postorder(node *T);

int main()
{
    node *root=NULL,*p;
    int x,op;
    do
    {
        printf("\n\n1)Create\n2)Delete\n3)Search\n4)Preorder");
        printf("\n5)Inorder\n6)Postorder\n7)Insert\n8)Quit");
        printf("\nEnter Your Choice :");
        scanf("%d",&op);
        switch(op)
        {
            case 1: root=create();
                    break;
            case 2: printf("\nEnter the key to be deleted :");
                    scanf("%d",&x);
                    root=delet(root,x);
                    break;
            case 3: printf("\nEnter the key to be searched :");
                    scanf("%d",&x);
                    p=find(root,x);
                    if(p==NULL)
                        printf("\n ***** Not Found****");
                    else
                        printf("\n ***** Found*****");
                    break;
            case 4: preorder(root);
                    break;
            case 5: inorder(root);
                    break;
            case 6: postorder(root);
                    break;
            case 7: printf("\nEnter a data to be inserted : ");
                    scanf("%d",&x);
                    root=insert(root,x);
        }
    }while(op!=8);

    return 0;
}


void inorder(node *T)
{
    if(T!=NULL)
    {
        inorder(T->left);
        printf("%d\t",T->data);
        inorder(T->right);
    }
}

void preorder(node *T)
{
    if(T!=NULL)
    { printf("%d\t",T->data);
        preorder(T->left);
        preorder(T->right);
    }
}
void postorder(node *T)
{
    if(T!=NULL)
    {
        postorder(T->left);
        postorder(T->right);
        printf("%d\t",T->data);
    }
}

node *find(node *root,int x)
{
    while(root!=NULL)
    {
        if(x==root->data)
            return(root);
        if(x>root->data)
            root=root->right;
        else
            root=root->left;
    }
    return(NULL);
}

node *insert(node *T,int x)
{
    node *p,*q,*r;
    r=(node*)malloc(sizeof(node));
    r->data=x;
    r->left=NULL;
    r->right=NULL;
    if(T==NULL)
        return(r);
    p=T;
    while(p!=NULL)
    {
        q=p;
        if(x>p->data)
            p=p->right;
        else
            if(x<p->data)
                p=p->left;
            else
            {
                printf("\nDuplicate data : ");
                return(T);
            }
    }
    if(x>q->data)
        q->right=r;  
    else
        q->left=r;   
    return(T);
}

node *delet(node *T,int x)
{
    node *temp;
    if(T==NULL)
    {
        printf("\nElement not found :");
        return(T);
    }
    if(x < T->data)                
    {
        T->left=delet(T->left,x);
        return(T);
    }
    if(x > T->data)                
    {
        T->right=delet(T->right,x);
        return(T);
    }
    if(T->left==NULL && T->right==NULL)   
    {
        temp=T;
        free(temp);
        return(NULL);
    }
    if(T->left==NULL)
    {
        temp=T;
        T=T->right;
        free(temp);
        return(T);
    }
    if(T->right==NULL)
    {
        temp=T;
        T=T->left;
        free(temp);
        return(T);
    }

    temp=T->right;
    while(temp->left !=NULL)
        temp=temp->left;
    T->data=temp->data;
    T->right=delet(T->right,temp->data);
    return(T);
}

node *create()
{
    int n,x,i;
    node *root;
    root=NULL;
    printf("\nEnter no. of nodes :");
    scanf("%d",&n);
    printf("\nEnter tree values :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        root=insert(root,x);
    }
    return(root);
}
