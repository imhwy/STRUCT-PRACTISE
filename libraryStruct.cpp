#include <iostream>
#include <string>
struct LIBRARY_STRUCT
{
    int MaSSach;
    std::string TenSach;
    std::string TacGia;
    int SL;
    void input(int order)
    {
        if (order == 0)
        {
            std::cout << "Ban khong nhap vao cuon sach nao ca: ";
        }
        else
        {
            std::cout << "Ban dang thuc hien nhap vao sach thu: " << order << std::endl;
            std::cout << "Nhap vao ma so sach: ";
            std::cin >> MaSSach;
            std::cout << "Nhap vao so luong: ";
            std::cin >> SL;
            std::cin.ignore();
            std::cout << "Nhap vao ten sach: ";
            getline(std::cin, TenSach);
            std::cout << "Nhap vao tac gia: ";
            getline(std::cin, TacGia);
        }
    }
    void output()
    {
        std::cout << "Thong tin sach: " << std::endl;
        std::cout << "Ma so sach: " << MaSSach << std::endl;
        std::cout << "Ten sach: " << TenSach << std::endl;
        std::cout << "Tac Gia: " << TacGia << std::endl;
        std::cout << "So luong: " << SL << std::endl;
    }
};
void name_of_book(LIBRARY_STRUCT *libraries, int n, std::string name)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (libraries[i].TenSach == name)
        {
            libraries[i].output();
        }
        else
        {
            count++;
        }
    }
    if (count == n)
    {
        std::cout << "Khong tim thay";
    }
}
int sum_of_books(LIBRARY_STRUCT *libraries, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + libraries[i].SL;
    }
    return sum;
}
int main()
{
    LIBRARY_STRUCT libraries[100];
    int n;
    std::string name;
    std::cout << "Nhap vao so luong sach ban muon nhap: ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        libraries[i].input(i + 1);
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++)
    {
        libraries[i].output();
    }
    std::cout << std::endl;
    std::cout << "nhap vao ten sach ban muon tim kiem: " << std::endl;
    getline(std::cin, name);
    std::cout << "Ket qua sach ma ban tim kiem la: " << std::endl;
    name_of_book(libraries, n, name);
    std::cout << std::endl;
    std::cout << "Tong tat ca nhung cuon sach trong thu vien: " << sum_of_books(libraries, n);
} 
