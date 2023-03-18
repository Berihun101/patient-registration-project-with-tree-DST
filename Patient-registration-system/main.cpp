#include <iostream>
#include <string>
#include<windows.h>
#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<Windows.h>
#include<cstring>
#include<conio.h>
//below are custom header files
#include "enterance.cpp"
#include "mainmenu.h"
#include "Reader.h"
#include "searchmenu.h"
#include "Delete.h"
#include "dispaly.h"

using namespace std;
struct patient{
    //data fields
 char name[20];
 char fname[20];
 double cardNO;
 char sex[7];
 int age;
 double phone;
 char bloodtype[3];
 struct patient *right;
 struct patient *left;
 int height;
};
struct patient *root=NULL;
ofstream myfile;
//methods
void Print(patient * root, int num);
void  searchbyCardNo(patient *root, double key);
void displayNode(patient *targetNode);
void searchbyName(patient *root,char TargetName[]);
void searchbyFname(patient *root, char TargetFname[]);
void searchbyBloodType(patient*root,char TargetBloodType[]);
void searchbyAge(patient *root,int TargetAge);
int deleteRoot(patient *root);
struct patient* deleteData(struct patient* root, int key);
struct patient* minValueNode(struct patient* node);
struct patient * maxValueNode(struct patient* node);
void PrintPostorder( struct patient * root, int num);
void PrintInorder( struct patient * root, int num);
void PrintPreorder( struct patient * root, int num);
void recordFromFile(patient *root);
void insertedNode(patient *fileNode );
int insertData();
int nodeNum=0;
void rightRotate(patient *&root) ;
void leftRotate(patient *&root);
int height(patient *root);
void balanceBSTwithAVL(patient *&root);
 bool check(patient * root, double cardNumber);
