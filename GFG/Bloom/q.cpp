#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    char    abc[27];
    char    *ptr = abc;
    strcpy(abc, "abcdefghij");
     /*
     * What are the types and values of expressions:
     *
  
     * 1. abc
     * 2. *abc
     * 3. abc[2]
     * 4. &abc[3] //&abc[3] = abc + 3*sizeof(char)
     * 5. abc+4
     * 6. *(abc+5) + 20000  //h  long long x = int * 1LL * int
     * 7. abc[10] //'\0'
     * 8. abc[12] //memset ()
     * 9. &ptr //char**
     */

    // * 1. abc
    // * 2. *abc
    // * 3. abc[2]
    // * 4. &abc[3]
    // * 5. abc+4
    // * 6. *(abc+5)
    // * 7. abc[10]
    // * 8. abc[11]
    // * 9. ptr
    // * 10. &ptr

    cout << abc << " " << typeid(abc).name() << endl ; //abcdefghi char pointer
    cout << *abc << " " << typeid(*abc).name() << endl ; //a char
    cout << abc[2] << " " << typeid(abc[2]).name() << endl ; //c char
    cout << &abc[3] << " " << typeid(&abc[3]).name() << endl ; //defghi char pointer
    cout << abc+4 << " " << typeid(abc+4).name() << endl ; //efghi char pointer
    cout << *(abc+5) + 20000  << " " << typeid(*(abc+5) + 20000 ).name() << endl ; //int
    cout << abc[10] << " " << typeid(abc[10]).name() << endl ;// /0 char
    cout << abc[12] << " " << typeid(abc[12]).name() << endl ; //null char
    cout << ptr << " " << typeid(ptr).name() << endl ; //abcdefghij char pointer
    cout << &ptr << " " << typeid(&ptr).name() << endl ; //some address Pointer Pointer Char
    
    return 0;
}