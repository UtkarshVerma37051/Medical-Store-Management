#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<conio.h>
#include"Supplier.h"
#include"Validate_Input.h"

using namespace std;
void Supplier_List::add_supplier(struct supplier& sup)
{
    supplier_list.push_back(sup);
    string name="./Supplier Data/"+sup.code+".txt";
    ofstream fout(name);
    fout << sup.name << '\n';
    fout << sup.email << '\n';
    fout << sup.code << '\n';
    fout << sup.mob_no;
    fout.close();
}
//void Supplier_List::read_supplier()
//{
//    supplier s;
//    supplier_list.push_back(s);
//
////    string name="./Supplier Data/"+code+".txt";
//    ifstream fin("./Supplier Data/Supplier.txt");
//    while(!(fin.eof()))
//    {
//        fin >> s.name;
//        fin >> s.email;
//        fin >> s.code;
//        fin >> s.mob_no;
//        supplier_list.push_back(s);
//    }
//    fin.close();
//}
int Supplier_List::search_supplier(const string key)
{
    int size=supplier_list.size();
    for(int i=0;i<size;i++)
    {
        if(supplier_list[i].name == key || supplier_list[i].code == key)
            return i;
    }
    return -1;
}

void Supplier_List::display_suppliers_list()
{
    if(supplier_list.empty())
        cout << "No Suppliers.\n";
    else
    {
        cout << fixed << showpoint;
        cout << setprecision(2);
        cout << std::left <<  setw(20)  << "Name" << setw(20)  << "Code" << setw(20) << "Ph. No." << setw(20) << "Email" << endl;
        int size=supplier_list.size();
        for(int i=0;i<size;i++)
            cout << setw(20) << supplier_list[i].name << setw(20) << supplier_list[i].code << setw(20) << supplier_list[i].mob_no << setw(20)  << supplier_list[i].email << endl;
    }
}

void Supplier_List :: supplier_to_file()
{
    if(supplier_list.empty())
    {
        remove("./Supplier Data/Suppiler.txt");
        return;
    }
    ofstream fout("./Supplier Data/Supplier.txt");
    int size=supplier_list.size();
    for(int i=0;i<size;i++)
    {
        fout << supplier_list[i].name << '\n';
        fout << supplier_list[i].code << '\n';
        fout << supplier_list[i].mob_no << '\n';
        fout << supplier_list[i].email;
        if(i != size-1)
            fout << '\n';
    }
    fout.close();
}

void Supplier_List :: get_supplier_list()
{
    supplier_list.clear();
    ifstream fin("./Supplier Data/Supplier.txt");
    if(!fin)                                                        //Checking if file exists or not.
        return;
    struct supplier sup;
    while(!fin.eof())
    {
        getline(fin,sup.name);
        getline(fin,sup.code);
        fin >> sup.mob_no;
        fin.get();
        getline(fin,sup.email);
        supplier_list.push_back(sup);
    }
    fin.close();
}

void Supplier_List :: write_to_supplier_history(const struct Inventory_Struct& inv,const string& code)
{
    string name="./Supplier Data/"+code+".txt";
    ofstream fout(name,ios::app);
    fout << '\n' << inv.name << '\n';
    fout << inv.code << '\n';
    fout << inv.CP << ' ' << inv.SP << ' ' << inv.quantity;
    fout.close();
}

void Supplier_List :: read_from_supplier_history()
{
    string code;
    cout << "Enter Supplier Code (0 to exit):";
    cin >> code;
    if(code == "0")
        return;
    int found=search_supplier(code);
    if(found == -1)
        cout << "Supplier Not found." << endl;
    else
    {
        string name="./Supplier Data/"+code+".txt";
        ifstream fin(name);
        supplier s;
        getline(fin,s.name);
        getline(fin,s.email);
        getline(fin,s.code);
        fin >> s.mob_no;
        fin.get();
        struct Inventory_Struct his;
        cout <<"\nName    : " << s.name << "\nCode    : " << s.code << "\nMob no. : " << s.mob_no << "\nEmail   : " << s.email << endl;
        cout << endl;
        cout << fixed << showpoint;
        cout << setprecision(2);
        cout << std::left <<  setw(20)  << "Med Name" << setw(20) << "Med Code" << setw(20) << "Quantity" << setw(20) << "Cost Price" << setw(20) << "Selling Price" <<endl << endl;
        if(fin.eof())
        {
            cout << "\nRecord is Empty.\n";
            return;
        }
        while(!fin.eof())
        {
            getline(fin,his.name);
            getline(fin,his.code);
            fin >> his.CP >> his.SP >> his.quantity;
            fin.get();
            cout << setw(20) << his.name << setw(20) << his.code << setw(20) << his.quantity << setw(20) << his.CP << setw(20) << his.SP << endl;
        }
    }
}


