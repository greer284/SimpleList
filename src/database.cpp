#include "include/database.h"

void Database::write(std::vector<std::string> list)
{
    std::ofstream db;
    // .sl isnt a real filetype, it was made up for this tutorial
    // dot simple list
    db.open("db/lists.sl");

    // check if file successfully opened
    if(db.is_open())
    {
        for (unsigned int list_index = 0; list_index < list.size(); list_index++)
        {
            db << list[list_index] << "\n";
        }
    } else 
    {
        std::cout << "Cannot open file for writing.\n";
    }

    db.close();
}

void Database::read()
{
    std::string line;
    std::ifstream db;
    db.open("db/lists.sl");

    // check if file successfully opened
    if(db.is_open())
    {
        while(getline(db, line, '\n'))
        {
            std::cout << line << '\n';
        }
    } else 
    {
        std::cout << "Cannot open file for writing.\n";
    }

    db.close();
}