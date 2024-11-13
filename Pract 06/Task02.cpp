#include <iostream>

bool isPrime(int num)
{

    int range = num / 2 + 1;

    for (int i = 2; i < range; i++)
    {
        if ((num % i) == 0)
            return false;
    }

    return true;
}

int getNextSmallerPrimeNumber(int num)
{
    int currentNum = num - 1;

    while (!isPrime(currentNum))
        currentNum -= 1;

    return currentNum;
}

int getThePowerOfPrimeNum(int number, int primeNum)
{
    int cnt = 0;

    while ((number % primeNum) == 0)
    {
        number /= primeNum;
        cnt++;
    }

    return cnt;
}

void factorizationTask2(int num)
{
    int currentPrimeNum = getNextSmallerPrimeNumber(num);
    ;
    int currentPower = 1;

    while (num > 1)
    {
        if ((num % currentPrimeNum) == 0)
        {
            currentPower = getThePowerOfPrimeNum(num, currentPrimeNum);
            for (int i = 0; i < currentPower; i++)
            {
                num /= currentPrimeNum;
            }

            std::cout << currentPrimeNum << "^" << currentPower;

            if (num != 1)
            {
                std::cout << " * ";
            }
        }
        else
        {
            currentPrimeNum = getNextSmallerPrimeNumber(currentPrimeNum);
        }
    }
}

int main()
{
    factorizationTask2(21528);
    std::cout << std::endl;

    return 0;
}