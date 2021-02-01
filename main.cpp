#include <iostream>
#include"Validate_Input.cpp"
#include"Menu.cpp"
#include"Password.cpp"
#include"New_Inventory.cpp"
#include"Customer.cpp"
#include"Purchased_Data.cpp"
#include"Admin.cpp"

using namespace std;

int main()
{
    char choice;
    Admin ad;
    Customer_Section cstmr;
    Inventory stock;
    stock.read_from_file();
    Customer_Record cstmr_rec;
    cstmr_rec.read_from_record();
    Customer_Purchase_Record cpr;
    while(1)
    {
        system("color F");
        cout << "Medical Store Management system\n" << endl;
        cout << "1. Admin             : " << endl;
        cout << "2. Customer          : " << endl;
        cout << "3. Exit              : " << endl;
        cout << "   Enter your choice : ";
        choice=getche();
        if(choice=='3')
            break;
        switch(choice)
        {
            case '1' :
                LOGIN();
                ad.ADMIN(stock,cstmr_rec);
                system("cls");
            break;

            case '2' :
                cstmr.START(stock,cstmr_rec);
            break;

            default :
                system("cls");
                cout << "\nInvalid Input!" << endl;
        }
    }
}
