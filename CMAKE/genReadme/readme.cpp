#include <fstream>
using namespace std;

int main(){
    ofstream out;
    out << "this is my first cmake trial" << endl;
    out.flush();
    out.close();
}