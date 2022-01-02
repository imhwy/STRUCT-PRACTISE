/*Bài 9: Một cửa hàng cần quản lý các mặt hàng, thông tin một mặt hàng bao gồm:
• Mã hàng.
• Tên mặt hàng.
• Số lượng.
• Đơn giá.
• Số lượng tồn.
• Thời gian bảo hành (tính theo đơn vị tháng).
a) Hãy nhập vào một danh sách các mặt hàng.
b) Tìm mặt hàng có số lượng tồn nhiều nhất.
c) Tìm mặt hàng có số lượng tồn ít nhất.
d) Tìm mặt hàng có giá tiền cao nhất.
e) In ra những mặt hàng có thời gian bảo hành lớn hơn 12 tháng.
f) Sắp xếp các mặt hàng theo thứ tự tăng dần của số lượng tồn*/

#include <iostream>
#include <string>
struct Store
{
    std::string ma_hang;
    std::string ten_hang;
    int so_luong;
    long long int don_gia;
    int so_luong_ton;
    int thoi_gian_bao_hanh;
    void input(int order = 0)
    {
        if (order == 0)
        {
            std::cout << "👉🏻Ban khong nhap vao mat hang nao ca👈🏻" << std::endl;
        }
        else
        {
            std::cout << "Dang nhap vao mat hang thu: " << order << std::endl;
            std::cout << "Nhap vao so luong: ";
            std::cin >> so_luong;
            std::cout << "Nhap vao don gia: ";
            std::cin >> don_gia;
            std::cout << "Nhap vao so luong ton: ";
            std::cin >> so_luong_ton;
            std::cout << "Nhap vao thoi gian bao hanh: ";
            std::cin >> thoi_gian_bao_hanh;
            std::cin.ignore();
            std::cout << "Nhap vao ma hang: ";
            getline(std::cin, ma_hang);
            std::cout << "Nhap vao ten hang: ";
            getline(std::cin, ten_hang);
        }
    }
    void output(int order)
    {
        std::cout << "Thong tin mat hang thu: " << order << std::endl;
        std::cout << "Ma hang: " << ma_hang << std::endl;
        std::cout << "Ten hang: " << ten_hang << std::endl;
        std::cout << "So luong: " << so_luong << std::endl;
        std::cout << "Don gia: " << don_gia << std::endl;
        std::cout << "So luong ton: " << so_luong_ton << std::endl;
        std::cout << "Thoi gian bao hanh: " << thoi_gian_bao_hanh << std::endl;
    }
};
Store find_max_SLT(Store *STO_1, int n)
{
    Store max = STO_1[0];
    for (int i = 0; i < n; i++)
    {
        if (STO_1[i].so_luong_ton > max.so_luong_ton)
        {
            max = STO_1[i];
        }
    }
    return max;
}
Store find_min_SLT(Store *STO_1, int n)
{
    Store min = STO_1[0];
    for (int i = 0; i < n; i++)
    {
        if (STO_1[i].so_luong_ton < min.so_luong_ton)
        {
            min = STO_1[i];
        }
    }
    return min;
}
Store find_max_price(Store *STO_1, int n)
{
    Store max_price = STO_1[0];
    for (int i = 0; i < n; i++)
    {
        if (STO_1[i].don_gia > max_price.don_gia)
        {
            max_price = STO_1[i];
        }
    }
    return max_price;
}
void find_bao_hanh(Store *STO_1, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (STO_1[i].thoi_gian_bao_hanh > 12)
        {
            STO_1[i].output(i + 1);
            std::cout << std::endl;
        }
    }
}
void swap(Store *a, Store *b)
{
    Store danh = *a;
    *a = *b;
    *b = danh;
}
void insert(Store *STO_1, int n)
{
    Store *STO_2 = new Store[n];
    STO_2 = STO_1;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (STO_2[i].so_luong_ton > STO_2[j].so_luong_ton)
                swap(&STO_2[i], &STO_2[j]);
}
int main()
{
    Store STO_1[100];
    int n;
    std::cout << "Nhap vao so mat hang: ";
    std::cin >> n;
    std::cout << std::endl;
    for (int i = 0; i < n; i++)
    {
        STO_1[i].input(i + 1);
        std::cout << std::endl;
    }
    for (int i = 0; i < n; i++)
    {
        STO_1[i].output(i + 1);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Ten Mat hang co so luong ton nhieu nhat: " << find_max_SLT(STO_1, n).ten_hang << std::endl;
    std::cout << std::endl;
    std::cout << "Ten mat hang co so luong ton it nhat: " << find_min_SLT(STO_1, n).ten_hang << std::endl;
    std::cout << std::endl;
    std::cout << "Ten mat hang co gia tien cao nhat: " << find_max_price(STO_1, n).ten_hang << std::endl;
    std::cout << std::endl;
    std::cout << "Danh sach co so thang bao hanh lon hon 12: " << std::endl;
    find_bao_hanh(STO_1, n);
    std::cout << std::endl;
    std::cout << "Sap xep cac mat hang theo thu tu tang dan cua so luong ton: " << std::endl;
    insert(STO_1, n);
    for (int i = 0; i < n; i++)
    {
        STO_1[i].output(i + 1);
        std::cout << std::endl;
    }
}