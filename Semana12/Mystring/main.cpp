#include <iostream>
#include "String.h"

using namespace std;

int main()
{
    String ma("ciencia");
    cout << ma.StringSize() << endl;
    ma.toLower();
    cout << ma.getData() << endl;
    ma.toUpper();
    cout << ma.getData() << endl;
    return 0;
}
