#include<iostream.h>
#include<stdlib.h>
struct tree
{
    int info;
    struct tree *left;
    struct tree *right;
};

struct tree *insert(struct tree *,int);
void inorder(struct tree *);
void postorder(struct tree *);
void preorder(struct tree *);
void findroot(struct tree *);
struct tree *del(struct tree *,int);

int main(void)
{
struct tree *root;
int ch,item,item_no;
root=NULL;
do
   {
      do
      {
      cout<<"\n\n\t\t\tMENU";
      cout<<"\n\t######################################";
      cout<<"\n\n\t1. Binary Search Tree Insertion  ";
      cout<<"\n\t2. Binary Search Tree Deletion ";
      cout<<"\n\t3. Inorder Traversal of Binary Search Tree";
      cout<<"\n\t4. Postorder Traversal of Binary Search Tree";
      cout<<"\n\t5. Preorder Traversal of Binary Search Tree";
      cout<<"\n\t6. Find Root ";
      cout<<"\n\t7. Exit\n\n";
      cout<<"\nEnter the Choice : ";
      cin>>ch;
      if(ch<1 || ch>7)
	  {
	    cout<<"\nInvalid choice: Try again!!!";
	  }
      }while (ch<1 || ch>7);
      switch(ch)
      {
       case 1:
       cout<<"\nEnter the New Element: ";
       cin>>item;
       root=insert(root,item);
       break;
       case 2:
       if(root!=NULL)
       {
       cout<<"\nEnter the Element to be Deleted: ";
       cin>>item_no;
       root=del(root,item_no);
       cout<<"The Binary Search Tree is now:\n";
       inorder(root);
	}
       else
	{
       cout<<"\nBinary Search Tree is Empty!!!\n";
	 }
       break;
       case 3:
       if(root!=NULL)
       {
       cout<<"\nInorder Traversal of Binary Search Tree is: ";
       inorder(root);
	}
       else
       {
       cout<<"\nBinary Search Tree is Empty!!!\n";
	}
       break;
       case 4:
       if(root!=NULL)
       {
       cout<<"\nPostorder Traversal of Binary Search Tree is: ";
       postorder(root);
	}
       else
       {
       cout<<"\nBinary Search Tree is Empty!!!\n";
	}
       break;
       case 5:
       if(root!=NULL)
       {
       cout<<"\nPreorder Traversal of Binary Search Tree is: ";
       preorder(root);
	}
       else
       {
       cout<<"\nBinary Search Tree is Empty!!!\n";
	}
       break;
       case 6:
       findroot(root);
       break;
       default:
       cout<<"\nProgram Terminating\n\n";
     }
   }while(ch !=7);
   return(0);
}

struct tree *insert(struct tree *root, int x)
{
   if(!root)
   {
      root=(struct tree*)malloc(sizeof(struct tree));
      root->info=x;
      root->left=NULL;
      root->right=NULL;
      return(root);
   }
   if(root->info>x)
   {
      root->left=insert(root->left,x);
   }
   else
   {
      if(root->info<x)
      {
	 root->right=insert(root->right,x);
      }
   }
   return(root);
}

void inorder(struct tree *root)
{
   if(root!=NULL)
   {
      inorder(root->left);
      cout<<" "<<root->info;
      inorder(root->right);
   }
   return;
}

void postorder(struct tree *root)
{
   if(root!=NULL)
   {
      postorder(root->left);
      postorder(root->right);
      cout<<" "<<root->info;
   }
   return;
}

void preorder(struct tree *root)
{
   if(root!=NULL)
   {
      cout<<" "<<root->info;
      preorder(root->left);
      preorder(root->right);
   }
   return;
}

void findroot(struct tree *root)
{
    if(root!=NULL)
    {
	cout<<"\nRoot is "<<root->info<<"\n";
    }
    else
    {
	cout<<"\nBinary Search Tree is Empty!!!\n";
    }
}

struct tree *del(struct tree *ptr,int x)
{
  struct tree *p1,*p2;
  if(!ptr)
  {
     cout<<"\nElement not Found!!!\n";
     return(ptr);
  }
  else
  {
     if(ptr->info<x)
     {
	 ptr->right=del(ptr->right,x);
     }
     else if(ptr->info>x)
     {
	 ptr->left=del(ptr->left,x);
	 return ptr;
     }
     else
     {
	 if(ptr->info==x)
	 {
	    if(ptr->left==ptr->right)
	    {
	       free(ptr);
	       return(NULL);
	    }
	    else if(ptr->left==NULL)
	    {
	       p1=ptr->right;
	       free(ptr);
	       return p1;
	    }
	    else if(ptr->right==NULL)
	    {
	       p1=ptr->left;
	       free(ptr);
	       return p1;
	    }
	    else
	    {
	       p1=ptr->right;
	       p2=ptr->right;
	       while(p1->left != NULL)
	       {
		   p1=p1->left;
	       }
	       p1->left=ptr->left;
	       free(ptr);
	       return p2;
	    }
	 }
     }
  }
  return(ptr);
}
