#include "QLNV.cpp"
int main()
{
  QLNV<NhanVien> data; 
  NVBC nv1;
  // NVBC nv2;
  NVBC nv3("1","Phuong",Date(1,1,2020), 1.0, 1000000.0,2.0);
   data.Insert(nv3,0);
  cin >> nv1;
  // cout << "Nhap nv 2:" << endl;
  // cin >> nv2;
  // cout << nv1;
  data.Insert(nv1,0);
  // data.Insert(nv2,1);
 
  data.Xuat();
  return 0;
}