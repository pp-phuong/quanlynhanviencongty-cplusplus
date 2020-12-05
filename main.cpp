#include "QLNV.cpp"
NVBC nvbc;
NVHD nvhd;
void Menu(QLNV<NhanVien> &data)
{
  cout << "______________________Quan ly nhan vien cong ty_________________________" << endl
       << "                       1. Them nhan vien" << endl
       << "                       2. Chinh sua nhan vien " << endl
       << "                       3. Xoa nhan vien " << endl
       << "                       4. Xem tat ca nhan vien" << endl
       << "                       5. Xem nhan vien hop dong " << endl
       << "                       6. Xem nhan vien bien che " << endl
       << "                       7. So nhan vien hien tai " << endl
       << "                       PRESS THE NUMBER : ";
  int m;
  cin >> m;
  switch (m)
  {
  case 1:
    cout << "______________________Them nhan vien_________________________" << endl
         << "                       1. Nhan vien Bien che (NVBC)" << endl
         << "                       2. Nhan vien Hop dong (NVHD)" << endl
         << "                       PRESS THE NUMBER : ";
    int case1;
    NhanVien *a;
    cin >> case1;
    switch (case1)
    {
    case 1:
      cout << "Nhap thong tin nhan vien:" << endl;
      cin >> nvbc;
      a = &nvbc;
      break;
    case 2:
      cout << "Nhap thong tin nhan vien:" << endl;
      cin >> nvhd;
      a = &nvhd;
      break;
    default:
      cout << " Sorry,There is no matching option " << endl;
      break;
    }
    cout << "______________________Them nhan vien_________________________" << endl
         << "                       1. Them vao dau danh sach" << endl
         << "                       2. Them vao cuoi danh sach" << endl
         << "                       3. Them vao vi tri k " << endl
         << "                       PRESS THE NUMBER : ";
    int case1_1;
    cin >> case1_1;
    switch (case1_1)
    {
    case 1:
      data.InsertFirst(a);
      data.Xuat();
      break;
    case 2:
      data.InsertLast(a);
      data.Xuat();
      break;
    case 3:
      data.Xuat();
      cout << "Nhap STT muon chen vao:";
      int index;
      cin >> index;
      data.Insert(a, index);
      data.Xuat();
      break;
    default:
      cout << " Sorry,There is no matching option " << endl;
      break;
    }
    /*cout << mv;*/
    break;
  case 2:
    break;
  case 3:
    int remove;
    cout << "Nhap stt nhan vien can xoa :";
    cin >> remove;
    data.Remove(remove);
    data.Xuat();
    break;
  case 4:
    data.Xuat();
    break;
  case 5:
    break;
  default:
    cout << " Sorry,There is no matching option " << endl;
    break;
  }
}
int main()
{
  QLNV<NhanVien> data;
  NVBC nv1("1", "Tran Thi Phuong", Date(1, 1, 2018), 1, 1000000, 5);

  char key;
  do
  {
    Menu(data);
    cout << "Do you want to be continute? y/n ";
    cin >> key;
  } while (key != 'n');
  // NhanVien *a;
  // a = &nv4;
  return 0;
}