#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ofstream fifo("bufferpipe"); 

    string message;
    cout << "Enter message to send: ";
    getline(cin, message);

    fifo << message << endl;
    fifo.close();

    cout << "Message sent!" << endl;
    return 0;
}
