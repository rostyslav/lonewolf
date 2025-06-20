#include <iostream>
#include <sys/ioctl.h>

#include "Console.h"

int main() {

    Console console;
    console.clear();

    console.createWindow(1, 1, 1, 80, 24);
    console.createWindow(2, 2, 2, 78, 22);
    console.update();

    // std::cout << "\033[2J\033[H";
    // std::cout << "\033[1;" << size.ws_col << "H*";

    char ch = cin.get(); // or ch = getchar();

    return 0;
}