#include<iostream>
#include<fstream>
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
    int className()
    {  
        return c_name;
    }
   }c1;
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
        file_obj.open("Sonam.dat",ios::binary | ios::in);
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
        file_obj.open("Sonam.dat",ios::binary | ios::app);
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
    
    
    void classes :: showClassData()
    {   
        ifstream file_obj;
        file_obj.open("Sonam.dat",ios::binary | ios::in);
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
     
    int main()
    {
    	int choice;
    	cout<<"Enter choice 1. Add Class Data \n 2. Display Class";
    	cin>>choice;
    	switch(choice)
    	{
    		case 1:
    			c1.getclassData();
    			break;
    		case 2:
			   c1.showClassData();
			   break;
			default:
				cout<<"Invalid Choice";
			   	
		}
	}
