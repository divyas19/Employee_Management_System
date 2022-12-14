#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstdio>
#include<unistd.h>
#include<cstring>

using namespace std;

class Employee{
    private:
        // Variables used for employee details
        char name[30];
        char id[5];
        char desig[10];
        int age;
        int ctc;
        int exp;

        // Utility functions
        void waitForEnter(void){
            cout<<"\n\n\n Press the enter button to go back \n\n";
            cin.get();
            cin.get();
        }

        //To list total employees with Name, Id and Designation
        void listEmployees(void)
		{ 
            system("cls");
            FILE *file;
            file= fopen("data.txt", "r");
            cout<<"\n\t      List of All Employees\n";
            cout<<"\n----------------------------------------------";
            cout<<"\n NAME        |     ID     |     DESIGNATION\n";
            cout<<"----------------------------------------------";
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &desig[0], &age, &ctc, &exp)!= EOF)
                cout<<"\n"<<name<<"\t\t"<<id<<"\t\t"<<desig;
            fclose(file);
            waitForEnter();
        }
        
        //Displays all details according to Employee's id
        void showDetails(void)
		{ 
            system("cls");
            FILE *file;
            char checkId[5];
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &desig[0], &age, &ctc, &exp)!=EOF)
                if(strcmp(checkId,id)==0){
                    cout<<"\nId: "<<id;
                    cout<<"\nDesignation: "<<desig;
                    cout<<"\nAge: "<<age;
                    cout<<"\nCTC: "<<ctc;
                    cout<<"\nExperience: "<<exp;
                }
            fclose(file);
            waitForEnter();
        }
        
        //Edits Designation and CTC of an employee
        void editExisting(void)
		{ 
            system("cls");
            char checkId[5];
            cout<<"\nEnter the employee id: ";
            cin>>checkId;
            char newDesignation[10];
            cout<<"\n-----------------------------";
            cout<<"\nEnter new designation: ";
            cin>>newDesignation;
            int newCtc;
            cout<<"------------------------------";
            cout<<"\nEnter new CTC: ";
            cin>>newCtc;
            FILE *file, *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &desig[0], &age, &ctc, &exp)!=EOF)
			{
                if(strcmp(checkId, id)==0)
                    fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, newDesignation, age, newCtc, exp );
                else
                    fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, desig, age, ctc, exp );
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("data.txt");
            int isRenamed= rename("temp.txt", "data.txt");
            waitForEnter();
        }
        
        //Adding detils
        void addEmployee(void)
		{ 
            system("cls");
            cout<<"\n Enter First Name of Employee: ";
            cin>>name;
            cout<<"\n Enter Employee ID [max 4 digits]: ";
            cin>>id;
            cout<<"\n Enter Designation: ";
            cin>>desig;
            cout<<"\n Enter Employee Age: ";
            cin>>age;
            cout<<"\n Enter Employee CTC: ";
            cin>>ctc;
            cout<<"\n Enter Employee Experience: ";
            cin>>exp;

            char ch;
            cout<<"\nEnter 'y' to save above information\n";
            cin>>ch;
            if(ch=='y'){
                FILE  *file;
                file= fopen("data.txt","a");
                fprintf(file, "%s %s %s %d %d %d \n", name, id, desig, age, ctc, exp );
                fclose(file);
                cout<<"\nNew Employee has been added to database\n";
            }
            else
                addEmployee();
            waitForEnter();
        }

        //Removing records
        void delEmployeeDetails(void)
		{ 
            system("cls");
            char checkId[5];
            cout<<"\n----------------------------------";
            cout<<"\nEnter Employee Id To Remove: ";
            cin>>checkId;
            char ch;
            cout<<"----------------------------------";
            cout<<"\n\n\n\n\nCONFIRMATION\nEnter 'y'\n";
            cin>>ch;
            if(ch=='y'){
                FILE *file, *tempfile;
                file= fopen("data.txt", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &desig[0], &age, &ctc, &exp)!=EOF)
                    if(strcmp(checkId, id)!=0)
                        fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, desig, age, ctc, exp );
                fclose(file);
                fclose(tempfile);
                int isRemoved= remove("data.txt");
                int isRenamed= rename("temp.txt", "data.txt");
                cout<<"\nRecord Removed Successfully\n";
                waitForEnter();
            }
            else
                delEmployeeDetails();
        }


    public:
        // Function to serve as end point
        void optionsList(void)
		{ //menu
            while(true)
			{
                system("cls");

                // Options to choose an action
                cout<<"\n\t\t\t>>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM  <<<<<<<<<";
                cout<<"\n";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   1:   To View List of Employees";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   2:   To View Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   3:   To Modify Existing Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   4:   To Add Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   5:   To Remove an Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   0:   To Exit     ";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\n\t\t\t   Please Enter Your Choice: ";

                // Taking the choice input
                int choice;
                cin>>choice;
                // Calling relevant function as per choice
                switch (choice) 
				{
                    case 0:
                    	system("CLS");
                        cout<<"\n\nEMPLOYEE MANAGEMENT SYSTEM\n\n ";
                        //Sleep(10);
                        return;
                    case 1:
                        listEmployees();
                        break;
                    case 2:
                        showDetails();
                        break;
                    case 3:
                        editExisting();
                        break;
                    case 4:
                        addEmployee();
                        break;
                    case 5:
                        delEmployeeDetails();
                        break;
                    default:
                        cout<<"\n Kindly! Select right option! \n";
                        break;
                }

            }
        }

};

int main()
{
    // Call the optionsList function
    Employee emp;
    emp.optionsList();
    return 0;
}
