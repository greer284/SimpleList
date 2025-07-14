#include "include/list.h"
#include "include/database.h"

int main(int arg_count, char *args[])
{
    List simple_list;
    Database data;

    if (arg_count > 1)
    {
        simple_list.name = std::string(args[1]);
        simple_list.mainList = data.read();
        simple_list.find_userList();
        simple_list.print_menu();
        data.write(simple_list.mainList);
    }
    else
    {
        std::cout << "Username not supplied... exiting program\n";
    }

    return 0;
}