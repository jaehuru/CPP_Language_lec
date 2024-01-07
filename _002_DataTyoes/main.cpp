#include <iostream>

using namespace std;

int main()
{
    int i;
    i = 123;

    cout << i << " " << sizeof(i) << endl;

    float f = 123.456f;
    double d = 123.456; 

    cout << f << " " << sizeof(f) << endl;
    cout << d << " " << sizeof(d) << endl;

    char c = 'a';
    char str[] = "Hello, World!";

    cout << c << " " << sizeof(c) << endl;

    i = 987.654; // double 형번환

    cout << "int from double" << i << endl;

    f = 567.89; // double 형변환

    // 기본 연산자

    i += 100; 
    i++;

    cout << i << endl; //1088

    //불리언

    bool is_good = true;
    is_good = false;

    cout << is_good << endl; // false = 0

    // is_good = true;
    // cout << is_good << endl; // true = 1

    cout << boolalpha << true << endl; // true
    cout << is_good << endl; // false
    cout << noboolalpha << true << endl; // 1

    // 논리 연산
    cout << boolalpha;
    cout << (false && true) << endl; // false
    cout << (true || false) << endl; // true

    cout << (1 > 3) << endl;
    cout << (3 == 3) << endl;
    cout << (i >= 3)
    cout << ('a' != 'c') << endl;
    cout << ('a' == 'c') << endl;

    //영역(scope)

    i = 123; // 더 넓은 영역

    {
        int i = 345;
        cout << i << endl; //345
    }

    cout << i << endl; // 123

    return 0;
}