int main()
{
    int num=1;
    enterance();
     int checker=0;
    mainentrance:
    int navigation;
    navigation = menu();
    system("cls");
    if(navigation==1){

        int amount;
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tEnter the number of patient you wish to enter:  ";
    cin>>amount;
    for(int i=0; i<amount; i++){
        insertData();
        nodeNum++;
    }
       system("cls");
       checker++;
      goto mainentrance;

    }
    else if(navigation==2){
          if (checker == 0)
        {   system("cls");
            cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSorry! There was no information to display fill information and come back!";
            cout << "\n\n\t\t\t\t\tPress any key to choose another option ...";
            getch();
            goto mainentrance;
          }
          else{
            system("cls");
            myfile.open("store_file.txt" );
            myfile << "\n\n\t\t\t\t\t\t\t ********** Display patient records ********** \n";
            myfile<<left<<setw(5)<<"N0"<<left<<setw(27)<<"Personal Information"<<left<<setw(15)<<"value";
            myfile << "\n--------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            int num=1;
            Print(root, num);
            myfile.close();
             cout << "the Data has been printed in to a file called store_file";
             cout << "\n\n\t\t\t\t\tPress any key to return to main menu ...";
             getch();
          goto mainentrance;
          }
    }
    else if(navigation==3){
          if (checker == 0)
        {   system("cls");
            cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSorry! There was no information to display fill information and come back!";
            cout << "\n\n\t\t\t\t\tPress any key to choose another option ...";
            getch();
            goto mainentrance;
          }
          else{
            system("cls");
               read();
              goto mainentrance;
          }
    }
    else if(navigation==4){
               if (checker == 0)
        {   system("cls");
            cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSorry! There was no information to display fill information and come back!";
            cout << "\n\n\t\t\t\t\tPress any key to choose another option ...";
            getch();
            goto mainentrance;
          }
    else{
             searchMenu:
        int navsearch=searchMenu();
        system("cls");
        if(navsearch==1){
            double key;
           cout << "\n\n\t\t\t\t\tWhat is the card number that you are looking for? ...";
           cin >>key;
            searchbyCardNo(root,key);
           goto searchMenu;
        }
        else if(navsearch==2){
            char TargetName[20];
            cout << "\n\n\t\t\t\t\tWhat is the First name that you are looking for? ...";
            cin >>TargetName;
            searchbyName(root,TargetName);
            goto searchMenu;

        }
         else if(navsearch==3){
            char TargetFname[20];
            cout << "\n\n\t\t\t\t\tWhat is the Father name that you are looking for? ...";
            cin >>TargetFname;
            searchbyFname(root,TargetFname);
            goto searchMenu;

        }
          else if(navsearch==4){
            char TargetBloodType[2];
            cout << "\n\n\t\t\t\t\tWhat is the Blood type that you are looking for? ...";
            cin >>TargetBloodType;
            searchbyBloodType(root,TargetBloodType);
            goto searchMenu;

        }
          else if(navsearch==5){
            int TargetAge;
            cout << "\n\n\t\t\t\t\tWhat is the Blood type that you are looking for? ...";
            cin >>TargetAge;
            searchbyAge(root,TargetAge);
            goto searchMenu;

        }
        else{
            goto mainentrance;
        }

    }

    }
    else if(navigation==5){
               if (checker == 0)
        {   system("cls");
            cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSorry! There was no information to display fill information and come back!";
            cout << "\n\n\t\t\t\t\tPress any key to choose another option ...";
            getch();
            goto mainentrance;
          }
          else{
            cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t The number of Patient are:"<<nodeNum;
            cout << "\n\n\t\t\t\t\tPress any key to return ...";
             getch();
            goto mainentrance;
          }

    }
    else if(navigation==6){
       if (checker == 0)
        {   system("cls");
            cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSorry! There was no information to display fill information and come back!";
            cout << "\n\n\t\t\t\t\tPress any key to choose another option ...";
            getch();
            goto mainentrance;
          }
          else{
                  deletemenu:
                int navDelete=Deletemenu();
                if(navDelete==1){
                   root=deleteData(root, root->cardNO);
                   nodeNum--;
            myfile.open("store_file.txt" );
            myfile << "\n\n\t\t\t\t\t\t\t ********** Display patient records ********** \n";
            myfile<<left<<setw(5)<<"N0"<<left<<setw(27)<<"Personal Information"<<left<<setw(15)<<"value";
            myfile << "\n--------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            Print(root, num);
            myfile.close();
            system("cls");
            cout<<"\n\n\t\t\t\t\tHere is the result after deletion";
            read();

            goto deletemenu;
                }
                else if(navDelete==2){
                    struct patient *minnode=minValueNode(root);
                    root=deleteData(root, minnode->cardNO);
                    nodeNum--;
            myfile.open("store_file.txt" );
            myfile << "\n\n\t\t\t\t\t\t\t ********** Display patient records ********** \n";
            myfile<<left<<setw(5)<<"N0"<<left<<setw(27)<<"Personal Information"<<left<<setw(15)<<"value";
            myfile << "\n--------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            int num=1;
            Print(root, num);
            myfile.close();
            system("cls");
            cout<<"\n\n\t\t\t\t\tHere is the result after deletion";
            read();

                      goto deletemenu;
                }
                else if(navDelete==3){
                 struct patient *maxnode=maxValueNode(root);
                 root=deleteData(root, maxnode->cardNO);
                 nodeNum--;
                     myfile.open("store_file.txt" );
            myfile << "\n\n\t\t\t\t\t\t\t ********** Display patient records ********** \n";
            myfile<<left<<setw(5)<<"N0"<<left<<setw(27)<<"Personal Information"<<left<<setw(15)<<"value";
            myfile << "\n--------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            Print(root, num);
            myfile.close();
            system("cls");
            cout<<"\n\n\t\t\t\t\tHere is the result after deletion";
            read();
                 goto deletemenu;
                }
                else{
                    goto mainentrance;
                }

           cout << "\n\n\t\t\t\t\tPress any key to choose another option ...";
            getch();
            goto mainentrance;

          }



    }
    else if(navigation==7){
        if (checker == 0)
        {   system("cls");
            cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSorry! There was no information to display fill information and come back!";
            cout << "\n\n\t\t\t\t\tPress any key to choose another option ...";
            getch();
            goto mainentrance;
          }
          else{
            patient *minNode;
            minNode=minValueNode(root);
            displayNode(minNode);
            goto mainentrance;
          }
    }
    else if(navigation==8){
             if (checker == 0)
        {   system("cls");
            cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSorry! There was no information to display fill information and come back!";
            cout << "\n\n\t\t\t\t\tPress any key to choose another option ...";
            getch();
            goto mainentrance;
          }
    else{
     patient *maxNode;
     maxNode=maxValueNode(root);
     displayNode(maxNode);
     goto mainentrance;
    }

    }
    else if(navigation==9){
           if (checker == 0)
        {   system("cls");
            cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSorry! There was no information to display fill information and come back!";
            cout << "\n\n\t\t\t\t\tPress any key to choose another option ...";
            getch();
            goto mainentrance;
          }
          else{
                display:
                int choice;
             choice=Displayinfo();
             if(choice==1){


            system("cls");
            cout << "\n\n\t\t\t\t\t\t\t ********** Display patient records ********** \n";
            cout<<left<<setw(5)<<"N0"<<left<<setw(27)<<"Personal Information"<<left<<setw(15)<<"value";
            cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            PrintPreorder(root, num);
            cout << "\n\n\t\t\t\t\tPress any key to choose another option ...";
            getch();
            system("cls");
             goto display;
             }
             else if(choice==2){


            int num=1;
            system("cls");
             cout<< "\n\n\t\t\t\t\t\t\t ********** Display patient records ********** \n";
            cout<<left<<setw(5)<<"N0"<<left<<setw(27)<<"Personal Information"<<left<<setw(15)<<"value";
            cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            PrintInorder(root, num);
            cout << "\n\n\t\t\t\t\tPress any key to choose another option ...";
            getch();
            system("cls");
            goto display;

             }
              else if(choice==3){


            int num=1;
            system("cls");
            cout<< "\n\n\t\t\t\t\t\t\t ********** Display patient records ********** \n";
            cout<<left<<setw(5)<<"N0"<<left<<setw(27)<<"Personal Information"<<left<<setw(15)<<"value";
            cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            PrintPostorder(root, num);
            cout << "\n\n\t\t\t\t\tPress any key to choose another option ...";
            getch();
            system("cls");
            goto display;

             }
             else{
                goto mainentrance;
             }


          }

    }
    else if(navigation==11){

             recordFromFile(root);
              checker++;
             goto mainentrance;
    }

    else if(navigation==10){
              if (checker == 0)
        {   system("cls");
            cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSorry! There was no information to balance fill information and come back!";
            cout << "\n\n\t\t\t\t\tPress any key to choose another option ...";
            getch();
            goto mainentrance;
          }
    else{
       balanceBSTwithAVL(root);
        cout<<"Done! the BST is balanced with AVL balancing method"<<endl;
        cout<<"press any key to return";
        getch();
        goto mainentrance;
     }

    }
    else{
        exit(0);
    }
    return 0;
}
int insertData(){
    patient *InsertNode= new patient;
 cout<<endl<<"Enter first name of the patient"<<endl;
	  cin>>InsertNode->name;
 cout<<endl<<"Enter Father name of the patient"<<endl;
	  cin>>InsertNode->fname;
 cout<<endl<<"Enter sex of patient"<<endl;
	  cin>>InsertNode->sex;
	   a:
 cout<<endl<<"Enter AGE of patient"<<endl;
	  cin>>InsertNode->age;
 if (cin.fail() || InsertNode->age<0 || InsertNode->age>200){
 cout<<endl<<"Invalid Input"<<endl;
        cin.clear();
        cin.ignore();
        goto a;
    }
     b:
 cout<<endl<<"Enter phone number"<<endl;
	  cin>>InsertNode->phone;
	  if (cin.fail()){
        cout<<endl<<"Invalid Input"<<endl;
        cin.clear();
        cin.ignore();
        goto b;
    }
    c:
 cout<<endl<<"Enter card number of the patient(5-digit)"<<endl;
	  cin>>InsertNode->cardNO;
	  	  if (cin.fail()){
 cout<<endl<<"Invalid Input"<<endl;
        cin.clear();
        cin.ignore();
        goto c;
    }
     bool checking=false;
    checking=check(root, InsertNode->cardNO);
    if(checking){
        goto c;
    }
cout<<endl<<"Enter Blood type of the patient"<<endl;
	  cin>>InsertNode->bloodtype;
     InsertNode->left=NULL;
     InsertNode->right=NULL;
     InsertNode->height = 1;
        if(root == NULL)
        root = InsertNode;
    else
    {
        patient *i = root;
        bool isInserted = false;
        while(isInserted == false)
        {
            if (i ->cardNO  > InsertNode -> cardNO)
            {
                if (i -> left == NULL)
                {
                    i -> left = InsertNode;
                    isInserted = true;
                }
                else
                    i = i -> left;
            }
            else
            {
                if (i -> right == NULL)
                {
                    i -> right = InsertNode;
                    isInserted = true;
                }
                else
                    i = i -> right;
            }
        }
    }
      system("cls");
      cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tSaved ... ";
       Sleep(700);
        system("cls");





 return 0;
}

 void Print( struct patient * root, int num){

    if(root != NULL){


             myfile<<left<<setw(5)<<num<<left<<setw(27)<< "First name:"<<left<<setw(15)<<root->name<<endl;
             myfile<<setw(5)<<" "<<setw(27)<<"Father name:"<<left<<setw(15)<<root->fname<<endl;
             myfile<<setw(5)<<" "<<setw(27)<<"Card number:"<<left<<setw(15)<<root->cardNO<<endl;
             myfile<<setw(5)<<" "<<setw(27)<<"Age:"<<root->age<<endl;
             myfile<<setw(5)<<" "<<setw(27)<<"Gender:"<<left<<setw(15)<<root->sex<<endl;
             myfile<<setw(5)<<" "<<setw(27)<<"Phone Number:"<<left<<setw(15)<<root->phone<<endl;
             myfile<<setw(5)<<" "<<setw(27)<<"Blood Type:"<<left<<setw(15)<<root->bloodtype<<endl;
             myfile<<endl;
                 num++;
             Print(root->left, num);
             Print(root->right, num);

       }

}
 void PrintInorder( struct patient * root, int num){

    if(root != NULL){

               PrintInorder(root->left, num);

             cout<<left<<setw(5)<<num<<left<<setw(27)<< "First name:"<<left<<setw(15)<<root->name<<endl;
             cout<<setw(5)<<" "<<setw(27)<<"Father name:"<<left<<setw(15)<<root->fname<<endl;
             cout<<setw(5)<<" "<<setw(27)<<"Card number:"<<left<<setw(15)<<root->cardNO<<endl;
             cout<<setw(5)<<" "<<setw(27)<<"Age:"<<root->age<<endl;
             cout<<setw(5)<<" "<<setw(27)<<"Gender:"<<left<<setw(15)<<root->sex<<endl;
             cout<<setw(5)<<" "<<setw(27)<<"Phone Number:"<<left<<setw(15)<<root->phone<<endl;
             cout<<setw(5)<<" "<<setw(27)<<"Blood Type:"<<left<<setw(15)<<root->bloodtype<<endl;
             cout<<endl;
               num++;
             PrintInorder(root->right, num);

       }

}
 void PrintPostorder( struct patient * root, int num){

    if(root != NULL){

               PrintPostorder(root->left, num);
               PrintPostorder(root->right, num);
              cout<<left<<setw(5)<<num<<left<<setw(27)<< "First name:"<<left<<setw(15)<<root->name<<endl;
             cout<<setw(5)<<" "<<setw(27)<<"Father name:"<<left<<setw(15)<<root->fname<<endl;
             cout<<setw(5)<<" "<<setw(27)<<"Card number:"<<left<<setw(15)<<root->cardNO<<endl;
             cout<<setw(5)<<" "<<setw(27)<<"Age:"<<root->age<<endl;
             cout<<setw(5)<<" "<<setw(27)<<"Gender:"<<left<<setw(15)<<root->sex<<endl;
             cout<<setw(5)<<" "<<setw(27)<<"Phone Number:"<<left<<setw(15)<<root->phone<<endl;
             cout<<setw(5)<<" "<<setw(27)<<"Blood Type:"<<left<<setw(15)<<root->bloodtype<<endl;
             cout<<endl;
                num++;






       }

}
 void PrintPreorder( struct patient * root, int num){

 if(root != NULL){


              cout<<left<<setw(5)<<num<<left<<setw(27)<< "First name:"<<left<<setw(15)<<root->name<<endl;
             cout<<setw(5)<<" "<<setw(27)<<"Father name:"<<left<<setw(15)<<root->fname<<endl;
             cout<<setw(5)<<" "<<setw(27)<<"Card number:"<<left<<setw(15)<<root->cardNO<<endl;
             cout<<setw(5)<<" "<<setw(27)<<"Age:"<<root->age<<endl;
             cout<<setw(5)<<" "<<setw(27)<<"Gender:"<<left<<setw(15)<<root->sex<<endl;
             cout<<setw(5)<<" "<<setw(27)<<"Phone Number:"<<left<<setw(15)<<root->phone<<endl;
             cout<<setw(5)<<" "<<setw(27)<<"Blood Type:"<<left<<setw(15)<<root->bloodtype<<endl;
             cout<<endl;
              num++;
             PrintPreorder(root->left, num);
             PrintPreorder(root->right, num);







       }





 }
