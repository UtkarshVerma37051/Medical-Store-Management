
#ifndef NEW_INVENTORY_H_INCLUDED
#define NEW_INVENTORY_H_INCLUDED
#include "Supplier.h"
#include<vector>
using namespace std;
struct Inventory_Struct
{
    string name="";
    string code="";
    float CP=0;
    float SP=0;
    int quantity=0;
};
class Inventory
{
protected :
    vector<Inventory_Struct> inv_list;
public :
    friend class Supplier_List;
    friend class Customer_Section;
    void add_Inventory(Supplier_List &);
    int search_Inventory(string key,int flag);
    void display_Inventory();
    void write_to_file();
    void read_from_file();
    void modify_inventory(Supplier_List&);
    void add_to_inventory(Supplier_List&);
    void delete_inventory();
    void delete_Medicine();
    void display_specific_medicine(int );
    void get_data_for_customer();
    void export_to_excel();
    void Start(Supplier_List&);
//    void update_on_purchase()
};
#endif // NEW_INVENTORY_H_INCLUDED
