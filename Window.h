#ifndef WINDOWS_H
#define WINDOWS_H

class Window {
public:
    Window(int _x, int _y, int _width, int _height);
    int getX();
    int getY();
    int getWidth();
    int getHeight();
private:
    int x;
    int y;
    int width;
    int height;
};

#endif //WINDOWS_H