void Supplier_List ::start()
{
    char ch;
    system("cls");
    string name,code,email,no;
    long long int mob_no;
    supplier s;
    while(1)
    {
        cout << "1. Add Supplier          : " << endl;
        cout << "2. View Supplier Details : " << endl;
        cout << "3. Supplier History      : " << endl;
        cout << "4. List All Suppliers    : " << endl;
        cout << "0. Exit                  : " << endl;
        cout << "   Enter your choice     : ";
        ch=getch();
        if(ch=='0')
            return ;
        switch(ch)
        {
        case '1'  :
            system("cls");
            cout << "Enter Supplier Name (0 to exit): ";
            fflush(stdin);
            getline(cin,name);
            if(name == "0")
                break;
            while(1)
            {
                cout << "Enter Supplier Code (0 to exit): ";
                fflush(stdin);
                getline(cin,code);
                if(code == "0")
                    break;
                if(search_supplier(code) != -1)
                {
                    cout << "Supplier Exists.\n";
                }
                else
                    break;
            }
            if(code=="0")
                break;
            while(1)
            {
                cout << "Enter Phone Number  (0 to exit): ";
                fflush(stdin);
                getline(cin,no);
                if(no=="0")
                    break;
                mob_no=check_phone_number(no);
                if(mob_no == 0)
                {
                    cout << "Invalid No.\n";
                }
                else
                    break;
            }
            if(no=="0")
                break;
            while(1)
            {
                cout << "Enter e-mail (0 to exit): ";
                fflush(stdin);
                getline(cin,email);
                if(email=="0")
                    break;
                if(check_mail(email) == 0)
                {
                    cout << "Invalid No.\n";
                }
                else
                    break;
            }
            if(email=="0")
                break;
            s={mob_no,name,code,email};
            add_supplier(s);
            cout << "Supplier Added." << endl;
            cout << "Press any key to exit." << endl;
            getch();
            system("cls");
            break;
        case '2'  :
            system("cls");
            if(supplier_list.empty())
            {
                cout << "No Suppliers.";
                cout << "Press any key to exit.";
                getch();
                system("cls");
                break;
            }
            while(1)
            {
                cout << "Enter Supplier code (0 to exit) : ";
                fflush(stdin);
                getline(cin,code);
                if(code=="0")
                    break;
                int found=search_supplier(code);
                if(found == -1)
                    cout << "Supplier not found.\n\n";
                else
                {
                    cout << "\nName        : " << supplier_list[found].name << endl;
                    cout << "Contact No. : " << supplier_list[found].mob_no << endl;
                    cout << "Email-Id.   : " << supplier_list[found].email << endl;
                    break;
                }
            }
            if(code=="0")
                break;
            cout << "\nPress any key to exit.";
            getch();
            system("cls");
            break;
        case '3'  :
//            string n;
            system("cls");
            if(supplier_list.empty())
            {
                cout << "No Suppliers.\n\n";
                cout << "Press any key to exit.";
                getch();
                system("cls");
                break;
            }
            read_from_supplier_history();
            cout << "\nPress any key to exit.";
            getch();
            system("cls");
            break;
        case '4'  :
            system("cls");
            display_suppliers_list();
            cout << "\nPress any key to exit.";
            getch();
            system("cls");
        break;
        default   :
            system("cls");
            cout << "Invalid Input!" << endl;
        }
        supplier_to_file();
    }
}
