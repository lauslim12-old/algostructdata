#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int data , blc;
    struct node *left;
    struct node *right;
};

void header()
{
    printf("Balancing Binary Tree by Nicholas Dwiarto\n");
    printf("1. Insert data\n");
    printf("2. View pre-order\n");
    printf("3. View in-order\n");
    printf("4. View post order\n");
    printf("5. Search\n");
    printf("6. Exit\n");
}

int insert(struct node **root, struct node **curr,int data)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->blc=0;
    //struct node *tmp;

    if((*root)==NULL)
    {
        (*root)=(*curr)=new_node;
        (*root)->left=NULL;
        (*root)->right=NULL;
        //tmp=new_node;
        //free(tmp);
        return 0;
    }
    else
    {
        if((*curr)->left==NULL&&(*curr)->blc==0)
        {
            printf("kr");
            //getch();
            (*curr)->blc=(*curr)->blc-1;
            (*curr)->left=new_node;
            //(*curr)=new_node;
           // tmp=new_node;
            //getch();
            //free(tmp);
            return 0;
        }
        else if ((*curr)->right==NULL&&(*curr)->blc==-1)
        {
            //getch();
            printf("kn");
            //getch();
            (*curr)->blc=(*curr)->blc+1;
            (*curr)->right=new_node;
            //(*curr)=new_node;
            //tmp=new_node;
            //free(tmp);
            return 0;
        }
        else if ( (*curr)->blc==0&&(*curr)->left->blc==0)
        {
            //getch();
            (*curr)->blc=(*curr)->blc-1;
            (*curr)=(*curr)->left;
            //tmp=new_node;
            //free(tmp);
            return insert(root,curr,data);
        }
        else if ( (*curr)->blc<0 && (*curr)->left->blc<0)
        {
            (*curr)->blc=(*curr)->blc-1;
            (*curr)=(*curr)->left;
            //tmp=new_node;
            //free(tmp);
            return insert(root,curr,data);
        }
        else if ((*curr)->blc<0 && (*curr)->left->blc==0)
        {
            (*curr)->blc=(*curr)->blc+1;
            (*curr)=(*curr)->right;
            return insert(root,curr,data);
        }
    }
}

void preorder(struct node *pnode)
{
    if(pnode==NULL) return;
    printf("%d ",pnode->data);
    preorder(pnode->left);
    preorder(pnode->right);
}

void inorder(struct node *pnode)
{
    if(pnode==NULL) return;
    inorder(pnode->left);
    printf("%d ",pnode->data);
    inorder(pnode->right);
}

void postorder(struct node *pnode)
{
    if(pnode==NULL) return;
    postorder(pnode->left);
    postorder(pnode->right);
    printf("%d ",pnode->data);
}

void src(struct node *pnode,int *key,int *found)
{
    if(pnode==NULL) return;
    src(pnode->left,key,found);
    if (pnode->data==*key)
     {
        *found=1;
        return ;
     }
    src(pnode->right,key,found);
}

int main ()
{
    int pil,data,key,found;
    struct node *root,*curr,*ptr;
    root=curr=NULL;
    while(1)
    {
        found=0;
        header();
        printf("Pilihan : ");
        scanf("%d",&pil);
        if(pil==1)
        {
            printf("Masukkan data : ");scanf("%d",&data);
            curr=root;
            insert(&root,&curr,data);
        }
        else if (pil == 2)
        {
            scanf("%d",&data);
            preorder(root);
            getch();
        }
        else if (pil == 3)
        {
            inorder(root);
            getch();
        }
        else if (pil == 4)
        {
            postorder(root);
            getch();
        }
        else if ( pil == 5)
        {
            printf("Enter Search Key : ");
            scanf("%d",&key);
            src(root,&key,&found);
            if (found==1)
            {
                printf("Data found !");
            }
            else
            {
                printf("Invalid data");
            }
            getch();
        }
        else if(pil == 6){
            exit(0);
        }
        system("cls");
    }
    return 0;
}

