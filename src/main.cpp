#include "include/list.h"

int main(int arg_count, char *args[])
{
    List simpleList;

    if (arg_count > 1)
    {
        simpleList.name = std::string(args[1]);
        simpleList.mainList = simpleList.data.read();
        simpleList.find_userList();
        simpleList.print_menu();
    }
    else
    {
        std::cout << "Username not supplied... exiting program\n";
    }

    return 0;
}