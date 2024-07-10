#include <iostream>
#include <cmath>
using namespace std;
// Cấu trúc điểm trong không gian 3 chiều
struct Point3D {
    double x, y, z;
};

// Cấu trúc vector trong không gian 3 chiều
struct Vector3D {
    double x, y, z;
};

// Cấu trúc điểm trong không gian 2 chiều
struct Point2D {
    double x, y;
};

// Hàm tính định thức của ma trận hệ số 2 chiều
double determinant2D(double a, double b, double c, double d) {
    return a * d - b * c;
}

// Hàm xác định mối quan hệ giữa hai đường thẳng trong không gian 2 chiều
void compareLines2D(double A1, double B1, double C1, double A2, double B2, double C2) {
    double delta = determinant2D(A1, B1, A2, B2);
    double delta1 = determinant2D(A1, C1, A2, C2);
    double delta2 = determinant2D(B1, C1, B2, C2);

    if (delta == 0) {
        if (delta1 == 0 && delta2 == 0) {
            cout << "Hai duong thang trung nhau" << endl;
        }
        else {
            cout << "Hai duong thang song song" << endl;
        }
    }
    else {
        cout << "Hai duong thang cat nhau" << endl;
    }
}

// Hàm kiểm tra hai vector có cùng phương không
bool areParallel(Vector3D b1, Vector3D b2) {
    return (b1.x * b2.y == b1.y * b2.x) && (b1.x * b2.z == b1.z * b2.x) && (b1.y * b2.z == b1.z * b2.y);
}

// Hàm tính khoảng cách giữa hai điểm trong không gian 3 chiều
double distance3D(Point3D p1, Point3D p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));
}

// Hàm tính vector từ hai điểm trong không gian 3 chiều
Vector3D vectorFromPoints(Point3D p1, Point3D p2) {
    return { p2.x - p1.x, p2.y - p1.y, p2.z - p1.z };
}

// Hàm xác định mối quan hệ giữa hai đường thẳng trong không gian 3 chiều
void compareLines3D(Point3D a1, Vector3D b1, Point3D a2, Vector3D b2) {
    if (areParallel(b1, b2)) {
        // Kiểm tra nếu hai đường thẳng trùng nhau
        Vector3D a1a2 = vectorFromPoints(a1, a2);
        if (areParallel(b1, a1a2)) {
            cout << "Hai duong thang trung nhau" << endl;
        }
        else {
            cout << "Hai duong thang song song" << endl;
        }
    }
    else {
        // Giải hệ phương trình để kiểm tra nếu hai đường thẳng cắt nhau
        Vector3D a1a2 = vectorFromPoints(a1, a2);
        double denom = b1.x * b2.y - b1.y * b2.x;
        if (denom != 0) {
            double t = (a1a2.x * b2.y - a1a2.y * b2.x) / denom;
            double s = (a1a2.x * b1.y - a1a2.y * b1.x) / denom;
            Point3D intersect1 = { a1.x + t * b1.x, a1.y + t * b1.y, a1.z + t * b1.z };
            Point3D intersect2 = { a2.x + s * b2.x, a2.y + s * b2.y, a2.z + s * b2.z };
            if (distance3D(intersect1, intersect2) < 1e-6) {
                cout << "Hai duong thang cat nhau" << endl;
            }
            else {
                cout << "Hai duong thang cheo nhau" << endl;
            }
        }
        else {
            cout << "Hai duong thang cheo nhau" << endl;
        }
    }
}

int main() {
    int dimension;
    cout << "Chon khong gian 2 chieu hoac 3 chieu: ";
    cin >> dimension;

    if (dimension == 2) {
        double A1, B1, C1, A2, B2, C2;

        // Nhập hệ số của đường thẳng thứ nhất
        cout << "Nhap he so cua duong thang thu nhat (Ax + By + C = 0): ";
        cin >> A1 >> B1 >> C1;

        // Nhập hệ số của đường thẳng thứ hai
        cout << "Nhập he so cua duong thang thu hai (Ax + By + C = 0): ";
        cin >> A2 >> B2 >> C2;

        // Gọi hàm so sánh hai đường thẳng trong không gian 2 chiều
        compareLines2D(A1, B1, C1, A2, B2, C2);
    }
    else if (dimension == 3) {
        Point3D a1, a2;
        Vector3D b1, b2;

        // Nhập dữ liệu cho đường thẳng thứ nhất
        cout << "Nhap diem A1 cua duong thang thu nhat: ";
        cin >> a1.x >> a1.y >> a1.z;
        cout << "Nhap vector chi phuong cua duong thang thu nhat: ";
        cin >> b1.x >> b1.y >> b1.z;

        // Nhập dữ liệu cho đường thẳng thứ hai
        cout << "Nhap diem A2 cua duong thang thu hai: ";
        cin >> a2.x >> a2.y >> a2.z;
        cout << "Nhap vector chi phuong cua duong thang thu hai: ";
        cin >> b2.x >> b2.y >> b2.z;

        // Gọi hàm so sánh hai đường thẳng trong không gian 3 chiều
        compareLines3D(a1, b1, a2, b2);
    }
    else {
        cout << "Lua chon khong hop le!" << endl;
    }

    return 0;
}
