#include <iostream>
using namespace std;
#include "hello.h"
#include "config.h"
#ifdef SayHi
#include "Hi/hi.h"
#endif

int main(int argc, char* argv[]){
    cout << "hello cmake" << endl;
#ifdef SayHi
#ifdef HAVE_LOG
    hi("yzd");
#endif
#endif
    hello("yzd");
}