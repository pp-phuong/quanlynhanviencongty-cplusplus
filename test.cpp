#include <iostream>
#include <ctime>

using namespace std;

int main( )
{
   time_t baygio = time(0);
   tm *ltm = localtime(&baygio);

   // in cac thanh phan cua cau truc tm struct.
   cout << "Nam: "<< 1900 + ltm->tm_year << endl;
   cout << "Thang: "<< 1 + ltm->tm_mon<< endl;
   cout << "Ngay: "<<  ltm->tm_mday << endl;
  cout << "Thu" << 1+  ltm->tm_wday << endl;
}