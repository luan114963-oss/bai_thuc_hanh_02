#include <iostream>
#include <string>
using namespace std;
struct sinhvien {
    string hoten;
    string msv;
    float diem1;
    float diem2;
    float diem3;
};
int main()
{
    int n;
    cout << "Nhập số lượng sinh viên: ";
    cin >> n;
    sinhvien* ds = new sinhvien[n];
    for (int i = 0; i < n; i++) {
        cin.ignore();
        cout << "họ tên: ";
        getline(cin, (ds + i)->hoten);
        cout << "mã sinh viên: ";
        getline(cin, (ds + i)->msv);
        cout << "Điểm 1: ";
        cin>> (ds + i)->diem1;
        cout << "Điểm 2: ";
        cin>> (ds + i)->diem2;
        cout << "Điểm 3: ";
        cin>> (ds + i)->diem3;
    }
    cout << "======DANH SÁCH SINH VIÊN======" << endl;
    for (int i = 0; i < n; i++) {
        cout << "STT: " << i + 1
            << " | mã sinh viên: " << (ds + i)->msv
            << " | họ tên: " << (ds + i)->hoten
            << " | điểm 1: " << (ds + i)->diem1
            << " | điểm 2: " << (ds + i)->diem2
            << " | điểm 3: " << (ds + i)->diem3 << endl;
    }
}
