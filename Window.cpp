#include "Window.h"

Window::Window(int _x, int _y, int _width, int _height) : x(_x), y(_y), width(_width), height(_height) {
}

int Window::getX() {
    return x;
}

int Window::getY() {
    return y;
}

int Window::getWidth() {
    return width;
}

int Window::getHeight() {
    return height;
}

