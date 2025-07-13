#include <iostream>
#include <vector>
#include <limits>

class List 
{
    private:
        void clear_screen();
        void wait_for_keypress();
    protected:
    public:

        List() {
            // constructor
        }

        ~List() {
            // destructor
        }

        void print_menu();
        void print_list();
        void add_item();
        void delete_item();

        std::vector<std::string> list;
        std::string name;
};