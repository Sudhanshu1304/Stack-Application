#include <iostream>
#include<string>
using namespace std;



class Stack{


private:


    char A[5];
    int Size;

public:
    int top;
    Stack(){

        top=-1;
        Size=sizeof(A)/sizeof(char);

    }



    bool IsFull(){

        if(top==Size-1){
            return true;
        }
        else{
            return false;
        }
    }

    bool IsEmpty(){

        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

    char peek(){

        return A[top];
    }

    void Push(char val){

        if (IsFull()==false){
            top++;
            A[top]=val;
        }
        else{
            cout<<"\nThe Stack is Full"<<endl;
        }
    }

    char Pop(){

        if(IsEmpty()==false){
            char temp=A[top];
            A[top]='0';
            top--;
            return temp;
        }
        else{
            return '-1';
        }

    }

    void Show_Stack(){


        for(int i=0;i<top+1;i++){
            cout<<A[i];
        }


    }

};


int Search(char A){


    string CHAR[]={"([","{)","]}","+-","*/","^$"};
    int Size=(sizeof(CHAR)/sizeof(string));

    for(int i=0;i<Size;i++){

        if(A==CHAR[i][0]){
                if(i+i>=6){
                    return i+i;
                }
                else{
                    return i+i+0;
                }

        }
        else if(CHAR[i][1]==A){
             if(i+i>=6){
                    return i+i;
                }
                else{
                    return i+i+1;
                }
        }
    }
    return -1;

}




void Display(char ch,string vari, Stack &s){

    int Size=s.top+1;


    cout<<"\n   "<<ch<<"           ";
    s.Show_Stack();
    for(int i=0;i<10-Size;i++){
        cout<<" ";
    }
    cout<<vari<<endl;

}


int main(){

    Stack STACK;
    char temp;
    string exp;//"A+B*C";
    cout<<"Enter Your Expression :";
    cin>>exp;

    string out="";
    cout<<"\n\nExpression   Stack   Postfix\n"<<endl;
    for(int i=0;i<exp.size();i++){

        temp=exp[i];

        int ab=Search(temp);

        if (ab!=-1){

            /* If We ENCOUNTER CLOSING BRACKETS*/
            if(ab<=5 && ab>=3){



                while(Search(STACK.peek())>2){
                    char val=STACK.Pop();
                        out=out+val;

                    //1 Display(temp,out,STACK);
                }
                //Display(temp,out,STACK);
                STACK.Pop();
                Display(temp,out,STACK);
                }
            /* Search Precedence*/
            else{
                if (Search(temp)>=0 && Search(temp)<=2){
                    STACK.Push(temp);
                    Display(temp,out,STACK);
                }

                /* If TOP < Temp */

                else if(Search(STACK.peek())<ab){

                        STACK.Push(temp);
                        Display(temp,out,STACK);
                }
                else{
                    /* if STACK= +,* and temp= + then we have to remove two times */


                    while(Search(STACK.peek())>=ab){

                        char val=STACK.Pop();
                            out=out+val;
                        //2 Display(temp,out,STACK);
                    }
                    //Display(temp,out,STACK);
                    STACK.Push(temp);
                    Display(temp,out,STACK);
                }
            }
        }
        /* If an Alphabet */
        else{

            out=out+temp;
            Display(temp,out,STACK);

            }


    }
    while(STACK.IsEmpty()==false){

        char val=STACK.Pop();

            out=out+val;
        //3 Display(temp,out,STACK);

    }
    Display(temp,out,STACK);
    cout<<"\n\nFINAL STRING : "<<out<<endl;


}
