// Lab1-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Header.h"

int main()
{
    std::vector<Car*> cars;

    std::ifstream in("txt.txt");
    if (in.is_open())
    {
        std::string mark;
        std::string model;
        while (in >> mark >> model) {
            //car_mark.emplace_back(std::move(std::pair<std::string, std::string>(mark, model)));
            cars.push_back(gen_car(mark, model));
            //std::cout << mark << " - " << model << '\n';
        }
        for (auto el : cars) {
            el->print_car();
        }

    }
    else {
        std::cout << "file open error " << '\n';
    }
    for (auto el : cars) {
        delete el;
    }
    return 0;
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
