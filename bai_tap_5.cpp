#include <iostream>
#include <string>
using namespace std;

class diem
{
private:
    string hoten;
    float diemtoan,diemvan,dtb;
public:

    /*
    Hàm nhập thông tin học sinh
    Đầu vào: Họ tên học sinh, điểm Toán và điểm Văn được nhập từ bàn phím.
    Đầu ra: Lưu các giá trị đã nhập vào các biến hoten, diemtoan và diemvan.
    Giải thích: Hàm dùng để nhập thông tin của một học sinh gồm họ tên, điểm Toán và điểm Văn.
    */
    void nhap()
    {
        cout << "Nhap ho ten: ";
        getline(cin,hoten);
        cout << "Nhap diem Toan: ";
        cin >> diemtoan;
        cout << "Nhap diem Van: ";
        cin >> diemvan;
    }

    /*
    Hàm tính điểm trung bình
    Đầu vào: Điểm Toán và điểm Văn đã được lưu trong các biến diemtoan và diemvan.
    Đầu ra: Giá trị điểm trung bình được lưu vào biến dtb.
    Giải thích: Hàm thực hiện tính toán điểm trung bình của học sinh dựa trên điểm hai môn Toán và Văn.
    */
    void tinhdtb()
    {
        dtb=(diemtoan+diemvan)/2;
    }

    /*
    Hàm xuất thông tin học sinh
    Đầu vào: Các thông tin của học sinh gồm họ tên, điểm Toán, điểm Văn và điểm trung bình.
    Đầu ra: In thông tin học sinh và điểm trung bình ra màn hình.
    Giải thích: Hàm dùng để hiển thị toàn bộ thông tin của học sinh sau khi đã tính điểm trung bình.
    */
    void xuat()
    {
        cout << "Ho ten: " << hoten << endl;
        cout << "Diem Toan: " << diemtoan << endl;
        cout << "Diem Van: " << diemvan << endl;
        cout << "Diem trung binh: " << dtb;
    }
};

int main(){
diem A;
A.nhap();
A.tinhdtb();
A.xuat();
}
