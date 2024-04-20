#include <iostream>
#include <cmpx>

int main(void)
{
    Complex *number = new Complex(3, -1);
    std::cout << number->stringify() << "\n";
}
