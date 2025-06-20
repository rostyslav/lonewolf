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

/**
 * Position the cursor at specific coordinates using ANSI escape sequences
 *
 * @param col represent the x coordinate
 * @param row represent the y coordinate
 */
void Console::gotoXY(int col, int row) {
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
        while (currentX < window.second.getX() + window.second.getWidth() - 1) {
            std::cout << "-";
            currentX++;
        }
        // Print top right corner
        std::cout << "+";
        // Print left and right borders
        while (currentY < window.second.getY() + window.second.getHeight() - 1) {
            gotoXY(window.second.getX(), currentY);
            std::cout << "|";
            gotoXY(window.second.getX() + window.second.getWidth() - 1, currentY);
            std::cout << "|";
            currentY++;
        }
        // Print left bottom corner
        gotoXY(window.second.getX(), window.second.getY() + window.second.getHeight() - 1);
        std::cout << "+";
        // Print bottom border
        currentX = window.second.getX() + 1;
        while (currentX < window.second.getX() + window.second.getWidth() - 1) {
            std::cout << "-";
            currentX++;
        }
        // Print right bottom corner
        std::cout << "+";
    }
}

void Console::remove() {
}
