#include <iostream>

int main() {
    int sum = 0, value = 0;
    unsigned u = 0;
    std::cout << "Enter some numbers:" << std::endl;
    while (std::cin >> value) {
        sum += value;
    }
    std::cout << "The sum of numbers is " << sum << std::endl;
}