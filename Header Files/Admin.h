#include"Supplier.h"
#include"New_Inventory.h"
#include"Customer.h"
#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include<iostream>
class Admin //: public Inventory
{
    friend class Inventory;
    friend class Supplier_List;
    friend class Inventory_Struct;
    friend class Customer_Purchase_Record;
    friend class Customer_Record;
    string password;
public :
    void ADMIN(Inventory&,Customer_Record&,Supplier_List&);
    void Customer_Start(Customer_Record&);
};
#endif // ADMIN_H_INCLUDED
