#include <iostream>
#include <cmath>

int LOOP_TIME = 10;
double sum = 0;

int main(int argc, char *argv[])
{
    if (argc >= 2){
        LOOP_TIME = atoi(argv[1]);
    }

    std::cout << LOOP_TIME << "回実行します" << std::endl;

    for (int i = 0; i < LOOP_TIME; i++)
    {
        double child = pow((-1), i);
        double mother = (2 * i) + 1;
        double item = child / mother;
        sum += item;
        // std::cout << child << " / " << mother << std::endl;
        // std::cout << i << std::endl;
    }

    double PI = sum * 4;
    std::cout << "PI = " << PI << std::endl;
}