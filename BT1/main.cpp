#include <iostream>

using namespace std;

struct vector3d {
    double x, y, z;
    vector3d() {
    }
    vector3d(double xx, double yy, double zz) {
        x = xx, y = yy, z = zz;
    }
    /*
    vector3d operator + (vector3d &v) {
        return vector3d(x + v.x, y + v.y, z + v.z);
    }
    vector3d operator - (vector3d &v) {
        return vector3d(x - v.x, y - v.y, z - v.z);
    }
    double operator * (vector3d &v) {
        return x * v.x + y * v.y + z * v.z;
    }
    */
};

vector3d operator + (vector3d &v1, vector3d &v2) {
    return vector3d(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
vector3d operator - (vector3d &v1, vector3d &v2) {
    return vector3d(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
double operator * (vector3d &v1, vector3d &v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
istream & operator >> (istream &in, vector3d &v) {
    double x, y, z;
    in >> x >> y >> z;
    v = vector3d(x, y, z);
    return in;
}
ostream & operator << (ostream &out, const vector3d &v) {
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}

int main()
{

    vector3d v1;
    vector3d v2;
    cin >> v1 >> v2;
    cout << v1 + v2 << endl;
    cout << v1 - v2 << endl;
    cout << v1 * v2;

    return 0;
}
