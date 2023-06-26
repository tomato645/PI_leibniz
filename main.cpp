#include <iostream>
#include <cmath>
#include <iomanip>
#include <thread>
#include <vector>
#include <list>
#include <cstring>
#include <chrono>
#include <string>

long long int LOOP_TIME = 9999999999;
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
        double child = pow((-1), i);
        double mother = (2 * i) + 1;
        double item = child / mother;
        sum += item;

        if (huge == true && (i % (LOOP_TIME / 10)) == 0)
        {
            checkProgress(i, LOOP_TIME);
        }
    }
    sumList.push_back(sum);
    return 0;
}

int accuratePI(double calculatedPI)
{
    int count = 0;
    std::string correctDecimals = "3.14159265358979323846264338327950288419716939937";
    std::string calculatedPI_str = std::to_string(calculatedPI);

    std::cout << "correct    = " << correctDecimals << std::endl;
    std::cout << "calculated = " << calculatedPI_str << std::endl;

    for (int i = 0; i < calculatedPI_str.length() - 2; i++)
    {
        if (calculatedPI_str[i] == correctDecimals[i])
        {
            count++;
        }
    }
    count -= 2; // 整数部分と小数点を無視する
    std::cout << "正確な桁数（少数部分）は = " << count << std::endl;
    return count;
}

int main(int argc, char *argv[])
{
    std::chrono::system_clock::time_point start, end;
    start = std::chrono::system_clock::now();

    init(argc, argv);

    std::cout << LOOP_TIME << "回実行します" << std::endl;

    float threads_num = 8;
    float unit = LOOP_TIME / threads_num;
    std::thread th1(calculate, unit * 0, unit * 1);
    std::thread th2(calculate, unit * 1, unit * 2);
    std::thread th3(calculate, unit * 2, unit * 3);
    std::thread th4(calculate, unit * 3, unit * 4);
    std::thread th5(calculate, unit * 4, unit * 5);
    std::thread th6(calculate, unit * 5, unit * 6);
    std::thread th7(calculate, unit * 6, unit * 7);
    std::thread th8(calculate, unit * 7, unit * 8);

    std::cout << threads_num << "スレッドで計算します。" << std::endl;

    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();
    th7.join();
    th8.join();

    std::cout << std::endl;

    double sum;
    for (int i = 0; i < sumList.size(); i++)
    {
        sum += sumList[i];
    }

    double PI = sum * 4;
    std::cout << "PI         = " << std::setprecision(99) << PI << std::endl;

    end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << elapsed << "ms" << std::endl;

    std::cout << std::endl;
    accuratePI(PI);
}