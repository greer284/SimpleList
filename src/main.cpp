#include "include/list.h"
#include "include/database.h"

int main(int arg_count, char *args[])
{
    List simple_list;
    Database data;

    if (arg_count > 1)
    {
        simple_list.name = std::string(args[1]);
        simple_list.print_menu();
        data.write(simple_list.list);
        data.read();
    }
    else
    {
        std::cout << "Username not supplied... exiting program\n";
    }

    return 0;
}