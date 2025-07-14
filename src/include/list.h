#include <limits>
#include "database.h"

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

        Database data;
        std::vector<std::vector<std::string>> mainList;
        std::vector<std::string> list;
        std::string name;
        unsigned int currentUserIndex;

        void print_menu();
        void print_list();
        void add_item();
        void delete_item();
        void save_list();
        bool find_userList();
};