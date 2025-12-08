#include<iostream>
#include<string>
using namespace std;

void Traversing(int a[],int n)
{
    cout << "Here is the numbers you entered in array : "<< endl;
    for(int i = 0; i<n; i++)
    {
        cout << a[i] << endl;
    }

}

void Insertion(int a[], int n, int item, int k)
{
    for(int i = n; i>=k; i-- )
    {
        a[i+1] = a[i];
    }
    a[k] = item;
}

int Deletion(int a[], int n, int item, int k)
{
    item = a[k];
    for(int i = k; i<n; i++)
    {
        a[i] = a[i+1];
    }
    cout << "Here is your Deleted Item : "<< item << endl;
}

main()
{
    int a[10];
    int counter, work, item, pos, ans;
    cout << "Please enter the no of elements you want to include in array :"<<endl;
    cin >> counter;
    cout << "Please Enter the elements of Array first : "<< endl;
    for(int i = 0; i<counter; i++)
    {
        cin >> a[i];
    }
    do
    {
        cout << "Please enter the what work you want to do : Press \n 1 for Traversing. \n 2 for Inserting. \n 3 for Deleting."<<endl;
        cin >> work;
        switch(work)
        {
            case 1 : 
                Traversing(a,counter);
                break;
            case 2 :
                cout << "Please enter the item you want Insert : " << endl;
                cin >> item;
                cout << "Please enter the Position where you want to Insert the data : " << endl;
                cin >> pos;
                Insertion(a,counter,item,pos);
                counter++;
                break;
            case 3 :
                cout << "Please enter the Position from where you want to Delete the data : " << endl;
                cin >> pos;
                Deletion(a,counter,item,pos);
                counter--;
                break;
            default :
                cout << "out";
                break;
        }
        cout << "Do you want to continue : Press 1 for Yes and 0 for No." << endl;
        cin >> ans;
    }
    while (ans == 1);
}