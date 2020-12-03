#include "NhanVien.h"
class NVHD : public NhanVien
{
protected:
  double luong_ngay;

public:
  NVHD(double = 150000);
  ~NVHD();
  double tinhLuong();
  friend istream &operator>>(istream &, NVHD &);
  friend ostream &operator<<(ostream &, const NVHD &);
};