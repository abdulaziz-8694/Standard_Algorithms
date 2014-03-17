/****Stack using array, with constant amortized time cpmlexity for push operations****/
class Stack{

private:
    int *A,pos,size;
    friend class Queue;
public:
    Stack()
    {
        pos=-1;
        size=1;
        A=new int[size];
    }

    ~Stack()
    {
        delete[] A;
    }

    void Push(int k)
    {
        if(pos==size-1)
        {

            int cpy[size];

            for(int i=0;i<size;i++)
                temp[i]=A[i];

            A=new int[2*size];

            for(int i=0;i<size;i++)
                A[i]=cpy[i];

            head=size;
            size*=2;
            A[pos]=k;
        }
        else
            A[++pos];

    }

    int Pop()
    {
        if(pos!=-1)
            return A[pos--];

        else
        {
            cout<<"Stack empty!!"<<endl;
        }
    }

    int Top()
    {

        if(pos!=-1)
            return A[pos];

        else
            cout<<"Stack empty!!"<<endl;
    }

    bool IsEmpty()
    {
        return (pos==-1)
    }

};
/*************************************************************/

/*****************Queue using two Stacks****************/

class Queue()
{
private:
    Stack one,two;

public:
    void Enqueue(int k)
    {
        one.Push(k);
    }

    int Dequeue()
    {

        if(!two.IsEmpty())
        {
            return two.Pop();
        }

        else
        {
            while(one.pos!=-1)
                two.Push(one.Pop());

            return two.Pop();
        }
    }

    int Front()
    {
        if(!two.IsEmpty())
        {
            return two.Top();
        }

        else
        {
            while(one.pos!=-1)
                two.Push(one.Pop());

            return two.Top();
        }
    }

    bool IsEmpty()
    {
        return (one.IsEmpty&&two.IsEmpty());
    }
};

/************************************************

/********************Stack Using Linked List****************************/

class Data{
    public:
        Data *prev;
        int value;
        Data *next;
};

class StackList
{
    private:
        Data *top;
    public:
        StackList()
        {
            top==NULL;
        }

        ~StackList()
        {
            delete top;
        }
        void Push(int k)
        {
            Data *insert=new Data;
            insert->next=NULL;
            insert->value=k;
            if(top==NULL)
            {
                insert->prev=NULL;
            }
            else
            {
                insert->prev=top;
                top->next=insert;
            }
            top=insert;
        }

        int Pop()
        {
            if(top!=NULL)
            {
                int temp=top->value;
                top=top->prev;
                return temp;
            }
            cout<<"Stack Empty"<<endl;
            return 0;
        }

        int Top()
        {

            if(top!=NULL)
            {
                return top->value;
            }
            cout<<"Stack Empty"<<endl;
            return 0;
        }

        bool IsEmpty()
        {
            return (top==NULL)
        }

};
/****************************************************/
