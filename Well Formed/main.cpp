#include <iostream>
using namespace std;

class Stack
{

private:
    int top;
    string A[20];
    int Size;

public:
    Stack()
    {

        top = -1;
        Size = sizeof(A) / sizeof(int);
    }

    bool IsFull()
    {

        if (top == Size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool IsEmpty()
    {

        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string peek()
    {

        return A[top];
    }

    void Push(int val)
    {

        if (IsFull() == false)
        {
            top++;
            A[top] = val;
        }
        else
        {
            cout << "\nThe Stack is Full" << endl;
        }
    }

    string Pop()
    {

        if (IsEmpty() == false)
        {
            string temp = A[top];
            A[top] = "0";
            top--;
            return temp;
        }
        else
        {
            return "-1";
        }
    }

    void Show_Stack()
    {

        for (int i = 0; i < top + 1; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

int Search(string a)
{

    int flag = 0;
    string A[] = {"(", "{", "[", "]", "}", ")"};
    for (int i = 0; i < 6; i++)
    {
        if (a == A[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    Stack Arr;
    int flag = 1, val;
    string cc, VV;
    string Str;
    string A[] = {"(", "{", "[", "]", "}", ")"};

    do
    {
        cout << "\nEnter Your String : ";
        cin >> Str;

        int i,Count=0;
        int s = Str.size();
        for (i = 0; i < s; i++)
        {

            cc = Str[i];
            val = Search(cc); /* It checks if it is Brackets or not */
            if (val != -1)
            {

                /* If we get a Opening Brackets */

                if (val <= 2)
                {
                    Count++;
                    Arr.Push(Str[i]);
                    Arr.Show_Stack();
                }

                /* If we get a Closing Brackets */

                else
                {
                    Count--;
                    VV = Arr.Pop();
                    //cout<<VV<<" "<<A[5-val]<<endl;
                    Arr.Show_Stack();

                    /* Comparing the Closing and Opening Bracket  */

                    if (VV != A[5 - val])
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        flag = 0;
                    }
                }
            }
        }


        if(Count!=0){
            flag=1;
        }
        if (flag == 1)
        {
            cout << "\nNOT WELL" << endl;
        }
        else
        {
            cout << "\nWell" << endl;
        }

    } while (true);
}
