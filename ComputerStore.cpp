#include <iostream>
#include <string>
struct Computer_Store
{
    std::string loai_may;
    std::string noi_san_xuat;
    int thoi_gian_bh;
    void input(int order)
    {
        if (order == 0)
        {
            std::cout << "👉🏻Ban khong nhap vao thong tin gi ca👈🏻";
        }
        else
        {
            std::cout << "Ban dang nhap vao thong tin cua may tinh thu: " << order << std::endl;
            std::cout << "Thoi gian bao hanh: ";
            std::cin >> thoi_gian_bh;
            std::cin.ignore();
            std::cout << "Loai may: ";
            getline(std::cin, loai_may);
            std::cout << "Noi san xuat: ";
            getline(std::cin, noi_san_xuat);
        }
    }
    void output(int order)
    {
        std::cout << "Thong tin cua may tinh thu: " << order << std::endl;
        std::cout << "Loai may: " << loai_may << std::endl;
        std::cout << "Noi san xuat: " << noi_san_xuat << std::endl;
        std::cout << "Thoi gian bao hanh: " << thoi_gian_bh << std::endl;
    }
};
int thongke_baohanh(Computer_Store *Store_1, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (Store_1[i].thoi_gian_bh == 1)
        {
            count++;
        }
    }
    return count;
}
void find_place(Computer_Store *Store_1, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (Store_1[i].noi_san_xuat == "my")
        {
            Store_1[i].output(i + 1);
            std::cout<<std::endl;
        }
    }
}
//this is main function.
int main()
{
    Computer_Store Store_1[100];
    int n;
    std::cout << "Nhap vao so may: ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        Store_1[i].input(i + 1);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++)
    {
        Store_1[i].output(i + 1);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Tong so may co bao hanh la mot nam: " << thongke_baohanh(Store_1, n) << std::endl;
    std::cout << std::endl;
    std::cout << "Danh sach cac loai may co xuat xu tu My: " << std::endl;
    find_place(Store_1, n);
}
