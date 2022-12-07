#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    int x = 20;
    string s;
    stringstream ss;
    ss << x;
    ss >> s;
    cout << s + 'a' << endl;

    string s1 = "10";
    int a;
    // stringstream ss1;
    // ss1 << s1;
    // ss1 >> a;
    istringstream(s1) >> a;
    cout << a+10 << endl;
    return 0;

}