#include "QLNV.cpp"

int main()
{
  QLNV<NhanVien> data;
  NVBC nvbc[100];
  NVHD nvhd[100];
  int bc = 0,hd= 0;
  // NVBC nv1("1", "Tran Thi Phuong", Date(1, 1, 2019), 1, 1000000, 5);
  // NVBC nv2("2", "Tran Thi Phuong", Date(1, 1, 2020), 1, 1000000, 5);
  // NVBC nv3("3", "Tran Thi Phuong", Date(1, 1, 2018), 1, 1000000, 5);
  // NVBC nv4("4", "Tran Thi Phuong", Date(1, 1, 2018), 1, 1000000, 5);
  //   NVBC nv5("5", "Tran Thi Phuong", Date(4, 1, 2018), 1, 1000000, 5);
  // data.InsertFirst(&nv1);
  // data.InsertLast(&nv2);
  // data.InsertLast(&nv3);
  // data.InsertLast(&nv4);
  //  data.InsertLast(&nv5);
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
         << "                       6. Sap xep nhan vien theo ngay nhan viec " << endl
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
      NhanVien *a;
      switch (case1)
      {
      case 1:
        cout << "Nhap thong tin nhan vien:" << endl;
        cin >> nvbc[bc];
        a = &nvbc[bc];
        bc++;
        break;
      case 2:
        cout << "Nhap thong tin nhan vien:" << endl;
        cin >> nvhd[hd];
        a = &nvhd[hd];
        hd++;
        break;
      default:
        cout << " Sorry,There is no matching option " << endl;
        break;
      }
      data.InsertLast(a);
      data.Xuat();
      a = nullptr;
      break;
    case 2:
      int update;
      data.Xuat();
      cout << " Nhap STT nhan vien can chinh sua : ";
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
      case 6:
      data.Sort();
      data.Xuat();
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
//g++ Nhanvien.cpp nvhd.cpp nvbc.cpp date.cpp main.cpp -o c