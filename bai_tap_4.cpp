#include <iostream>
using namespace std;

class ngaythangnam
{
private:
    int ngay,thang,nam;

    /*
    Hàm kiểm tra năm nhuận
    Đầu vào: Năm y.
    Đầu ra: Trả về true nếu năm y là năm nhuận, ngược lại trả về false.
    Giải thích: Hàm dùng để xác định một năm có phải năm nhuận hay không dựa theo quy tắc chia hết cho 4 nhưng không chia hết cho 100,
    hoặc chia hết cho 400.
    */
    bool lanamnhuan(int y)
    {
        if ((y%4==0 && y%100!=0) || y%400==0) return true;
        else return false;
    }

    /*
    Hàm xác định số ngày trong một tháng
    Đầu vào: Tháng m và năm y.
    Đầu ra: Trả về số ngày của tháng m trong năm y.
    Giải thích: Hàm dùng để xác định số ngày của từng tháng trong năm, trong đó tháng 2 sẽ có 28 hoặc 29 ngày tùy theo năm nhuận.
    */
    int ngaytrongthang(int m,int y)
    {
        switch(m)
        {
            case 4: case 6: case 9: case 11: return 30;
            case 2: return lanamnhuan(y) ? 29 : 28;
            default: return 31;
        }
    }
public:

    /*
    Hàm nhập ngày tháng năm
    Đầu vào: Ngày, tháng, năm được nhập từ bàn phím.
    Đầu ra: Lưu các giá trị hợp lệ vào các biến ngay, thang, nam.
    Giải thích: Hàm dùng để nhập một ngày tháng năm từ bàn phím và kiểm tra tính hợp lệ của ngày đó.
    Nếu ngày không hợp lệ thì yêu cầu người dùng nhập lại.
    */
    void nhap()
    {
        cout << "Nhap ngay: ";
        cin >> ngay >> thang >> nam;
        while (thang>12 || thang<1 || ngay<1 || ngay>ngaytrongthang(thang,nam))
        {
            cout << "Ngay khong hop le, nhap lai: ";
            cin >> ngay >> thang >> nam;
        }
    }

    /*
    Hàm xuất ngày tháng năm
    Đầu vào: Ngày, tháng, năm đã được lưu trong các biến của lớp.
    Đầu ra: In ngày kế tiếp ra màn hình.
    Giải thích: Hàm dùng để hiển thị kết quả ngày kế tiếp sau khi đã thực hiện tính toán.
    */
    void xuat()
    {
        cout << "Ngay ke tiep: " << ngay << "/" << thang << "/" << nam << endl;
    }

    /*
    Hàm tính ngày kế tiếp
    Đầu vào: Ngày, tháng, năm hiện tại.
    Đầu ra: Cập nhật lại các giá trị ngay, thang, nam thành ngày kế tiếp.
    Giải thích: Hàm thực hiện tăng ngày lên 1 đơn vị. Nếu ngày vượt quá số ngày tối đa của tháng
    thì chuyển sang ngày đầu của tháng tiếp theo. Nếu tháng vượt quá 12 thì chuyển sang tháng 1 của năm tiếp theo.
    */
    void ngayketiep()
    {
        ngay++;
        if (ngay>ngaytrongthang(thang,nam))
        {
            ngay=1;
            thang++;
            if (thang>12)
            {
                thang=1;
                nam++;
            }
        }
    }
};

int main(){
ngaythangnam A;
A.nhap();
A.ngayketiep();
A.xuat();
}
