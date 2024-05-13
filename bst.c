struct node{
    int data;
    struct node*left,*right;
};
struct node*createnode(int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void inser(struct node*root,int data){
   if(root==NULL){
    return createnode(data);
   }
   else if(data<root->data){
    return insert(root->left,data);
   }
   else if(data>root->data){
    return insert(root->right,data);
   }
}
void inorder(struct node*root){
    if(root!=NULL){
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
}
void postorder(struct node*root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}
struct node*deletenode(struct node*root,int data)
{
    if(root==NULL)
        return root;
    if(data<root->data){
        root->left=deletenode(root->left,data);
    }
    else if(data>root->data){
        root->right=deletenode(root->right,data);
    }
    else{
        if(root->left==NULL){
            struct node*temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
        struct node*temp=root->left; 
        free(root);
        return temp;
        }
    struct node*temp=find_min(root->right);
    root->data=temp->data;
    root->right=deletenode(root->right,temp->data);
}
return root;
}