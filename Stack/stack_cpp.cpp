include<iostream>
using namespace std;

int PUSH_Array(int a[],int top)
{
    int item;
    cout << "Please enter the element you want to Push : " << endl;
    cin >> item;
    a[top] = item;
}

int POP_Array(int a[],int top)
{
    int item;
    item = a[top] ;
    return item;
}

void PEEK_Array(int a[],int top)
{
    cout << "Here is your stack data : " << endl;
    for(int i = top; i>=0; i--)
    {
        cout << a[i] << endl;
    }
}

int main()
{
    int sizeofs;   
    cout << "Please enter the size of stack : "<< endl;
    cin >> sizeofs;
    int s[sizeofs],work,ans, item; 
    int top = -1;
    do
    {
        cout << "Please enter what work you want to do : press \n1 fo Push \n2 for Pop \n3 for peek. "<< endl;
        cin >> work;
        switch(work)
        {
            case 1:
                if(top==sizeofs-1)
                {
                    cout << "Sorry the element cannot be inserted, the Stack is Full !!!" << endl;
                }
                else
                {
                    top++;
                    PUSH_Array(s,top);
                }
                PEEK_Array(s,top);
                break;
            
            case 2:
                if(top==-1)
                {
                    cout << "Sorry element cannot be Deleted, the Stack is Empty !!!" << endl;
                }
                else
                {
                    item = POP_Array(s,top);
                    top--;
                }
                PEEK_Array(s,top);
                break;

            case 3:
                PEEK_Array(s,top);
                break;

            default:
                cout << "Please Enter the right work value !!!" << endl;
        }
        cout << "Do you want to continue : press 1/0" << endl;
        cin >> ans;
    }
    while(ans==1);

    


}
