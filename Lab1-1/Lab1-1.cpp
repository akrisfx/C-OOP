// Lab1-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <string>
#include <vector>
#include "Header.h"


int main()
{
    Library lib;
    lib.new_book("AAA", "name", type_of_book::art);
    lib.new_book("asdasd", "nahhhhme", type_of_book::tech);
    lib.new_book("asdasd", "nahhhhme", type_of_book::tech);
    lib.new_book("asdasd", "nahhhhme", type_of_book::tech);
    lib.new_book("asdasd", "nahhhhme", type_of_book::tech);
    lib.new_book("asdasd", "nahhhhme", type_of_book::tech);
    lib.new_book("", "nahhhhme", type_of_book::art);
    std::cout << lib[0].get_book().name << '\n';
    lib.print_count_type_switch();
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
