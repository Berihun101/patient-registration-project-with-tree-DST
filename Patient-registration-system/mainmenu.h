#include<string.h>
#include<Windows.h>
#include<cstring>
#include<conio.h>
using namespace std;

int menu()
{

   int choice;

  mainmenu:
  cout << endl << endl;
  system("cls");
  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t*** Where do you want to go" << endl << endl ;
  cout << "\t\t\t\t\t\t\t\t--------------------------------------" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<1> ADD patient record" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<2> write the recorded data to a file" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<3> DISPLAY EXSISTING RECORDS(fetch from a file)" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<4> Search a specific record " << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<5> count number of recorded data" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<6> Delete information" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<7> Display a node with minimum Card number" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<8> Display a node with maximum Card number" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<9> Display information" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<10> Balance the BST with AVL balanced rotation" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<11> Add data from the file to the BST" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t<12> Exit" << endl << endl;
  cout << "\t\t\t\t\t\t\t\t--------------------------------------" << endl << endl;
  cout << "\t\t\t\t\t\t\t\tEnter your choice:       ";
  cin >> choice;
  if (cin.fail()){
        cout<<endl<<"Invalid Input"<<endl;
        cin.clear();
        cin.ignore();
        goto mainmenu;
    }
  cout << endl << endl;
 if(choice ==1 || choice ==2 || choice==3 || choice ==4 || choice ==5 || choice==6 || choice ==7 || choice==8 || choice==9 || choice==10 || choice==11  || choice==12 )
 {

  return choice;
 }
   else
   {
         system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tWrong Input" << endl;
        cout << "\t\t\t\t\t\t\t\t\tPress any key to choose another option ...";
        getch();
        goto mainmenu;
   }

}
