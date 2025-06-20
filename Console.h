#ifndef CONSOLE_H
#define CONSOLE_H

#include <map>
#include <string>
#include <sys/ioctl.h>
#include "Window.h"

using namespace std;

class Console {
public:
    Console();
    void clear();
    void gotoXY(int col, int row);
    winsize getResolution();
    void createWindow(int id, int row, int col, int width, int height);
    void update();
    void remove();
private:
    int ioctl_result;
    winsize resolution;
    map<int, Window> windows;
};

#endif //CONSOLE_H
