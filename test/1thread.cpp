#include <iostream>
#include <cmath>
#include <iomanip>
#include <thread>
#include <vector>
#include <list>
#include <cstring>
#include <chrono>
#include <stdio.h>

long long int LOOP_TIME = 999999999;
std::vector<double> sumList;
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

int init(long long int argc, char *argv[])
{
    if (argc >= 2)
    {
        LOOP_TIME = atoi(argv[1]);
    }

    if (LOOP_TIME >= 100000000)
    {
        huge = true;
    }

    return 0;
}

double calculate(long long int start, long long int stop)
{
    double sum;

    for (long long int i = start; i < stop; i++)
    {
        // std::cout << i << std::endl;

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
    // sumList.push_back(sum);
    return sum;
}

int main(int argc, char *argv[])
{
    std::chrono::system_clock::time_point start, end;
    start = std::chrono::system_clock::now();

    init(argc, argv);

    std::cout << LOOP_TIME << "回実行します" << std::endl;

    double sum = calculate(0, LOOP_TIME);

    std::cout << std::endl;

    // double sum;
    // for (int i = 0; i < sumList.size(); i++)
    // {
    //     sum += sumList[i];
    //     std::cout << i << "番目のリストは" << sumList[i] << std::endl;
    // }

    double PI = sum * 4;
    std::cout << "PI = " << std::setprecision(99) << PI << std::endl;

    end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << elapsed << std::endl;

    // std::cout << "size = " << sumList.size() << std::endl;
}