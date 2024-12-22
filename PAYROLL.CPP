#include <iostream.h>
#include <conio.h>
#include <string.h>

struct Employee {
    char name[100];
    char designation[100];
    int age;
    float salary;
    float houseRentAllowance;
    float dailyAllowance;
    float providentFund;
    char contact[20]; // Contact field
};

Employee employees[100]; // array to store employees
int numEmployees = 0; // number of employees

void login() {
    char username[50], password[50];
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if(strcmp(username, "kritika") == 0 && strcmp(password, "payroll") == 0) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Invalid username or password. Please try again." << endl;
        login();
    }
}

void input(Employee &emp) {
    cout << "Enter employee name: ";
    cin.ignore(); // To ignore the leftover newline character from previous input
    cin.getline(emp.name, 100); // Allows input with spaces

    cout << "Enter employee designation: ";
    cin.getline(emp.designation, 100); // Allows input with spaces

    cout << "Enter employee age: ";
    cin >> emp.age;
    while(emp.age < 18 || emp.age > 65) {
        cout << "Invalid age. Please enter a value between 18 and 65." << endl;
        cin >> emp.age;
    }
    
    cout << "Enter employee salary: ";
    cin >> emp.salary;
    while(emp.salary < 0) {
        cout << "Invalid salary. Please enter a positive value." << endl;
        cin >> emp.salary;
    }
    
    cout << "Enter house rent allowance: ";
    cin >> emp.houseRentAllowance;
    while(emp.houseRentAllowance < 0) {
        cout << "Invalid house rent allowance. Please enter a positive value." << endl;
        cin >> emp.houseRentAllowance;
    }
    
    cout << "Enter daily allowance: ";
    cin >> emp.dailyAllowance;
    while(emp.dailyAllowance < 0) {
        cout << "Invalid daily allowance. Please enter a positive value." << endl;
        cin >> emp.dailyAllowance;
    }
    
    cout << "Enter provident fund: ";
    cin >> emp.providentFund;
    while(emp.providentFund < 0) {
        cout << "Invalid provident fund. Please enter a positive value." << endl;
        cin >> emp.providentFund;
    }
    
    cout << "Enter contact number: "; // Input for contact
    cin >> emp.contact;
}

void calculateSalary(Employee &emp) {
    float totalAllowances = emp.houseRentAllowance + emp.dailyAllowance + emp.providentFund;
    if(emp.salary < totalAllowances) {
        cout << "Error: Salary is less than total allowances." << endl;
    } else {
        emp.salary -= totalAllowances;
    }
}

void displayIdentityCard(Employee &emp) {
    cout << "*******************************" << endl;
    cout << "   Employee Identity Card" << endl;
    cout << "*******************************" << endl;
    cout << "Name: " << emp.name << endl;
    cout << "Designation: " << emp.designation << endl;
    cout << "Age: " << emp.age << endl;
    cout << "Contact: " << emp.contact << endl; // Display contact
    cout << "*******************************" << endl;
}

void displayTotalEmployees() {
    char designation[50];
    int totalEmployees = 0;
    cout << "Enter designation to display total employees: ";
    cin.ignore(); 
    cin.getline(designation, 50); 
    for(int i = 0; i < numEmployees; i++) {
        if(strcmp(employees[i].designation, designation) == 0) {
            totalEmployees++;
        }
    }
    cout << "Total employees with designation " << designation << ": " << totalEmployees << endl;
}

void displayTotalEmployeeCount() {
    cout << "Total number of employees: " << numEmployees << endl;
}

void displayGrossSalaryByName() {
    char name[100];
    int found = 0;
    cout << "Enter employee name to display gross salary: ";
    cin.ignore(); 
    cin.getline(name, 100); 

    for(int i = 0; i < numEmployees; i++) {
        if(strcmp(employees[i].name, name) == 0) {
            float grossSalary = employees[i].salary + employees[i].houseRentAllowance + employees[i].dailyAllowance + employees[i].providentFund;
            cout << "Gross Salary of " << name << ": " << grossSalary << endl;
            found = 1;
            break;
        }
    }
    if (!found) {
        cout << "Employee with name " << name << " not found." << endl;
    }
}

void displayAllSalaries() {
    if (numEmployees == 0) {
        cout << "No employees available to display." << endl;
    } else {
        for (int i = 0; i < numEmployees; i++) {
            cout << "Name: " << employees[i].name << endl;
            cout << "Designation: " << employees[i].designation << endl;
            cout << "Salary: " << employees[i].salary << endl;
            cout << "------------------------" << endl;
        }
    }
    getch(); 
}

int main() {
    int choice;

    while(1) {
        clrscr();
        cout << "*******************************" << endl;
        cout << "Payroll Management System" << endl;
        cout << "*******************************" << endl;
        cout << "1. Login" << endl;
        cout << "2. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                login();
                while(1) {
                    clrscr();
		    cout << "*******************************" << endl;
                    cout << "Payroll Management System" << endl;
                    cout << "*******************************" << endl;

                    cout << "1. Add Employee" << endl;
                    cout << "2. View identity card of Employees" << endl;
                    cout << "3. View Total Employees by Designation" << endl;
                    cout << "4. View Total Number of Employees" << endl;
                    cout << "5. View Employee salary by their name" << endl;
                    cout << "6. View Employees' designation & their salary" << endl;
                    cout << "7. exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch(choice) {
                        case 1:
                            input(employees[numEmployees]);
                            calculateSalary(employees[numEmployees]);
                            numEmployees++;
                            break;
                        case 2:
                            for(int i = 0; i < numEmployees; i++) {
                                displayIdentityCard(employees[i]);
                                cout << "------------------------" << endl;
                            }
                            getch(); 
                            break;
                        case 3:
                            displayTotalEmployees();
                            getch(); 
                            break;
                        case 4:
                            displayTotalEmployeeCount();
                            getch(); 
                            break;
                        case 5:
                            displayGrossSalaryByName();
                            getch(); 
                            break;
                        case 6:
                            displayAllSalaries(); 
                            break;
                        case 7:
                            goto main_menu; 
                    }
                }
                break; 
            case 2:
                return 0;
        }
        main_menu:; 
    }
    return 0; 
}
