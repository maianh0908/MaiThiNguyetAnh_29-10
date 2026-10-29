#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Ngay {
    int ngay, thang, nam;
};

struct HangHoa {
    int   maHH;
    string tenHH;           
    Ngay   ngayXuat;
    float  giaXuat;         
};

void Nhap(HangHoa a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap hang hoa thu " << i + 1 << endl;
        cout << "Ma hang hoa: ";      
        cin >> a[i].maHH;
        cin.ignore();
        cout << "Ten hang hoa: ";     
        getline(cin, a[i].tenHH);
        cout << "Ngay xuat: ";        
        cin >> a[i].ngayXuat.ngay;
        cout << "Thang xuat: ";       
        cin >> a[i].ngayXuat.thang;
        cout << "Nam xuat: ";         
        cin >> a[i].ngayXuat.nam;
        cout << "Gia xuat (trieu): "; 
        cin >> a[i].giaXuat;
    }
}

void XuatMot(HangHoa h) {
    cout << left << setw(8)  << h.maHH
                 << setw(25) << h.tenHH
                 << setw(10) << h.giaXuat
                 << h.ngayXuat.ngay << "/"
                 << h.ngayXuat.thang << "/"
                 << h.ngayXuat.nam << endl;
}

void Xuat(HangHoa a[], int n) {
    cout << left << setw(8)  << "Ma"
                 << setw(25) << "Ten hang hoa"
                 << setw(10) << "Gia xuat"
                 << "Ngay xuat" << endl;
    for (int i = 0; i < n; i++)
        XuatMot(a[i]);
}

void QuickSort(HangHoa a[], int left, int right) {
    int i = left, j = right;
    float x = a[(left + right) / 2].giaXuat;        

    while (i <= j) {
        while (a[i].giaXuat < x) i++;
        while (a[j].giaXuat > x) j--;
        if (i <= j) {
            HangHoa t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if (left < j)  QuickSort(a, left, j);
    if (i < right) QuickSort(a, i, right);
}

int TimNhiPhan(HangHoa a[], int left, int right, float x) {
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    if (a[mid].giaXuat == x)
        return mid;
    if (a[mid].giaXuat < x)
        return TimNhiPhan(a, mid + 1, right, x);
    return TimNhiPhan(a, left, mid - 1, x);
}

void TimKiem(HangHoa a[], int n, float x) {
    int pos = TimNhiPhan(a, 0, n - 1, x);
    if (pos == -1) {
        cout << "Khong co hang hoa nao co gia xuat = " << x << endl;
    } else {
        cout << "Hang hoa co gia xuat = " << x << ":" << endl;
        
        // In tieu ?? cac c?t
        cout << left << setw(8)  << "Ma"
                     << setw(25) << "Ten hang hoa"
                     << setw(10) << "Gia xuat"
                     << "Ngay xuat" << endl;
        
        int l = pos, r = pos;
        while (l - 1 >= 0 && a[l - 1].giaXuat == x) l--;
        while (r + 1 < n  && a[r + 1].giaXuat == x) r++;
        for (int i = l; i <= r; i++)
            XuatMot(a[i]);
    }
}

int main() {
    HangHoa a[100];
    int n;

    cout << "Nhap n: ";
    cin >> n;
    Nhap(a, n);
    cout << "Danh sach vua nhap:" << endl;
    Xuat(a, n);

    QuickSort(a, 0, n - 1);
    cout << "Sau khi sap xep tang dan theo gia xuat:" << endl;
    Xuat(a, n);

    float x;
    cout << "Nhap gia xuat X can tim: ";
    cin >> x;
    TimKiem(a, n, x);

    return 0;
}
