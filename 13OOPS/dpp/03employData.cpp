#include <iostream>
#include <vector>
#include <algorithm> // For std::max_element

using namespace std;

class Employee {
private:
    string name;
    int employeeID;
    double salary;
public:
    Employee(string n, int id, double sal) : name(n), employeeID(id), salary(sal) {}
    
    // Display function
    void display() const {
        cout << "Name: " << name << ", Employee ID: " << employeeID << ", Salary: " << salary << endl;
    }

    double getSalary() const {
        return salary;
    }
};

// Function to calculate the average salary of all employees
double averageSalary(const vector<Employee>& employees) {
    double totalSalary = 0;
    for (const auto& emp : employees) {
        totalSalary += emp.getSalary();
    }
    return employees.empty() ? 0 : totalSalary / employees.size();
}

// Function to find the employee with the maximum salary
Employee maxSalary(const vector<Employee>& employees) {
    auto maxSalaryEmployee = max_element(employees.begin(), employees.end(), [](const Employee& emp1, const Employee& emp2) {
        return emp1.getSalary() < emp2.getSalary();
    });

    if (maxSalaryEmployee != employees.end()) {
        return *maxSalaryEmployee;
    }

    // Return a default Employee if no employee is found (shouldn't occur in practice with non-empty vector)
    return Employee("", -1, 0);
}

int main() {
    // Create 5 Employee objects
    vector<Employee> employees = {
        {"John", 101, 50000},
        {"Alice", 102, 60000},
        {"Bob", 103, 55000},
        {"Emily", 104, 62000},
        {"David", 105, 58000}
    };

    // Display characteristics of each employee
    cout << "Details of all employees:\n";
    for (const auto& emp : employees) {
        emp.display();
    }

    // Calculate and display average salary
    cout << "Average salary of all employees: " << averageSalary(employees) << endl;

    // Find and display employee with maximum salary
    cout << "Employee with maximum salary:\n";
    maxSalary(employees).display();

    return 0;
}
