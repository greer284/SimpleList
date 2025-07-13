#include "include/list.h"

int main(int arg_count, char *args[])
{

    if (arg_count > 0)
    {
        List simple_list;
        simple_list.name = std::string(args[0]);
        simple_list.print_menu();
    }
    else
    {
        std::cout << "Username not supplied... exiting program\n";
    }

    return 0;
}