#include <windows.h>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

void setColor(int textColor, int backgroundColor) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD)(backgroundColor << 4 | textColor));
}

void clearScreen() {

    system("cls");
}

void moveText(const string& text, int delay) {

    int width = 80; 

    for (int position = 0; position < width; ++position) {
        
        clearScreen();
        string spaces(position, ' ');
        int color = rand() % 15 + 1; 
        setColor(color, 0);
        cout << spaces << text << endl;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}

int main() {

    string text = "I been balling from the start, and now I'm really 'bout to spit.";
    moveText(text, 100);
    setColor(7, 0);
    return 0;
}
