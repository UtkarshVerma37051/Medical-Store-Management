#include "New_Inventory.h"
#ifndef SUPPLIER_H_INCLUDED
#define SUPPLIER_H_INCLUDED
#include<cstring>
#include<vector>
using namespace std;
struct supplier
{
    long long int mob_no=0;
    string name="";
    string code="";
    string email="";
};

class Supplier_List
{
    vector<struct supplier> supplier_list;
public :
    friend class Inventory;
    void add_supplier(struct supplier&);
//    void modify_suppler();
    int search_supplier(const string);
    void display_suppliers_list();
    void supplier_to_file();
    void write_to_supplier_history(const struct Inventory_Struct& ,const string& code);
    void read_from_supplier_history();
    void get_supplier_list();
    void start();
};
#endif // SUPPLIER_H_INCLUDED
