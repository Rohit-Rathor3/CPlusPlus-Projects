/* This is software to manage a school record of classes , teachers , students and staffs .*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;
class classes{
    int c_name;
    char c_incharge[30];
    int c_room_no;
    int total_student;
    public:
    classes(){
        c_name=1;
    }
    void getclassData();
    void showClassData();
    void searchClass();
    void UpdateClass();
    int className()
    {  
        return c_name;
    }
   }c1,c2;
   class student{
       int s_id , c_name;
       char s_name[30], f_name[30], s_add[50];
       char p_no[15];
       public:
       void addDetials();
       void showStudent();
       void addDetialsFile();
       void showDetailsFile();
       void searchStudent();
       void updateStudent();
       void deleteStudent();
       int getRollNo()
       {
           return s_id;
       }
   }s1;

   //--------------------------------------- Section of class Classes ------------------------------------// 
    //         ------------------  Taking Details of classes ------------------------
     void classes:: getclassData(){
        //                  Input Class Name 
        int classn;
        className:
        cout<<"\nEnter Class Name (1-12) : ";
        while(!(cin>>classn))
        {
            cout<<"\nError , a number must be entered : ";
            cin.clear();
            cin.ignore(132,'\n');
            goto className;
           
        }
        if(classn>12 || classn<1)
        {
            cout<<"\nPlz Enter correct class name !!";
            goto className;
        }
        ifstream file_obj;
        file_obj.open("Myschool.dat",ios::binary | ios::in);
        if(file_obj.is_open())
        {  int i=0;
           while(file_obj.read((char*)&c1 ,sizeof(c1)))
           {    ++i;
               if(classn==className())
               {  
                   cout<<"This class name exist already , plz try other name except "<<classn;
                   goto className;
                  
               }
               else{
                   c_name=classn;
                  
               }
            
           }
           file_obj.close();
        }
        
        //               Input Class Incharge Name 
        cout<<"\nEnter Class Incharge Name : ";
        cin.ignore();
        cin.getline(c_incharge,30);

        //              Input Class Room No.
        roomNo:
        cout<<"\nEnter Class Room No : ";
        while(!(cin>>c_room_no))
        {
            cout<<"\nError , a number must be entered : ";
            cin.clear();
            cin.ignore(132,'\n');
            goto roomNo;
           
        }
        if(!(c_room_no>0 && c_room_no<=100))
        {
            cout<<"\nPlz enter class name betwwen 1-100 :";
            goto roomNo;
        }
        
        //                Input Total Student 
        totalStudent:
        cout<<"\nEnter total registered students : ";
        while(!(cin>>total_student))
        {
            cout<<"\nError , a number must be entered : ";
            cin.clear();
            cin.ignore(132,'\n');
            goto totalStudent ;
           
        }
        if(!(total_student>0 && total_student<=200))
        {
            cout<<"\nPlz enter students between (1-200) : ";
            goto totalStudent;
        }
        char choice;
        choice:
        cout<<"\nDo you want to save details (y/n)";
        cin>>choice;
        if(choice=='y' || choice=='Y')
        {
        ofstream file_obj;
        file_obj.open("Myschool.dat",ios::binary | ios::app);
        if(file_obj.is_open())
        {
            file_obj.write((char*)&c1 ,sizeof(c1));
            file_obj.close();
            cout<<"\nData Saved Successfully !!!!";
        }
        else
        {
            cout<<"\n\tError --> To open the file !!!!";
        }
        }
        else if (choice=='n' || choice=='N')
        {  
            cout<<"\nYou didn't save the data !!";
        }
        else
        {
            cout<<"\nPlz Enter correct choice !!";
            goto choice;
        }
    }
      //              -------------------- Showing Details of classes ------------------------------
    void classes :: showClassData()
    {   
        ifstream file_obj;
        file_obj.open("Myschool.dat",ios::binary | ios::in);
        if(file_obj.is_open())
        {  cout<<"\n---------- Student's Details ----------";
           while(file_obj.read((char*)&c1 ,sizeof(c1)))
           {
           cout<<"\n\tClass Name     :- "<<c_name
            <<"\n\tIncharge Name  :- "<<c_incharge
            <<"\n\tClass Room No. :- "<<c_room_no
            <<"\n\tTotal Student  :- "<<total_student<<"\n";
           }
           file_obj.close();
        } 
        else
        {
            cout<<"\n\tError --> To open the file !!!!";
        }
    }
     //    ------------------------- Search Class By Class Name ---------------------------
    void classes ::searchClass(){
        int cn;
        bool found=0;
        cout<<"\n Enter Class Name You , want to search : ";
        cin>>cn;
        ifstream file_obj;
        file_obj.open("Myschool.dat",ios::binary | ios::in);
        if(file_obj.is_open())
        {  
           while(file_obj.read((char*)&c1 ,sizeof(c1)))
           {
               if(cn==className())
               {  found =1;
                  cout<<"\n\tClass Name :- "<<c_name
                  <<"\n\tIncharge Name  :- "<<c_incharge
                  <<"\n\tClass Room No. :- "<<c_room_no
                  <<"\n\tTotal Student  :- "<<total_student<<"\n";
               }
            
           }
           file_obj.close();
           if(found==0)
           {
               cout<<"\nThere is no class with this name in the record !!";
           }
           
        } 
        else
        {
            cout<<"\n\tError --> To open the file !!!!";
        }

    } 
    //            ---------------------- Update a class Record -------------------------
    void classes :: UpdateClass(){
        int cn,pos=0;
        bool found=0;
        cout<<"\n Enter Class Name You , want to Update : ";
        cin>>cn;
        fstream file_obj;
        file_obj.open("Myschool.dat",ios::binary | ios::in | ios::out);
        if(file_obj.is_open())
        {  
           while(file_obj.read((char*)&c1 ,sizeof(c1)))
           {   
               pos = file_obj.tellg();
               if(cn==className())
               {  
               found =1;
               cout<<"\n ------------------- Current record of class -----------------------";
                  
                  cout<<"\n\tClass Name     :- "<<c_name
                  <<"\n\tIncharge Name  :- "<<c_incharge
                  <<"\n\tClass Room No. :- "<<c_room_no
                  <<"\n\tTotal Student  :- "<<total_student<<"\n";
                  cout<<"\n -------------------- Enter New Details of class ------------------- ";

                  //         input class name 
                  className:
        cout<<"\nEnter Class Name (1-12) : ";
        while(!(cin>>c_name))
        {
            cout<<"\nError , a number must be entered : ";
            cin.clear();
            cin.ignore(132,'\n');
            goto className;
           
        }
        if(c_name>12 || c_name<1)
        {
            cout<<"\nPlz Enter correct class name !!";
            goto className;
        }
        
        //               Input Class Incharge Name 
        cout<<"\nEnter Class Incharge Name : ";
        cin.ignore();
        cin.getline(c_incharge,30);

        //              Input Class Room No.
        roomNo:
        cout<<"\nEnter Class Room No : ";
        while(!(cin>>c_room_no))
        {
            cout<<"\nError , a number must be entered : ";
            cin.clear();
            cin.ignore(132,'\n');
            goto roomNo;
           
        }
        if(!(c_room_no>0 && c_room_no<=100))
        {
            cout<<"\nPlz enter class name betwwen 1-100 :";
            goto roomNo;
        }
        
        //                Input Total Student 
        totalStudent:
        cout<<"\nEnter total registered students : ";
        while(!(cin>>total_student))
        {
            cout<<"\nError , a number must be entered : ";
            cin.clear();
            cin.ignore(132,'\n');
            goto totalStudent ;
           
        }
        if(!(total_student>0 && total_student<=200))
        {
            cout<<"\nPlz enter students between (1-200) : ";
            goto totalStudent;
        }

        file_obj.seekg(pos-sizeof(c1));
        file_obj.write((char*)&c1 ,sizeof(c1));
        file_obj.close();
        cout<<"\nData Saved Successfully !!!!";
        }
            
        }
           
        if(found==0)
           {
               cout<<"\nThere is no class with this name in the record !!";
           }
           
        file_obj.close();   
        } 
        else
        {
            cout<<"\n\tError --> To open the file !!!!";
        }

    }


//            ---------------- Class Portal -----------------
void classPortal()
{
    int choice;
    again:
    cout<<"\nEnter Your choie : "
        <<"\n1.Edit New Class : \n"
        <<"2.See All Classes : "
        <<"\n3.Search a class : "
        <<"\n4.Update a class : ";
    cin>>choice;
    switch(choice){
        case 1:
        c1.getclassData();
        break;
        case 2:
        c1.showClassData();
        break;
        case 3:
        c1.searchClass();
        break;
        case 4:
        c1.UpdateClass();
        break;
        default:
        cout<<"\n Invalid Choice : ";
        break;
    }
    goto again;
}

//----------------------------- Section Of Class Student ------------------------------------------------//

// ---------------------- Add Details --------------------------------
int validateInt(){
    int n;
    validInt:
    while(!(cin>>n))
        {
            cout<<"\nError , a number must be entered : ";
            cin.clear();
            cin.ignore(132,'\n');
            goto validInt;
           
        }
       
        return n;
}
void student::addDetials(){
    cout<<"\n\t\t--------------- Add Student Details --------------";
    className:
    cout<<"\n\tEnter Class Name : ";
    c_name=validateInt();
    if(c_name>12 || c_name<0)
    {
        cout<<"\n\tPlz enter correct class name (1-12) : ";
        goto className;
    }
    idName:    
    cout<<"\n\tStudent Id       : ";
    s_id=validateInt();
        if(s_id>2000 || s_id<1)
        {
            cout<<"\nPlz Enter correct Id name (1-2000) !!";
            goto idName;
        }
    cout<<"\n\tStudent Name     : ";cin.ignore();cin.getline(s_name,30);
    cout<<"\n\tFather Name      : ";cin.getline(f_name,30);
    cout<<"\n\tContact Number   : ";
    cin.getline(p_no,10);
    //cin.ignore();
    cout<<"\n\tPresent Address  : ";//
    cin.getline(s_add,50);
    cin.ignore();
    //cin.getline(s_add,50);
}

//    --------------------- show details -------------------------------
void student::showStudent(){
    cout<<"\n\tStudent Name  : "<<s_name;
    cout<<"\n\tFather Name   : "<<f_name;
    cout<<"\n\tClass         : "<<c_name;
    cout<<"\n\tRoll No.      : "<<s_id;
    cout<<"\n\tContact No.   : "<<p_no;
    cout<<"\n\tAddress       : "<<s_add;
}

// ---------------------- Add to file -----------------------------
void student::addDetialsFile(){
    addDetials();
    char choice;
        choice:
        cout<<"\nDo you want to save details (y/n)";
        cin>>choice;
        if(choice=='y' || choice=='Y')
        {
        ofstream file_obj;
        file_obj.open("myStudent.dat",ios::binary | ios::app);
        if(file_obj.is_open())
        {
        file_obj.write((char*)&s1,sizeof(s1));
        file_obj.close();
        cout<<"\nData Saved Successfully !!!!";
        }
        else
        {
            cout<<"\n\tError --> To open the file !!!!";
        }
        }
        else if (choice=='n' || choice=='N')
        {  
            cout<<"\nYou didn't save the data !!";
        }
        else
        {
            cout<<"\nPlz Enter correct choice !!";
            goto choice;
        }
    
}

//      ---------------------- Show Details from file -----------------------
void student::showDetailsFile()
{
    ifstream file_obj;
    file_obj.open("myStudent.dat" , ios::binary | ios::in);
    if(file_obj.is_open()){
        while(file_obj.read((char*)&s1,sizeof(s1)))
        {
            showStudent();
            cout<<endl;
        }
    }
    else
    {
        cout<<"\nError -> to open the file !!!";
    }
    file_obj.close();
}

void student::searchStudent(){
    cout<<"\n\tSearch a student by roll no :- ";
    int roll,flag=0;
    cout<<"\n\tEnter Roll No :- ";
    cin>>roll;
    ifstream file_obj;
    file_obj.open("myStudent.dat",ios::binary | ios::in);
    if(file_obj.is_open())
    {
        while(file_obj.read((char*)&s1,sizeof(s1)))
        {
            if(s_id==roll)
            {   
                flag=1;
                showStudent();
                cout<<endl;
            }
        }
    }
    else
    {
        cout<<"\n\t Error-> to open the file!!";
    }
    if(flag==0)
    {
        cout<<"\n\tNo record found!!";
    }
    file_obj.close();
}

// -------------------------- Update Record ---------------
void student::updateStudent()
{
    int rolno,pos=0,flag=0;
    cout<<"\n\tEnter Roll No. of student : ";
    cin>>rolno;
    fstream file_obj;
    file_obj.open("myStudent.dat" ,ios::binary | ios::in |ios::out);
    if(file_obj.is_open())
    {
      while(file_obj.read((char*)&s1,sizeof(s1)))
      {
          pos=file_obj.tellg();
          if(getRollNo()==rolno)
          {  
              flag=1;
             cout<<"\n\t---------- Current Details of Student -------------";
             showStudent();
             cout<<"\n\t---------- Edit New Details ------------------";
             addDetials();
             file_obj.seekg(pos-sizeof(s1));
             file_obj.write((char*)&s1,sizeof(s1));
             file_obj.close();

          }
          
      }
      if(!flag)
          {
              cout<<"\n\tNo record found !!!!";
          }
    }
    else{
        cout<<"Error -> To open the filen!!";
    }
}

// ------------- Delete a Record ---------------------
void student::deleteStudent()
{
     cout<<"\n---------------------- Delete a Record ----------------";
     int rolno;
     static int flag=0;
     cout<<"\n\tEnter Roll no :- ";
     cin>>rolno;
     fstream file_obj,file_obj1;

    file_obj.open("myStudent.dat",ios::binary | ios::in );
    file_obj1.open("myStudentDelete.dat" ,ios::binary | ios::app);
    if(!(file_obj.is_open() || file_obj1.is_open()))
    {
        cout<<"\n\tError -> To open the file !!";
    }
    // coping data of myStudent file to Delete file
    else
    {
        while(file_obj.read((char*)&s1,sizeof(s1)))
        {
            if(getRollNo()==rolno)
            {   
                flag=1;
            }
            else
            {
                file_obj1.write((char*)&s1,sizeof(s1));
            }
        }
        file_obj.close();
        file_obj1.close();
        
    // coping data from Delete file to myStudent file 
       if(flag==0)
       {
           cout<<"\n\t There is no record !!";
       }
       else
       {
           file_obj.open("myStudent.dat",ios::binary | ios::out);
           file_obj1.open("myStudentDelete.dat", ios::binary | ios::in);
           if(!(file_obj.is_open() || file_obj1.is_open()))
             {
              cout<<"\n\tError -> To open the file !!";
              }
            else
            {
                while(file_obj1.read((char*)&s1,sizeof(s1)))
                {
                    file_obj.write((char*)&s1,sizeof(s1));
                } 
            file_obj1.close();
            file_obj.close();
            file_obj1.open("myStudentDelete.dat",ios::binary | ios::out);
            file_obj1.close(); 
            cout<<"\n\t Record deleted sucessfully !!";

            } 
            
       }

     
}}
int main(){
    classPortal();
    //s1.addDetials();
    //s1.showStudent();
    //s1.addDetialsFile();
    //s1.showDetailsFile();
    //s1.searchStudent();
    //s1.updateStudent();
    //s1.deleteStudent();
    //s1.showDetailsFile();
    
    return 0;

}
