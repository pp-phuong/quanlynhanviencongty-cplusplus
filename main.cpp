#include "QLNV.cpp"
NVBC nvbc;
NVHD nvhd;
int main()
{
  QLNV<NhanVien> data;
  // NVBC nv1("1", "Tran Thi Phuong", Date(1, 1, 2018), 1, 1000000, 5);
  // NVBC nv2("2", "Tran Thi Phuong", Date(1, 1, 2018), 1, 1000000, 5);
  // NVBC nv3("3", "Tran Thi Phuong", Date(1, 1, 2018), 1, 1000000, 5);
  // NVBC nv4("4", "Tran Thi Phuong", Date(1, 1, 2018), 1, 1000000, 5);
  // data.InsertFirst(&nv1);
  // data.InsertLast(&nv2);
  // data.InsertLast(&nv3);
  // data.InsertLast(&nv4);
  // data.InsertLast(&nv1);
  // data.Xuat();
  // data.Remove(1);
  // data.Xuat();
  char key;
  do
  {
    cout << "______________________Quan ly nhan vien cong ty_________________________" << endl
         << "                       1. Them nhan vien" << endl
         << "                       2. Chinh sua nhan vien " << endl
         << "                       3. Xoa nhan vien " << endl
         << "                       4. Xem tat ca nhan vien" << endl
         << "                       5. So nhan vien hien tai " << endl
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
      cin >> case1;
      switch (case1)
      {
      case 1:
        cout << "Nhap thong tin nhan vien:" << endl;
        cin >> nvbc;
        data.InsertLast(&nvbc);
        data.Xuat();
        break;
      case 2:
        cout << "Nhap thong tin nhan vien:" << endl;
        cin >> nvhd;
        data.InsertLast(&nvhd);
        data.Xuat();
        break;
      default:
        cout << " Sorry,There is no matching option " << endl;
        break;
      }
      break;
    case 2:
      int update;
      data.Xuat();
      cout << " Nhap STT nhan vien can chinh sua : " ;
      cin >> update;
      data.Update(update);
      data.Xuat();
      break;
    case 3:
      data.Xuat();
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
      cout << "So nhan vien hien tai : " << data.GetLength() << endl;
      break;
    default:
      cout << " Sorry,There is no matching option " << endl;
      break;
    }
    cout << "Do you want to be continute? y/n ";
    cin >> key;
  } while (key != 'n');
  // NhanVien *a;
  // a = &nv4;
  return 0;
}