#include <iostream>
#include <cmath>

int LOOP_TIME = 10;
double sum = 0;
bool huge = false;

int checkProgress(int count, int loop_time)
{
    if (count % (loop_time / 10) == 0)
    {
        char test[] = "123456789";
        std::cout << "\r" << std::flush;
        for (int j = 0; j < count / (loop_time / 10); j++)
        {
            std::cout << test[j] << std::flush;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        LOOP_TIME = atoi(argv[1]);
    }

    if (LOOP_TIME >= 100000000)
    {
        huge = true;
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

        if (huge == true && (i % (LOOP_TIME / 10)) == 0)
        {
            checkProgress(i, LOOP_TIME);
        }
    }

    std::cout << std::endl;
    double PI = sum * 4;
    std::cout << "PI = " << PI << std::endl;
}