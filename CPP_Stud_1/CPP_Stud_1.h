#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cassert> 

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.

class SomeStrongPerson {
public:
	void getCode() {
		std::cout << code << '\n';
	}
	SomeStrongPerson() {
		std::cout << "SSP()" << '\n';
	};
	SomeStrongPerson(const SomeStrongPerson& obj) {
		std::cout << "SSP(const SomeStrongPerson&)" << '\n';
	}
	SomeStrongPerson& operator=(const SomeStrongPerson& obj) {
		std::cout << "SSP& op=(const SSP&)" << '\n';
		this->code = "new";
		return *this;
	}
private:
	std::string code = "password for nuclear war";
};

namespace oop_lab1 {


    enum class type_of_book
    {
        tech = 0,
        art = 1
    };

    namespace book {



        struct book_obj
        {
            std::string name;
            std::string author;
            //bool type; //enum 
            type_of_book type;
        };


        class Book {
        public:
            Book(const std::string& _author_name, const std::string& _book_name, type_of_book _book_type) : m_author_name(_author_name) {
                //m_author_name = _author_name; 
                m_book_name = _book_name;
                m_book_type = _book_type;
            };
            ~Book() {};
            book_obj get_book() const {
                book_obj out_book_obj;
                out_book_obj.author = m_author_name;
                out_book_obj.name = m_book_name;
                out_book_obj.type = m_book_type;
                return out_book_obj;
            }
            type_of_book get_type() const {
                return m_book_type;
            }
            
            std::string get_book_name() const {
                return m_book_name;
            }

            std::string get_author_name() const {
                return m_author_name;
            }

            bool is_normal() const {
                return (!m_book_name.empty() && !m_author_name.empty());
            }

        private:
            const std::string m_author_name;
            std::string m_book_name;
            type_of_book m_book_type;
        };

        void new_book(const Book&& new_book, std::vector<Book>& vec) {
            if (new_book.is_normal()) {
                vec.emplace_back(std::move(new_book));
            }
        }

        void new_book(const Book& new_book, std::vector<Book>& vec) {
            if (new_book.is_normal()) {
                vec.emplace_back(std::move(new_book));
            }
        }

        void print_count_type_of_book1(const std::vector<Book>& vec) {// 
            int cnt_art{ 0 };
            int cnt_tech{ 0 };

            for (const Book& el : vec) {// 
                if (el.get_book().type == type_of_book::tech) {
                    cnt_tech++;
                }
                else {
                    cnt_art++;
                }
            }
            std::cout << "Count of technical books: " << cnt_tech << '\n';
            std::cout << "Count of artistic books: " << cnt_art << '\n';
        }

        void print_count_type_of_book2(const std::vector<Book>& vec) {
            int cnt_art{ 0 };
            int cnt_tech{ 0 };
            for (const Book& el : vec) {
                switch (el.get_book().type)
                {
                case type_of_book::tech:
                    cnt_tech++;
                    break;
                case type_of_book::art:
                    cnt_art++;
                    break;
                default:
                    break;
                }
            }
            std::cout << "Count of technical books: " << cnt_tech << '\n';
            std::cout << "Count of artistic books:  " << cnt_art << '\n';
        }
    }

    

#include <iostream> 
#include <vector> 
#include <string>

    int main1()
    {
        std::cout << "Hello World!\n";
        std::vector<book::Book> vec;
        book::new_book(book::Book("AAA", "name", type_of_book::art), vec);
        book::new_book(book::Book("asdasd", "nahhhhme", type_of_book::tech), vec);
        book::new_book(book::Book("asdasd", "nahhhhme", type_of_book::tech), vec);
        book::new_book(book::Book("asdasd", "nahhhhme", type_of_book::tech), vec);
        book::new_book(book::Book("asdasd", "nahhhhme", type_of_book::tech), vec);
        book::new_book(book::Book("asdasd", "nahhhhme", type_of_book::tech), vec);
        book::new_book(book::Book("", "nahhhhme", type_of_book::art), vec);
        std::cout << vec[0].get_book().name << '\n';
        book::print_count_type_of_book2(vec);
        return 0;
    }




   
}

namespace oop_lab1_2
{
    class Car {
    public:
        Car(const std::string& _car_model) { m_car_model = _car_model; };
        Car(const std::string&& _car_model) { m_car_model = _car_model; };
        virtual ~Car() {
            //std::cout << typeid(this).name() << " " << m_car_model << '\n';
        }

        std::string get_car_model() {
            return m_car_model;
        }
    protected:
        std::string m_car_model;
    };

    class BMW : public Car
    {
    public:
        BMW(const std::string& _car_model) : Car(_car_model) {};
        BMW(const std::string&& _car_model) : Car(_car_model) {};
        ~BMW() {
            std::cout << typeid(this).name() << " " << m_car_model << '\n';
        }
    };
    class Audi :public Car
    {
    public:
        Audi(const std::string& _car_model) : Car(_car_model) {};
        Audi(const std::string&& _car_model) : Car(_car_model) {};
        ~Audi() {
            std::cout << typeid(this).name() << " " << m_car_model << '\n';
        }
    };
    class Ford :public Car
    {
    public:
        Ford(const std::string& _car_model) : Car(_car_model) {};
        Ford(const std::string&& _car_model) : Car(_car_model) {};
        ~Ford() {
            std::cout << typeid(this).name() << " " << m_car_model << '\n';
        }
    };
    class Toyota :public Car
    {
    public:
        Toyota(const std::string& _car_model) : Car(_car_model) {};
        Toyota(const std::string&& _car_model) : Car(_car_model) {};
        ~Toyota() {
            std::cout << typeid(this).name() << " " << m_car_model << '\n';
        }
    };

    Car* gen_car(const std::string& _mark, const std::string& _model) {
        if (_mark == "BMW") {
            return new BMW(_model);
        } 
        else if (_mark == "Audi") {
            return new Audi(_model);
        }
        else if (_mark == "Ford") {
            return new Ford(_model);
        }
        else if (_mark == "Toyota") {
            return new Toyota(_model);
        }
        else
        {
            return std::nullptr_t();
        }
    }




    int main2() {
        std::string str;
        std::vector<std::pair<std::string, std::string>> car_mark;
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

        }
        else {
            std::cout << "file open error " << '\n';
        }
        for (int i = 0; i < cars.size(); ++i) {
            delete cars[i];
        }
        return 0;
    }
}
/*Лаб. 1
       1. Есть библиотека, в которой хранятся два вида книг – художественные и
       технические.
       Надо создать программу, в которой :
           А) наполнить библиотеку несколькими разными книгами(Примечание1: у
           пользовательского конструктора класса должно быть 3 параметра – для указания
           имени автора, названия книги и типа, художественная или техническая)
           (Примечание2: в библиотеке не должно быть книг безымянных и без названия);
           Б) В отдельной процедуре вывести на консоль, используя оператор switch,
           количество художественной литературы и технической;
           В) В дополнительной процедуре вывести на консоль те же данные, не применяя
           оператор switch.
           Программа должна функционировать корректно(следить за недопущением
           утечки памяти).

       2. Вручную создать текстовый файл со следующей информацией : в две колонки,
       разделяя их пробелом, марка машины — модель.
           Например : Мерседес 320. (всего примерно 10 строк в файле, марка и модель могут повторяться).
           В программе загрузить файл, распределяя данные по объектам, тип которых
           соответствует марке автомобиля, а модель — член данных в базовом классе.
           Храниться объекты должны совместно, используя контейнер vector.Вывести данные
           о модели и марке каждого автомобиля при выходе из программы. (Подсказка : в
               деструкторах).
   */