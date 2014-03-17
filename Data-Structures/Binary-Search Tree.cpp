#ifndef MAIN;
#define MAIN;
#define BST_MAIN;
#endif // MAIN
#include<iostream>
#include<cstdlib>

using namespace std;

template<class T>
class TreeNode
{
public:
    TreeNode<T> *parent;
    TreeNode<T> *right;
    TreeNode<T> *left;
    T *data;
    TreeNode()
    {
        parent=NULL;
        right=NULL;
        left=NULL;
        data=NULL;
    }
    ~TreeNode()
    {
        delete parent;
        delete right;
        delete left;
        delete data;
    }
};

template<class T>
class BST
{
    TreeNode<T> *root;
public:
    BST()//constructor
    {
        root = NULL;
    }


    bool isEmpty()
    {
        return(root==NULL);
    }

    int number_of_nodes()
    {
        return _number_of_nodes(root);
    }
    int _number_of_nodes(TreeNode<T> *node)
    {
        if(node==NULL)
            return 0;
        int count=1;
        count+=_number_of_nodes(node->left);
        count+=_number_of_nodes(node->right);
        return count;
    }

    T* Insert(T *datap)
    {
        TreeNode<T> *newNode = new TreeNode<T>;
        newNode->data = datap;
        TreeNode<T> *y;
        TreeNode<T> *x;
        y=NULL;
        x = root;

        while(x!=NULL)
        {
            y=x;
            if(*(newNode->data)<*(x->data)){
                x=x->left;
            }
            else if(*(newNode->data)>*(x->data)){
                x=x->right;
            }
            else if(*(newNode->data)==*(x->data))
                return x->data;
        }

        newNode->parent=y;
        if(y==NULL)
            root = newNode;
        else if(*(newNode->data)<*(y->data))
        {
            y->left=newNode;
            newNode->parent=y;
        }
        else{
            y->right=newNode;
            newNode->parent=y;
        }
        return newNode->data;
    }


    T* Search(T *datap)
    {
        if(_Search(datap)!=NULL)
            return _Search(datap)->data;
        else
            return NULL;
    }
    TreeNode<T>* _Search(T *datap)
    {
        TreeNode<T> *x=root;
        while(x!=NULL)
        {
            if(*datap==*(x->data))
                return x;
            else if(*datap>*(x->data))
                x=x->right;
            else
                x=x->left;
        }
            return NULL;
    }



    T* Min()
    {
        return _Min(root)->data;
    }
    TreeNode<T> *_Min(TreeNode<T> *node)
    {
        TreeNode<T> *x;
        x=node;
        while(x->left!=NULL)
        {
            x=x->left;
        }
        return x;
    }


    T* Max()
    {
        return _Max(root)->data;
    }
    TreeNode<T> *_Max(TreeNode<T> *node)
    {
        TreeNode<T> *x;
        x=node;
        while(x->right!=NULL)
        {
            x=x->right;
        }
        return x;
    }


    int height()//height of the tree
    {
        return _height(root);
    }
    int _height(TreeNode<T> *node)//heaight of subtree rooted at node "node";
    {
        if(node==NULL)
            return -1;
        else
        {
            if(_height(node->right)>=_height(node->left))
                return (1+_height(node->right));
            else
                return (1+_height(node->left));
        }
    }


    void transplant(TreeNode<T> *u,TreeNode<T> *v)
    {
        if(u->parent==NULL)
            root = v;
        else if(u==u->parent->left)
            u->parent->left=v;
        else if(u==u->parent->right)
            u->parent->right=v;

        if(v!=NULL)
            v->parent=u->parent;
    }
    void Delete(T *datap)
    {
        TreeNode<T> *x=_Search(datap);
        if(x==NULL)
        {
            cout<<"Does not exist\n";
            return;
        }

        if(x->left==NULL)
            transplant(x,x->right);
        else if(x->right==NULL)
            transplant(x,x->left);
        else
        {
            TreeNode<T> *y=_Min(x->right);
            //cout<<*y->data;
            if(y->parent!=x){
            transplant(y,y->right);
            //if(y->parent!=x)
            y->right=x->right;
            y->right->parent=y;
            }
            transplant(x,y);
            y->left=x->left;
            y->left->parent=y;
            //delete x;
        }

    }


    T* InorderSucc(T *datap)
    {
        TreeNode<T> *x=_Search(datap);
        //cout<<*x->data<<" ";
        if(x==root &&x->right==NULL||(x==NULL))
            return NULL;

        if(_InorderSucc(x)!=NULL)
            return _InorderSucc(x)->data;
        else
            return NULL;
    }
    TreeNode<T>* _InorderSucc(TreeNode<T> *x)
    {
        if(x->right!=NULL)
        {
            //cout<<*x->data;
            TreeNode<T> *z=_Min(x->right);
            return z;
        }
        else
        {
            TreeNode<T> *p=x->parent;
            while(p!=NULL &&x==p->right)
            {
                x=p;
                p=p->parent;
            }
            if(p==NULL)
                return NULL;
            else
                return p;
            }
    }


