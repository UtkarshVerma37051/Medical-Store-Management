#include<string>
#include<vector>
#include"New_Inventory.h"
#include<iostream>
#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
using namespace std;
struct customer
{
    string name;
    string address;
    long long int mob_no;
};

struct cart
{
    string med_name;
    string med_code;
    float med_price;
    int quantity;
};

class Customer_Record
{
    vector <customer> cstmr_list;
public :
    friend class Customer_Section;

    int search_in_record(long long int);
    void add_customer_to_record(struct customer);
    void read_from_record();
    void view_all_customer();
    void display_record();
    void add_to_purchased_list();
    void display_specific_record(int);
};

class Customer_Section
{
    friend class Inventory;
    friend class Customer_Record;
    vector<cart>cart_list;
    vector<float>profit;
    struct customer curnt_cstmr;
public :
    void  display_customer_details();
    void  display_cart();
    int   get_customer_data(Customer_Record&);
    void  add_to_cart(Inventory&);
    void  delete_from_cart();
    void  update_inventory(Inventory&);
    int  generate_bill(Inventory&);
    int   search_in_cart(string);
    float price_to_pay();
    void  START(Inventory&,Customer_Record&);
    void add_to_purchased_list(Customer_Record&,struct customer,Inventory&);
};

#endif // CUSTOMER_H_INCLUDED
