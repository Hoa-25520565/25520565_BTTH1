#include <iostream>
using namespace std;

class phanso{
private:
    int tu,mau;

    /*
    Hàm tìm ước chung lớn nhất của hai số nguyên
    Đầu vào: Hai số nguyên a và b.
    Đầu ra: Ước chung lớn nhất của a và b.
    Giải thích: Hàm sử dụng thuật toán Euclid để tìm ước chung lớn nhất,
    phục vụ cho việc rút gọn phân số.
    */
    int ucln(int a,int b)
    {
        while (b!=0)
        {
            int r=a%b;
            a=b;
            b=r;
        }
        return a;
    }
public:
    /*
    Hàm nhập phân số
    Đầu vào: Tử số và mẫu số được nhập từ bàn phím.
    Đầu ra: Lưu giá trị tử số và mẫu số hợp lệ vào hai biến tu và mau.
    Giải thích: Hàm dùng để nhập một phân số từ bàn phím và kiểm tra
    điều kiện mẫu số phải khác 0. Nếu mẫu số bằng 0 thì yêu cầu nhập lại.
    */
    void nhap()
    {
        cout << "Nhap phan so: ";
        cin >> tu >> mau;
        while (mau==0)
        {
            cout << "Phan so khong hop le, nhap lai: ";
            cin >> tu >> mau;
        }
    }

    /*
    Hàm rút gọn phân số
    Đầu vào: Tử số và mẫu số của phân số.
    Đầu ra: Cập nhật lại tử số và mẫu số sau khi đã rút gọn.
    Giải thích: Hàm sử dụng ước chung lớn nhất để chia cả tử và mẫu
    nhằm đưa phân số về dạng tối giản. Nếu mẫu số âm thì đổi dấu tử
    và mẫu để mẫu số luôn dương.
    */
    void rutgon()
    {
        int r=ucln(tu,mau);
        tu/=r;
        mau/=r;
        if (mau<0)
        {
            tu*=-1;
            mau*=-1;
        }
    }

    /*
    Hàm xuất phân số
    Đầu vào: Phân số đã được lưu trong hai biến tu và mau.
    Đầu ra: In phân số ra màn hình.
    Giải thích: Hàm hiển thị phân số dưới dạng a/b. Nếu tử số bằng 0
    thì chỉ in 0. Nếu mẫu số bằng 1 thì chỉ in tử số.
    */
    void xuat()
    {
        if (tu==0) cout << tu << endl;
        else
        {
            if (mau==1) cout << tu << endl;
            else cout << tu << "/" << mau << endl;
        }
    }

    /*
    Hàm tìm phân số lớn nhất
    Đầu vào: Một phân số a để so sánh với phân số hiện tại(*this).
    Đầu ra: Trả về phân số lớn hơn trong hai phân số.
    Giải thích: Hàm so sánh hai phân số bằng cách nhân chéo
    tử số và mẫu số để xác định phân số nào lớn hơn. Nếu phân số hiện
    tại lớn hơn trả về *this, ngược lại trả về a.
    */
    phanso phansolonnhat(const phanso &a)
    {
        return(tu*a.mau>a.tu*mau ? *this : a);
    }

    /*
    Hàm tính tổng hai phân số
    Đầu vào: Phân số hiện tại và một phân số a.
    Đầu ra: Trả về phân số là tổng của phân số hiện tại và phân số a.
    Giải thích: Hàm thực hiện quy đồng mẫu số để cộng hai phân số
    sau đó rút gọn kết quả.
    */
    phanso tong(const phanso &a)
    {
        phanso b;
        b.tu=tu*a.mau+mau*a.tu;
        b.mau=mau*a.mau;
        b.rutgon();
        return b;
    }

    /*
    Hàm tính hiệu hai phân số
    Đầu vào: Phân số hiện tại và một phân số a.
    Đầu ra: Trả về phân số là hiệu của phân số hiện tại và phân số a.
    Giải thích: Hàm thực hiện quy đồng mẫu số để trừ hai phân số
    sau đó rút gọn kết quả.
    */
    phanso hieu(const phanso &a)
    {
        phanso b;
        b.tu=tu*a.mau-mau*a.tu;
        b.mau=mau*a.mau;
        b.rutgon();
        return b;
    }

    /*
    Hàm tính tích hai phân số
    Đầu vào: Phân số hiện tại và một phân số a.
    Đầu ra: Trả về phân số là tích của hai phân số.
    Giải thích: Hàm nhân tử số với tử số và mẫu số với mẫu số
    của hai phân số rồi rút gọn kết quả.
    */
    phanso tich(const phanso &a)
    {
        phanso b;
        b.tu=tu*a.tu;
        b.mau=mau*a.mau;
        b.rutgon();
        return b;
    }

    /*
    Hàm kiểm tra phân số bằng 0
    Đầu vào: Phân số hiện tại.
    Đầu ra: Trả về true nếu phân số bằng 0, ngược lại trả về false.
    Giải thích: Hàm dùng để kiểm tra nếu tử số bằng 0 thì phân số
    bằng 0 và ngược lại nhằm phục vụ cho việc kiểm tra phép chia phân số.
    */
    bool laphanso0()
    {
        if (tu==0) return true;
        else return false;
    }

    /*
    Hàm tính thương hai phân số
    Đầu vào: Phân số hiện tại và một phân số a.
    Đầu ra: Trả về phân số là thương của phân số hiện tại chia cho phân số a.
    Giải thích: Hàm thực hiện phép chia hai phân số bằng cách nhân phân số
    thứ nhất với nghịch đảo của phân số thứ hai, sau đó rút gọn kết quả.
    */
    phanso thuong(const phanso &a)
    {
        phanso b;
        b.tu=tu*a.mau;
        b.mau=mau*a.tu;
        b.rutgon();
        return b;
    }
};

int main(){
phanso A,B;
A.nhap();
A.rutgon();
cout << "Phan so da rut gon: ";
A.xuat();
B.nhap();
B.rutgon();
cout << "Phan so lon nhat trong 2 phan so: ";
A.phansolonnhat(B).xuat();
cout << "Tong cua 2 phan so: ";
A.tong(B).xuat();
cout << "Hieu cua 2 phan so: ";
A.hieu(B).xuat();
cout << "Tich cua 2 phan so: ";
A.tich(B).xuat();
if (B.laphanso0()) cout << "Khong the chia phan so bang 0";
else
{
    cout << "Thuong cua 2 phan so: ";
    A.thuong(B).xuat();
}
}
