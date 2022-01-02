#include <iostream>
#include <string>
using namespace std;
struct SINHVIEN
{
    int MSSV;
    string name;
    string date;
    float toan;
    float ly;
    float hoa;
    float DTB;
    void input(int order = 0)
    {
        if (order == 0)
        {
            cout << "ban khong nhap vao sinh vien nao ca" << endl;
        }
        else
        {
            cout << "Ban dang thuc hien quy trinh nhap vao sinh vien thu " << order << endl;
            cout << "Nhap vao MSSV: ";
            cin >> MSSV;
            cout << "Nhap vao diem toan ";
            cin >> toan;
            cout << "Nhap vao diem ly: ";
            cin >> ly;
            cout << "Nhap vao diem hoa: ";
            cin >> hoa;
            cout << "Nhap vao diem trung binh: ";
            cin >> DTB;
            cin.ignore();
            cout << "Nhap vao ten sinh vien: ";
            getline(cin, name);
            cout << "Nhap vao nam sinh: ";
            getline(cin, date);
        }
    }
    void output(int order)
    {
        cout << "Thong tin sinh vien thu " << order << endl;
        cout << "MSSV: " << MSSV << endl;
        cout << "Ten sinh vien: " << name << endl;
        cout << "Nam sinh: " << date << endl;
        cout << "Diem toan: " << toan << endl;
        cout << "Diem ly: " << ly << endl;
        cout << "Diem hoa: " << hoa << endl;
        cout << "Diem trung binh: " << DTB << endl;
    }
};
string find_max_dtb(SINHVIEN STU[], int n)
{
    int max = STU[0].DTB;
    string NAME = STU[0].name;
    for (int i = 0; i < n; i++)
    {
        if (STU[i].DTB > max)
        {
            max = STU[i].DTB;
            NAME = STU[i].name;
        }
    }
    return NAME;
}
void hoanvi(SINHVIEN &a, SINHVIEN &b)
{
    SINHVIEN danh = a;
    a = b;
    b = danh;
}
void insert(SINHVIEN *STU, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (STU[i].DTB > STU[j].DTB)
                hoanvi(STU[i], STU[j]);
}
void insert1(SINHVIEN *STU, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (STU[i].toan < STU[j].toan)
                hoanvi(STU[i], STU[j]);
}
SINHVIEN find_sinhvien(SINHVIEN *STU, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (STU[i].DTB > 5 && STU[i].toan >= 3 && STU[i].ly >= 3 && STU[i].hoa >= 3)
        {
            STU[i].output(i + 1);
        }
    }
}
SINHVIEN find_student(SINHVIEN *STU, int n, string NAME)
{
    for (int i = 0; i < n; i++)
    {
        if (STU[i].name == NAME)
        {
            STU[i].output(i + 1);
        } 
    }
}
int main()
{
    SINHVIEN STU[100];
    int n;
    cout << "Nhap vao so sinh vien: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        STU[i].input(i + 1);
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        STU[i].output(i + 1);
        cout << endl;
    }
    cout << "Sinh vien diem trung binh cao nhat la: ";
    cout << find_max_dtb(STU, n);
    cout << endl;
    cout << "Danh sach sinh vien duoc xep theo DTB ";
    insert(STU, n);
    for (int i = 0; i < n; i++)
    {
        STU[i].output(i + 1);
        cout << endl;
    }
    cout << "Danh sach sinh vien duoc xep theo diem toan: ";
    insert1(STU, n);
    for (int i = 0; i < n; i++)
    {
        STU[i].output(i + 1);
        cout << endl;
    }
    cout << endl;
    cout << "In ra sinh vien co DTB lon hon 5 va cac mon tren 3" << endl;
    find_sinhvien(STU, n);
    cout << endl;
    string NAME;
    cout << "Nhap vao ten sinh vien muon tra cuu: " << endl;
    getline(cin, NAME);
    find_student(STU, n, NAME);
}
