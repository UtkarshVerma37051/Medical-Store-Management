#include <iostream>
#include<conio.h>
#include<iomanip>
#include"Validate_Input.h"
#include"Password.h"
#include"Password.h"
#include"New_Inventory.h"
#include"Customer.h"
#include"Purchased_Data.h"
#include"Admin.h"
#include"Supplier.h"
using namespace std;
int main()
{
    Supplier_List lst;
//    supplier s1={9811272448,"Utkarsh","uv","@gmail.com"};
//    lst.add_supplier(s1);
//    supplier s2={9811272448,"Divyansh","div","@gmail.com"};
//    lst.add_supplier(s2);
//    supplier s3={9811272448,"Raveesh","rav","@gmail.com"};
//    lst.add_supplier(s3);
//    lst.display_suppliers_list();
//    lst.write_to_file();
    lst.get_supplier_list();
//    lst.display_suppliers_list();
//    lst.read_from_supplier_history();
//    struct Inventory_Struct st1={"pa","12",10,20,30};
//    struct Inventory_Struct st2={"ed","23",40,50,60};
//    lst.write_to_supplier_file(st1,"uv");
//    lst.write_to_supplier_file(st2,"uv");

//    if(lst.search_supplier("uv") == -1)
//    {
//        cout << "Not found.";
//    }
//    else
//    {
//        cout << "found";
//    }
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
                ad.ADMIN(stock,cstmr_rec,lst);
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
