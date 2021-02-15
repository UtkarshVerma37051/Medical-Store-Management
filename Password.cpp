#include<iostream>
#include<cstring>
#include<windows.h>
#include<fstream>
#include<conio.h>
using namespace std;

void LOGIN()
{
    system("cls");
    string pass="",orig_pass;
    ifstream fin("Password.txt");
    if(!fin)
    {
        fin.close();
        orig_pass="qwerty";
        ofstream fout("Password.txt");
        fout << '9';
        for(int i=0;i<6;i++)
            fout << ((char)((int)orig_pass[i]+6));
        fout.close();
    }
    else
    {
        char ch=fin.get();
//        char code=ch;
        while(1)
        {
            ch=fin.get();
            if(!fin.eof())
                orig_pass.push_back((char)((int)ch-6));
            else
                break;
        }
        fin.close();
    }
//    cout << "Original pass : " << orig_pass;
    //Login details
    PASSWORD:
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n \t\t\t\t\tPLEASE ENTER THE LOGIN PASSWORD: ";
    char ch;
    while(1)
    {
        ch = getch();
        if(ch=='\r')
            break;
        if(ch=='\b' && pass.empty()!=1)
        {
            pass.pop_back();
            cout << "\b \b";
        }
        else
        {
            if(ch!='\b')
            {
                pass.push_back(ch);
                cout << '*';
            }
        }
    }

    if(pass == orig_pass)
    {
        cout << "\n\n \t\t\t\t\tWELCOME........LOGIN IN SUCESSFULLY ";
        Sleep(1000);
        system("cls");
        return ;
    }
    else
    {
        cout << "\n\n \t\t\t\t\tIncorrect Login!";
        cout << "\n\n \t\t\t\t\tPLEASE WAIT . . . ";
        system("cls");
        pass.clear();
        goto PASSWORD;
    }
}

void resetpassword()
{
    system("cls");
    string pass,reset;
    Enter: printf("\nENETR NEW PASSWORD: ");
    char ch;
    while(1)
    {
        ch = getch();
        if(ch=='\r')
            break;
        if(ch=='\b' && pass.empty()!=1)
        {
            pass.pop_back();
            cout << "\b \b";
        }
        else
        {
            if(ch!='\b')
            {
                pass.push_back(ch);
                cout << '*';
            }
        }
    }

    printf("\nRECONFIRM PASSWORD: ");
    while(1)
    {
        ch = getch();
        if(ch=='\r')
            break;
        if(ch=='\b' && reset.empty()!=1)
        {
            reset.pop_back();
            cout << "\b \b";
        }
        else
        {
            if(ch!='\b')
            {
                reset.push_back(ch);
                cout << '*';
            }
        }
    }

    if(pass==reset)
    {
        ofstream fout("Password.txt");
        fout << '9';
        for(int i=0;i<6;i++)
            fout << ((char)((int)pass[i]+6));
        fout.close();
        cout << "\n\n*******************************" << endl;
        cout << "PASSWORD RESET SUCESSFULLY" << endl;
        cout << "*******************************" << endl;
        Sleep(1000);
        system("cls");
    }
    else
    {
            cout << "\nERROR: Password does not match" << endl;
            pass.clear();
            reset.clear();
            goto Enter;
    }
}
