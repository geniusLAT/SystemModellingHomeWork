// BackendSystemModelling.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
using namespace std;


float* GenerateRandoms(int HowMuch, int from, int to) {
    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());  // to seed mersenne twister.
    uniform_int_distribution<> dist(1, 10000); // distribute results between 1 and 6 inclusive.




    float* res = new float[HowMuch];
    int delta = to - from;
    for (int i = 0; i < HowMuch; i++)
    {
       float x = (dist(gen) % (1001 * delta)) / 1000.0;
       
       res[i] = from+x;
    }




    return res;
}

float* GenerateColumns(int n, float a,float b,int howMuch) {
    float* Ar = GenerateRandoms(howMuch, a, b);
    float ColumnRange = (b-a) / n;
    std::cout << " (" << a << "-" << b << ")/" << n << "=";
    std::cout << " ColumnRange" << ColumnRange<<std::endl;
    float* ColumnHeight = new float[n];
    for (int j = 0; j < n; j++)
    {
        ColumnHeight[j] = 0;
        float leftBorder = j * ColumnRange;
        float rightBorder = leftBorder + ColumnRange;
        for (int i = 0; i < howMuch; i++)
        {
            if ((Ar[i]>=leftBorder) && (Ar[i]<rightBorder)) {
                ColumnHeight[j]++;
                //std::cout << " " << j;
            }
        }
        ColumnHeight[j] /= howMuch;
    }
    return ColumnHeight;
}
int main()
{
    std::cout << "Hello World!\n";

    float* Ar = GenerateColumns(15, 0, 2,1000000);
    for (int i = 0; i < 15; i++)
    {
        std::cout << " " << Ar[i];
    }
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
