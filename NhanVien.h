#include <iostream>
#include <iomanip>
#include "Date.h"
#include <string>
#pragma once
using namespace std;
class NhanVien{
  protected:
    string ma_nv;
    string ten_nv;
    Date ngay_nhan_viec;
    bool gioi_tinh;
    double luong;
  public:
    NhanVien(string = "0", string ="name", Date = Date(1,1,2020), bool = 1, double = 1000000);
    ~NhanVien();
    virtual string getMaNV();
    virtual string getTenNV();
    virtual Date getNgayNhanViec();
    virtual bool getGioiTinh();
    virtual double getLuong();
    virtual void show();
    virtual void update();
    NhanVien &operator=(const NhanVien &);
};