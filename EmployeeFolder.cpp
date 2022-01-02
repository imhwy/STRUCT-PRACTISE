/*Bài 10: Viết chương trình quản lý hồ sơ nhân viên trong một công ty, chương trình
thực hiện những công việc sau:
• Họ và tên.
• Phái.
• Ngày sinh.
• Địa chỉ.
• Lương cơ bản.
• Bảo hiểm xã hội.
• Thưởng.
• Phạt.
• Lương thực lĩnh = Lương cơ bản + Thưởng - Bảo hiểm xã hội - Phạt.
a) Nhập vào hồ sơ của các nhân viên trong công ty.
b) Xuất danh sách các nhân viên theo lương thực lĩnh giảm dần bằng 2
cách sau:
i. Cấp phát vùng nhớ tĩnh.
ii. Cấp phát vùng nhớ động*/

#include <iostream>
#include <string>
struct Folder
{
    std::string name;
    std::string sex;
    int date_of_birth;
    std::string address;
    int salary;
    int BHXH;
    int prize;
    int punishment;
    int true_salary;
    void input(int order = 0)
    {
        if (order == 0)
        {
            std::cout << "You haven't sign up for any employee!!!";
        }
        else
        {
            std::cout << "You are sign up for the " << order << " employee: " << std::endl;
            std::cout << "Date of birth: ";
            std::cin >> date_of_birth;
            std::cout << "Salary: ";
            std::cin >> salary;
            std::cout << "BHXH: ";
            std::cin >> BHXH;
            std::cout << "Prize: ";
            std::cin >> prize;
            std::cout << "Punishment: ";
            std::cin >> punishment;
            std::cout << "True salary: ";
            true_salary = salary + prize - BHXH - punishment;
            std::cin.ignore();
            std::cout << "Name: ";
            getline(std::cin, name);
            std::cout << "Sex: ";
            getline(std::cin, sex);
            std::cout << "Address: ";
            getline(std::cin, address);
        }
    }
    void output(int order)
    {
        std::cout << "The information of the " << order << " employee" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Sex: " << sex << std::endl;
        std::cout << "Date of birth: " << date_of_birth << std::endl;
        std::cout << "Address: " << address << std::endl;
        std::cout << "Salary: " << salary << std::endl;
        std::cout << "BHXH: " << BHXH << std::endl;
        std::cout << "Prize: " << prize << std::endl;
        std::cout << "Punishment: " << punishment << std::endl;
    }
};
// way of static  memory allowcation
Folder hoanvi(Folder &a, Folder &b)
{
    Folder danh = a;
    a = b;
    b = danh;
}
void insert_static(Folder *employee, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (employee[i].true_salary > employee[j].true_salary)
                hoanvi(employee[i], employee[j]);
}
// way of dynamic memory allowcation
Folder swap(Folder *a, Folder *b)
{
    Folder danh = *a;
    *a = *b;
    *b = danh;
}
void insert_dynamic(Folder *employee, int *n)
{
    Folder *employee_1 = new Folder[*n];
    employee_1 = employee;
    for (int i = 0; i < *(n - 1); i++)
        for (int j = i + 1; j < *n; j++)
            if (employee_1[i].true_salary > employee_1[j].true_salary)
                swap(&employee_1[i], &employee_1[j]);
}
int main()
{
    Folder employee[100];
    int n;
    std::cout << "Enter the amount of the employee: ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        employee[i].input(i + 1);
        std::cout << std::endl;
    }
    for (int i = 0; i < n; i++)
    {
        employee[i].output(i + 1);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "way of static  memory allowcation:" << std::endl;
    insert_static(employee, n);
    for (int i = 0; i < n; i++)
    {
        employee[i].output(i + 1);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "way of dynamic memory allowcation" << std::endl;
    insert_dynamic(employee, &n);
    for (int i = 0; i < n; i++)
    {
        employee[i].output(i + 1);
        std::cout << std::endl;
    }
}