#include <iostream>
#include <string>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<iomanip>

int searchMenu(){
  int choice;
  menu:
  cout << endl << endl;
  system("cls");
  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t*** in What attribute do you want to find a patient?" << endl << endl ;
  cout << "\t\t\t\t\t\t\t\t--------------------------------------" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<1>By card number" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<2>BY name" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<3>By father name  " << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<4> By Blood type" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<5> By Age" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<6> Exit" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t--------------------------------------" << endl << endl;
  cout << "\t\t\t\t\t\t\t\tEnter your choice:       ";
  cin >> choice;
   if (cin.fail()){
        cout<<endl<<"Invalid Input"<<endl;
        cin.clear();
        cin.ignore();
        goto menu;
    }
    if(choice ==1 || choice ==2 || choice==3 || choice ==4 || choice ==5 || choice==6 ){
        return choice;
    }
    else{
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tWrong Input" << endl;
        cout << "\t\t\t\t\t\t\t\t\tPress any key to choose another option ...";
        getch();
        goto menu;
    }
}
