#include<string.h>
#include<Windows.h>
#include<cstring>
#include<conio.h>
 using namespace std;
int Displayinfo(){
  int choice;
  menu:
  cout << endl << endl;
  system("cls");
  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t*** In what method do you want to traverse the recorded data?" << endl << endl ;
  cout << "\t\t\t\t\t\t\t\t--------------------------------------" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<1>Preorder" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<2>Inorder" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<3>Postorder " << endl << endl;
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
