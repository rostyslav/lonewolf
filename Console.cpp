//
// Created by rostyslav on 6/20/25.
//

#include "Console.h"
#include <iostream>
#include <unistd.h>
#include <sys/ioctl.h>

Console::Console() {
    ioctl_result = ioctl(STDOUT_FILENO, TIOCGWINSZ, &resolution);
}

void Console::clear() {
    std::cout << "\033[2J\033[H";
}

void Console::gotoXY(int row, int col) {
    std::cout << "\033[" << row << ";" << col << "H";
}

winsize Console::getResolution() {
    return resolution;
}

void Console::createWindow(int id, int row, int col, int width, int height) {
    windows.insert(pair(id, Window(row, col, width, height)));
}

void Console::update() {
    clear();
    for (auto & window : windows) {
        // Print top left corner
        gotoXY(window.second.getX(), window.second.getY());
        std::cout << "+";
        // Print top border
        int currentX = window.second.getX() + 1;
        int currentY = window.second.getY() + 1;
        while (currentY < window.second.getY() + window.second.getWidth() - 1) {
            std::cout << "-";
            currentY++;
        }
        // Print top right corner
        std::cout << "+";
        // Print left and right borders
        while (currentX < window.second.getX() + window.second.getHeight() - 1) {
            gotoXY(currentX, window.second.getY());
            std::cout << "|";
            gotoXY(currentX, window.second.getY() + window.second.getWidth());
            std::cout << "|";
            currentX++;
        }
        // Print left bottom corner
        gotoXY(currentX + window.second.getHeight() - 2, window.second.getY());
        std::cout << "+";
        // Print bottom border
        currentY = window.second.getY() + 1;
        while (currentY < window.second.getY() + window.second.getWidth() - 1) {
            std::cout << "-";
            currentY++;
        }
        // Print right bottom corner
        std::cout << "+";
    }
}

void Console::remove() {
}
