#include <iostream>
#include <string>
using namespace std;
struct VIDEO
{
    string film_name;
    string kind;
    string director_name;
    string actor_name;
    string actress_name;
    string year;
    string source_name;
    void input(int order = 0)
    {
        if (order == 0)
        {
            cout << "Ban khong nhap vao bo phim nao ca: ";
        }
        else
        {
            cout << "Ban dang nhap vao bo phim thu: " << order << endl;
            cout << "Nam san xuat: ";
            cin >> year;
            cin.ignore();
            cout << "Ten Phim: ";
            getline(cin, film_name);
            cout << "The loai: ";
            getline(cin, kind);
            cout << "Ten dao dien: ";
            getline(cin, director_name);
            cout << "Ten dien vien nam chinh: ";
            getline(cin, actor_name);
            cout << "ten dien vien nu chinh: ";
            getline(cin, actress_name);
            cout << "Ten hang san xuat: ";
            getline(cin, source_name);
        }
    }
    void output(int order)
    {
        cout << "Thong tin ve bo phim thu: " << order << endl;
        cout << "Ten phim: " << film_name << endl;
        cout << "The loai: " << kind << endl;
        cout << "Ten dao dien: " << director_name << endl;
        cout << "Ten dien vien nam chinh: " << actor_name << endl;
        cout << "Ten dien vien nu chinh: " << actress_name << endl;
        cout << "Nam san xuat: " << year << endl;
        cout << "Hang san xuat: " << source_name << endl;
    }
};
void find_kind_of_film(VIDEO *vid, int n, string theloai)
{
    for (int i = 0; i < n; i++)
    {
        if (vid[i].kind == theloai)
        {
            vid[i].output(i + 1);
        }
    }
}
void find_actor(VIDEO *vid, int n, string tendienvien)
{
    for (int i = 0; i < n; i++)
    {
        if (vid[i].actor_name == tendienvien)
        {
            vid[i].output(i + 1);
        }
    }
}
void find_director(VIDEO *vid, int n, string tendaodien)
{
    for (int i = 0; i < n; i++)
    {
        if (vid[i].director_name == tendaodien)
        {
            vid[i].output(i + 1);
        }
    }
}
int main()
{
    VIDEO vid[100];
    int n;
    string theloai, tendienvien, tendaodien;
    cout << "Nhap vao so bo phim: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vid[i].input(i + 1);
        cout << "Da nhap thanh cong thong tin bo phim thu: " << i << endl;
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        vid[i].output(i + 1);
        cout << endl;
    }
    cout << endl;
    cout << "Nhap vao the loai phim muon tim: ";
    getline(cin, theloai);
    cout << endl;*/
    cout << "Nhap vao ten nam dien vien dong phim: ";
    getline(cin, tendienvien);
    cout << endl;
    /*cout << "Nhap vao ten dao dien: ";
    getline(cin, tendaodien);
    cout << endl;*/
    /*find_kind_of_film(vid, n, theloai);*/
    find_actor(vid, n, tendienvien);
    /*find_director(vid, n, tendaodien);*/
}
