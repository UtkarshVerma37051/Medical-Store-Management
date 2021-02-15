#include<iostream>
#include<conio.h>
using namespace std;

class Menu
{
public :
    char main_menu();
    char Admin_Menu();
    char Admin_Supplier();
    char Admin_Inventory();
    void Admin_Customer();
    void Admin_Employee();
    void Employee_Menu();
};
Menu menu;
char Menu:: main_menu()
{
    char ch;
    system("cls");
    while(1)
    {
        system("color F");
        cout << "Medical Store Management system\n" << endl;
        cout << "1. Admin             : " << endl;
        cout << "2. Employee          : " << endl;
        cout << "3. Exit              : " << endl;
        cout << "   Enter your choice : ";
        ch=getche();
        if(ch=='3')
            return '3';
        switch(ch)
        {
        case '1'  :
        case '2'  :
            return ch;
        break;
        default   :
            system("cls");
            cout << "Invalid Input!" << endl;
        }
    }
}

char Menu :: Admin_Menu()
{
    char ch;
    system("cls");
    while(1)
    {
        cout << "1. Supplier          : " << endl;
        cout << "2. Employee          : " << endl;
        cout << "3. Customer          : " << endl;
        cout << "4. Inventory         : " << endl;
        cout << "0. Exit              : " << endl;
        cout << "   Enter your choice : ";
        ch=getche();
        if(ch=='0')
            return '0';
        switch(ch)
        {
        case '1'  :
        case '2'  :
        case '3'  :
        case '4'  :
            return ch;
        break;
        default   :
            system("cls");
            cout << "Invalid Input!" << endl;
        }
    }
}



char Menu :: Admin_Supplier()
{
    char ch;
    system("cls");
    while(1)
    {
        cout << "1. Add Supplier       : " << endl;
        cout << "2. View Supplier      : " << endl;
        cout << "3. Modify Supplier    : " << endl;
        cout << "4. List All Suppliers : " << endl;
        cout << "0. Exit               : " << endl;
        cout << "   Enter your choice  : ";
        ch=getch();
        if(ch=='0')
            return ch;
        switch(ch)
        {
        case '1'  :
        case '2'  :
        case '3'  :
        case '4'  :
            return ch;
        break;
        default   :
            system("cls");
            cout << "Invalid Input!" << endl;
        }
    }
}


char Menu :: Admin_Inventory()
{
    char ch;
    system("cls");
    while(1)
    {
        cout << "1. Add Medicine       : " << endl;
        cout << "2. Delete Medicine    : " << endl;
        cout << "3. Modify Medicine    : " << endl;
        cout << "4. Search Medicine    : " << endl;
        cout << "5. List All Medicines : " << endl;
        cout << "0. Exit               : " << endl;
        cout << "   Enter your choice  : ";
        ch=getche();
        if(ch=='0')
            return ch;
        switch(ch)
        {
        case '1' :
        case '2' :
        case '3' :
        case '4' :
        case '5' :
        case '6' :
        case '7' :
            return ch;
        default   :
            system("cls");
            cout << "Invalid Input!" << endl;
        }
    }
}
