#pragma once 

enum class type_of_book
{
    tech = 0,
    art = 1
};



struct book_obj
{
    std::string name;
    std::string author;
    //bool type; //enum 
    type_of_book type;
};


class Book {
public:
    Book(const std::string& _author_name, const std::string& _book_name, type_of_book _book_type) :
        m_author_name(_author_name),
        m_book_name(_book_name),
        m_book_type(_book_type) {

    };
    ~Book() {};
    book_obj get_book() const {
        book_obj out_book_obj;
        out_book_obj.author = m_author_name;
        out_book_obj.name = m_book_name;
        out_book_obj.type = m_book_type;
        return out_book_obj;
    }
    const type_of_book get_type() const {
        return m_book_type;
    }

    const std::string& get_book_name() const {
        return m_book_name;
    }

    const std::string& get_author_name() const {
        return m_author_name;
    }



private:
    const std::string m_author_name;
    const std::string m_book_name;
    const type_of_book m_book_type;
};



class Library {
public:


    ~Library() {
        vec.clear();
    }

    void new_book(const std::string& _author_name, const std::string& _book_name, type_of_book _type) {
        if ((!_book_name.empty() && !_author_name.empty())) {
            vec.emplace_back(_author_name, _book_name, _type);
        }
        else {
            std::cout << "invalid book info " << '/n';
        }
    }
    void print_count_type_with_if() const {//naming
        int cnt_art{ 0 };
        int cnt_tech{ 0 };

        for (const Book& el : vec) {
            if (el.get_book().type == type_of_book::tech) {
                ++cnt_tech;
            }
            else if (el.get_book().type == type_of_book::art) {
                ++cnt_art;
            }
        }
        std::cout << "Count of technical books: " << cnt_tech << '\n';
        std::cout << "Count of artistic books: " << cnt_art << '\n';
    }
    void print_count_type_switch() const {
        int cnt_art{ 0 };
        int cnt_tech{ 0 };
        for (const Book& el : vec) {
            switch (el.get_book().type)
            {
            case type_of_book::tech:
                ++cnt_tech;
                break;
            case type_of_book::art:
                ++cnt_art;
                break;
            default:
                break;
            }
        }
        std::cout << "Count of technical books: " << cnt_tech << '\n';
        std::cout << "Count of artistic books:  " << cnt_art << '\n';
    }
    Book& operator[] (int&& index)
    { // for r-value 
        return vec.at(index);
    }
    Book& operator[] (int& index)
    { // for l-value 
        return vec.at(index);
    }

private:
    std::vector<Book> vec;
};



int main1()
{
    std::cout << "Hello World!\n";
    //std::vector<book::Book> vec;
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