    T* InorderPred(T *datap)
    {
        TreeNode<T> *x=_Search(datap);
        //cout<<*x->data<<" ";
        if(x==root &&x->left==NULL||(x==NULL))
            return NULL;
        if(_InorderPred(x)!=NULL)
            return _InorderPred(x)->data;
        else
            return NULL;
    }
    TreeNode<T>* _InorderPred(TreeNode<T> *x)
    {
        if(x->left!=NULL)
        {
            //cout<<*x->data;
            TreeNode<T> *z=_Max(x->left);
            return z;
        }
        else
        {
            TreeNode<T> *p=x->parent;
            while(p!=NULL &&x==p->left)
            {
                x=p;
                p=p->parent;
            }
            if(p==NULL)
                return NULL;
            else
                return p;
            }
    }


    void PrintInorder()
    {
        Inorder(root);
    }
    void Inorder(TreeNode<T> *node)
    {
        if(node!=NULL)
        {
            Inorder(node->left);
            cout<<*node->data<<" ";
            Inorder(node->right);
        }
    }


    void PrintPreorder()
    {
        Preorder(root);
    }
    void Preorder(TreeNode<T> *node)
    {
        if(node!=NULL)
        {
            cout<<*node->data<<" ";
            Preorder(node->left);
            Preorder(node->right);
        }
    }


    void PrintPostorder()
    {
        Postorder(root);
    }
    void Postorder(TreeNode<T> *node)
    {
        if(node!=NULL)
        {
            Postorder(node->left);
            Postorder(node->right);
            cout<<*node->data<<" ";
        }
    }


};
#ifdef BST_MAIN;
int main()
{
    BST<int> a;

    int count=0;
    while(true)
    {
        cout<<"***************MENU***************\n";
        cout<<"1.Insert"<<endl
            <<"2.Delete"<<endl
            <<"3.Search"<<endl
            <<"4.Min"<<endl
            <<"5.Max"<<endl
            <<"6.InorderSuccessor"<<endl
            <<"7.InorderPredecessor"<<endl
            <<"8.PrintInorder"<<endl
            <<"9.PrintPreorder"<<endl
            <<"10.PrintPostorder"<<endl
            <<"11.Height"<<endl
            <<"12.Exit"<<endl;
        cout<<"Enter the menu option: ";
        cin>>count;

        switch(count)
        {
        case 1:
            {
                int *num1=new int;
                cout<<"Enter the number to be inserted: ";
                cin>>*num1;
                cout<<*a.Insert(num1)<<endl;
                break;
            }

        case 2:
            {
                int *num2 = new int;
                if(a.isEmpty())
                    cout<<"tree is empty.Nothing to be deleted\n";
                else
                {
                    cout<<"Enter the number to be deleted: ";
                    cin>>*num2;
                    a.Delete(num2);
                }
                break;
            }

        case 3:
            {
                if(a.isEmpty())
                    cout<<"tree is empty.Nothing to be searched\n";
                else
                {
                    int *num3=new int;
                    cout<<"Enter the number to be searched: ";
                    cin>>*num3;
                    int *search = a.Search(num3);
                    if(search==NULL)
                        cout<<"Not Found\n";
                    else
                        cout<<*search<<endl;
                }
                break;
            }

        case 4:
            {
                if(a.isEmpty())
                    cout<<"tree is empty.\n";
                else
                    cout<<*a.Min()<<endl;
                break;
            }

        case 5:
            {
                if(a.isEmpty())
                    cout<<"tree is empty.\n";
                else
                    cout<<*a.Max()<<endl;
                break;
            }

        case 6:
            {
                if(a.isEmpty())
                    cout<<"tree is empty.\n";
                else{
                    int *num4=new int;
                    cout<<"Enter the number whose successor is to be found: ";
                    cin>>*num4;
                    int *succ=a.InorderSucc(num4);
                    if(succ==NULL)
                        cout<<"Does not exist\n";
                    else
                        cout<<*succ<<endl;
                    }
                break;
            }

        case 7:
            {
                if(a.isEmpty())
                    cout<<"tree is empty.\n";
                else{
                    int *num5=new int;
                    cout<<"Enter the number whose predecessor is to be found: ";
                    cin>>*num5;
                    int *pred=a.InorderPred(num5);
                    if(pred==NULL)
                        cout<<"Does not exist\n";
                    else
                        cout<<*pred<<endl;
                }
                break;
            }

        case 8:
            {
                if(a.isEmpty())
                    cout<<"tree is empty.\n";
                else{
                    a.PrintInorder();
                    cout<<endl;
                }
                break;
            }

        case 9:
            {
                if(a.isEmpty())
                    cout<<"tree is empty.\n";
                else{
                a.PrintPreorder();
                cout<<endl;
                }
                break;
            }

        case 10:
            {
                if(a.isEmpty())
                    cout<<"tree is empty.\n";
                else{
                a.PrintPostorder();
                cout<<endl;
                }
                break;
            }

        case 11:
            {
                if(a.isEmpty())
                    cout<<"tree is empty\n";
                else
                    cout<<a.height()<<endl;
                break;
            }

        case 12:
            {
                exit(0);
                break;
            }

        default:
                cout<<"Invalid Input\n";
                break;

        }
    }
}
#endif;
