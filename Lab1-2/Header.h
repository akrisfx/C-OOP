#pragma once
class Car {
public:
    Car(const std::string& _car_model) : m_car_model(_car_model) {};
    Car(const std::string&& _car_model) : m_car_model(_car_model) {};
    virtual ~Car() {
        //std::cout << typeid(this).name() << " " << m_car_model << '\n';
    }
    //pure virtual print
    virtual void print_car() = 0;
    std::string get_car_model() {
        return m_car_model;
    }
protected:
    const std::string m_car_model; //const
};

class BMW : public Car
{
public:
    BMW(const std::string& _car_model) : Car(_car_model) {};
    BMW(const std::string&& _car_model) : Car(_car_model) {};
    virtual ~BMW() {
        std::cout << typeid(this).name() << " " << m_car_model << " has destructed" << '\n';
    }
    void print_car() override {
        std::cout << "This is " << typeid(this).name() << " " << m_car_model << '\n';
    }
};
class Audi :public Car
{
public:
    Audi(const std::string& _car_model) : Car(_car_model) {};
    Audi(const std::string&& _car_model) : Car(_car_model) {};
    virtual ~Audi() {
        std::cout << typeid(this).name() << " " << m_car_model << " has destructed" << '\n';
    }
    void print_car() override {
        std::cout << "This is " << typeid(this).name() << " " << m_car_model << '\n';
    }
};
class Ford :public Car
{
public:
    Ford(const std::string& _car_model) : Car(_car_model) {};
    Ford(const std::string&& _car_model) : Car(_car_model) {};
    virtual ~Ford() {
        std::cout << typeid(this).name() << " " << m_car_model << " has destructed" << '\n';
    }
    void print_car() override {
        std::cout << "This is " << typeid(this).name() << " " << m_car_model << '\n';
    }
};
class Toyota :public Car
{
public:
    Toyota(const std::string& _car_model) : Car(_car_model) {};
    Toyota(const std::string&& _car_model) : Car(_car_model) {};
    virtual ~Toyota() {
        std::cout << typeid(this).name() << " " << m_car_model << " has destructed" << '\n';
    }
    void print_car() override {
        std::cout << "This is " << typeid(this).name() << " " << m_car_model << '\n';
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
        return nullptr;
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