void  searchbyCardNo(patient *root, double key)
{
    int found=0;
if(root == NULL)
        cout<<"Patient Not Found."<<endl;
    else
    {
        if(root -> cardNO == key)
            displayNode(root);
        else if(key < root -> cardNO)
            searchbyCardNo(root -> left, key);
        else
            searchbyCardNo(root -> right, key);
            found++;
    }
    if(found==0){
       cout<<"the card number you entered is not in the list please enter valid card number";
       cout << "\n\n\t\t\t\t\tPress any key to return back ...";
            getch();
    }


}
void displayNode(patient *targetNode){
  cout<<"\n\n\t\t\t\t\tHere is the result we got "<<endl;
  cout<<"\t\t\t\t\tCard number: "<<targetNode->cardNO<<endl;
  cout<<"\t\t\t\t\tName: "<<targetNode->name<<endl;
  cout<<"\t\t\t\t\tFather name: "<<targetNode->fname<<endl;
  cout<<"\t\t\t\t\tPhone: "<<targetNode->phone<<endl;
  cout<<"\t\t\t\t\tGender: "<<targetNode->sex<<endl;
  cout<<"\t\t\t\t\tBlood type: "<<targetNode->bloodtype<<endl;
  cout << "\t\t\t\t\tPress any key to choose another option ...";
            getch();

}
void searchbyName(patient *root,char TargetName[]){
    int found=0;
    if (root != NULL)
    {
        if (strcmp(root -> name, TargetName) == 0)
        {
            displayNode(root);
            searchbyName(root -> left, TargetName);
            searchbyName(root -> right, TargetName);
             found++;
        }
        else
        {
            searchbyName(root -> left, TargetName);
            searchbyName(root -> right, TargetName);
             found++;
        }
    }


}
void searchbyFname(patient *root,char TargetFname[]){
 int found=0;
 if (root != NULL)
    {
        if (stricmp(root -> fname, TargetFname) == 0)
        {
            displayNode(root);
            searchbyFname(root -> left, TargetFname);
           searchbyFname(root -> right, TargetFname);
           found++;
        }
        else
        {
            searchbyFname(root -> left, TargetFname);
            searchbyFname(root -> right, TargetFname);
            found++;
        }
    }

}
void searchbyBloodType(patient*root,char TargetBloodType[]){

if (root != NULL)
    {
        if (stricmp(root ->bloodtype, TargetBloodType) == 0)
        {
            displayNode(root);
            searchbyBloodType(root -> left, TargetBloodType);
            searchbyBloodType(root -> right, TargetBloodType);
        }
        else
        {
            searchbyBloodType(root -> left, TargetBloodType);
            searchbyBloodType(root -> right, TargetBloodType);
        }
    }


}
void searchbyAge(patient *root,int TargetAge){

if (root != NULL)
    {
        if (root->age == TargetAge)
        {
            displayNode(root);
            searchbyAge(root -> left, TargetAge);
            searchbyAge(root -> right, TargetAge);

        }
        else
        {
            searchbyAge(root -> left, TargetAge);
            searchbyAge(root -> right, TargetAge);

        }
    }


}
int deleteRoot(patient *root){
    patient *temp=root;
    int num=1;
if(root->left==NULL && root->right==NULL){

 cout<<"\n\n\t\t\t\t\t"<<root->name<<" has been deleted successfully"<<endl;
    root=NULL;
    free(temp);

}

  else if(root->left==NULL && root->right!=NULL){
      cout<<"\n\n\t\t\t\t\t"<<root->name<<" has been deleted successfully"<<endl;
        root=temp->right;
         free(temp);

}

 else if(root->left!=NULL && root->right==NULL){
     cout<<"\n\n\t\t\t\t\t"<<root->name<<" has been deleted successfully"<<endl;
     root=temp->left;
      free(temp);
 }

else
    {
 while(temp!=NULL){
    root=temp;
    temp=temp->left;
 }
 cout<<"\n\n\t\t\t\t\t"<<root->name<<" has been deleted successfully"<<endl;
   root=nullptr;

}


return 0;
}
//this function deletes data with the given key
struct patient* deleteData(struct patient* root, int key){
      if (key < root->cardNO)
         root->left = deleteData(root->left, key);
      else if (key > root->cardNO)
         root->right = deleteData(root->right, key);
   else{
      if (root->left == NULL){
         patient *temp = root->right;
         free(root);
         return temp;
      }
      else if (root->right == NULL){
         patient *temp = root->left;
         free(root);
         return temp;
      }
      struct patient* temp = minValueNode(root->right);
      root->cardNO = temp->cardNO;
      root->right = deleteData(root->right, temp->cardNO);
   }
   return root;
}
struct patient * minValueNode(struct patient* node){
   struct patient* current = node;
   while (current && current->left != NULL)
      current = current->left;
   return current;
}
struct patient * maxValueNode(struct patient* node){
struct patient* current = node;
   while (current && current->right != NULL)
      current = current->right;
   return current;

}
//this function record a data from a file
void recordFromFile(patient *root)
{
     int numberOfPatient;
 char nameFile[20];
 char fnameFile[20];
 double cardNOFile;
 char sexFile[7];
 int ageFile;
 double phoneFile;
 char bloodtypeFile[3];
    i: cout<<"\t\tEnter the number of patient you want to record from the file"<<endl<<"\t\t";
    cin>>numberOfPatient;
    if (cin.fail())
    {
        cout<<endl<<"\t\tInvalid Input."<<endl;
        cin.clear();
        cin.ignore();
        goto i;
    }
    ifstream file;
    file.open("Patient.txt");
    if(file.is_open())
    {
        for (int i = 0; i < numberOfPatient; i++)
        {
            patient *node = new patient;

            file>>nameFile;
            strcpy(node -> name,nameFile);

            file>>fnameFile;
            strcpy(node -> fname, fnameFile);

            file>>cardNOFile;
            node -> cardNO = cardNOFile;

            file>>ageFile;
            node -> age = ageFile;

            file>>sexFile;
            strcpy(node -> sex,sexFile);

            file>>phoneFile;
            node -> phone = phoneFile;

            file>>bloodtypeFile;
           strcpy(node -> bloodtype, bloodtypeFile);

            node -> left = NULL;
            node -> right = NULL;
            node->height = 1;
            insertedNode(node);
        }
        system("cls");
        cout<<"\t\tDone  data has been added to the BST successfully!"<<endl;
         cout << "\n\n\t\t\t\t\tPress any key to choose another option ...";
            getch();
        file.close();
    }
    else
        cout<<"\t\tError opening file!"<<endl;
}
//this function inserts data from the file
void insertedNode(patient *fileNode )
{
 if(root == NULL)
        root = fileNode;
    else
    {
        patient *i = root;
        bool isInserted = false;
        while(isInserted == false)
        {
            if (i ->cardNO  > fileNode -> cardNO)
            {
                if (i -> left == NULL)
                {
                    i -> left = fileNode;
                    isInserted = true;
                }
                else
                    i = i -> left;
            }
            else
            {
                if (i -> right == NULL)
                {
                    i -> right = fileNode;
                    isInserted = true;
                }
                else
                    i = i -> right;
            }
        }
    }
nodeNum++;




}
//this function determines the height of a specific node
int height(patient *root) {
if(root == nullptr) return 0;
int leftHeight = height(root->left);
int rightHeight = height(root->right);
return 1 + max(leftHeight, rightHeight);
}
void leftRotate(patient *&root) {
patient *newRoot = root->right;
root->right = newRoot->left;
newRoot->left = root;
root = newRoot;
}
void rightRotate(patient *&root) {
patient *newRoot = root->left;
root->left = newRoot->right;
newRoot->right = root;
root = newRoot;
}
//this is the main function that balances the BST tree
void balanceBSTwithAVL(patient *&root) {
int heightDifference = height(root->left) - height(root->right);
if(heightDifference > 1) {
int leftHeightDifference = height(root->left->left) - height(root->left->right);
if(leftHeightDifference > 0) {
rightRotate(root);
}
else {
leftRotate(root->left);
rightRotate(root);
}
}
else if(heightDifference < -1) {
int rightHeightDifference = height(root->right->left) - height(root->right->right);
if(rightHeightDifference < 0) {
leftRotate(root);
}
else {
rightRotate(root->right);
leftRotate(root);
}
}
}
//this is a function that checks if the user enter the same number or not
 bool check(patient * root, double cardNumber){
if (root != NULL)
    {
        if (root->cardNO ==  cardNumber)
        {
            cout<<"The card number is already exist! please enter another";
            return true;
            check(root -> left,  cardNumber);
            check(root -> right,  cardNumber);

        }
        else
        {
            check(root -> left,   cardNumber);
            check(root -> right,  cardNumber);

        }
    }
}
