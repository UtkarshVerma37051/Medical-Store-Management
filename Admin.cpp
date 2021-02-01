#include<iostream>
//#include"New_Inventory.cpp"
#include<fstream>
using namespace std;
class Admin //: public Inventory
{
    friend class Inventory;
//    friend class Inventory_Struct;
    friend class Customer_Purchase_Record;
    friend class Customer_Record;
    string password;
public :
    void ADMIN(Inventory&,Customer_Record&);
    void Customer_Start(Customer_Record&);
};
void Admin :: ADMIN(Inventory& st,Customer_Record& CR)
{
    char ch;
    system("cls");
    while(1)
    {
        cout << "1. Supplier          : " << endl;
        cout << "2. Employee          : " << endl;
        cout << "3. Customer          : " << endl;
        cout << "4. Inventory         : " << endl;
        cout << "5. Reset Password    : " << endl;
        cout << "0. Exit              : " << endl;
        cout << "   Enter your choice : ";
        ch=getche();
        if(ch=='0')
            break;
        switch(ch)
        {
        case '1' :

            system("cls");
        break;

        case '2' :

            system("cls");
        break;

        case '3' :
            system("cls");
            Customer_Start(CR);

        break;

        case '4' :
            st.Start();
            system("cls");
            st.write_to_file();
        break;

        case '5' :
            resetpassword();
        break;

        default :
            system("cls");
            cout << "Invalid Choice!" << endl;
        }
    }
}

void Admin ::Customer_Start(Customer_Record& CR)
{
    system("cls");
    char ch;

    long long int ph=0;
    string num;
    while(1)
    {
        cout << "1. View Specific Customer Record :" << endl;
        cout << "2. View All Customer Records     :" << endl;
        cout << "3. View Purchase History         :" << endl;
        cout << "4. Exit                          :" << endl;
        cout << "   Enter your choice             :";
        ch=getch();
        if(ch=='4')
            return;
        switch(ch)
        {
        case '1' :
            system("cls");

            cout << "Enter Mobile Number (0 to exit) : ";
            while(1)
            {
                getline(cin,num);
                if(num=="0")
                    break;
                ph=check_phone_number(num);
                if(ph == 0)
                {
                    cout << "Invalid Number!" << endl;
                    cout << "Please enter a 10 digit number (0 to exit): ";
                    continue;
                }
                else
                {
                    int srch=-1;
                    srch=CR.search_in_record(ph);
                    if(srch!= -1)
                    {
                        CR.display_specific_record(srch);
                    }
                    else
                    {
                        cout << "No Customer Found." << endl;
                    }
                    cout << "\nPress any key to exit : ";
                    getch();
                    break;
                }
            }
        break;

        case '2' :
            system("cls");
            CR.view_all_customer();
            cout << "\nPress any key to Exit : ";
            getch();
        break;

        case '3' :
            system("cls");
            cout << "Enter Mobile Number (0 to exit) : ";
            while(1)
            {
                getline(cin,num);
                if(num=="0")
                    break;
                ph=check_phone_number(num);
                if(ph == 0)
                {
                    cout << "Invalid Number!" << endl;
                    cout << "Please enter a 10 digit number (0 to exit): ";
                    continue;
                }
                else
                {
                    Customer_Purchase_Record CPR;
                    if(CPR.read_from_file(ph))
                    {
                        CPR.view_data();
                    }
                    else
                    {
                        cout << "No Customer Found." << endl;
                    }
                    cout << "\nPress any key to exit : ";
                    getch();
                    break;
                }
            }
        break;
        }
        system("cls");
    }
}
