#include "NhanVien.h"
#include <iomanip>
NhanVien::NhanVien(string ma_nv, string ten_nv, Date ngay_nhan_viec, bool gioi_tinh, double luong)
    : ma_nv(ma_nv), ten_nv(ten_nv), ngay_nhan_viec(ngay_nhan_viec), gioi_tinh(gioi_tinh), luong(luong)
{
}
NhanVien::~NhanVien() {}

string NhanVien::getMaNV()
{
    return this->ma_nv;
}
string NhanVien::getTenNV()
{
    return this->ten_nv;
}
Date NhanVien::getNgayNhanViec()
{
    return this->ngay_nhan_viec;
}
double NhanVien::getLuong()
{
    return this->luong;
}
bool NhanVien::getGioiTinh()
{
    return this->gioi_tinh;
}
 NhanVien &NhanVien::operator=(const NhanVien &nv){
    this->ma_nv = nv.ma_nv;
    this->ten_nv = nv.ten_nv;
    this->ngay_nhan_viec = nv.ngay_nhan_viec;
    this->gioi_tinh =nv.gioi_tinh;
    this->luong = nv.luong;
    return *this;
}
void NhanVien::show(){
    cout << this->ma_nv << setw(5) << this->ten_nv << setw(20) << this->ngay_nhan_viec << setw(15) << this->gioi_tinh << setw(5) << to_string(this->luong)<< endl;
}