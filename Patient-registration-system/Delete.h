#include<string.h>
#include<Windows.h>
#include<cstring>
#include<conio.h>
 using namespace std;
int Deletemenu(){
  int choice;
  menu:
  cout << endl << endl;
  system("cls");
  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t*** What data do you want to delete?" << endl << endl ;
  cout << "\t\t\t\t\t\t\t\t--------------------------------------" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<1>The root node" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<2>Node having maximum Card number" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<3>A node with having minimum card number " << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<4> Exit" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t--------------------------------------" << endl << endl;
  cout << "\t\t\t\t\t\t\t\tEnter your choice:       ";
  cin >> choice;
   if (cin.fail()){
        cout<<endl<<"Invalid Input"<<endl;
        cin.clear();
        cin.ignore();
        goto menu;
    }
    if(choice ==1 || choice ==2 || choice==3 || choice ==4){
        return choice;
    }
    else{
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tWrong Input" << endl;
        cout << "\t\t\t\t\t\t\t\t\tPress any key to choose another option ...";
        getch();
        goto menu;
    }
}

