#include "include/database.h"

void Database::write(std::vector<std::vector<std::string>> mainList)
{
    std::ofstream db;
    // .sl isnt a real filetype, it was made up for this tutorial
    // dot simple list
    db.open("db/lists.sl");

    // check if file successfully opened
    if(db.is_open())
    {
        for (size_t user_index=0; user_index < mainList.size(); user_index++)
        {
            for (size_t list_index=0; list_index < mainList[user_index].size(); list_index++)
            {
                if (list_index == 0)
                {
                    db << '#' << mainList[user_index][list_index] << '\n';
                } else
                {
                    db << mainList[user_index][list_index] << '\n';
                }
            }
            db << "%\n";
        }
    } else 
    {
        std::cout << "Cannot open file for writing.\n";
    }

    db.close();
}

std::vector<std::vector<std::string>> Database::read()
{
    std::string line;
    std::ifstream db;
    db.open("db/lists.sl");

    std::vector<std::string> userList;

    // check if file successfully opened
    if(db.is_open())
    {
        // Read each line in ifstream to string using '\n' delimeter
        while(getline(db, line, '\n'))
        {

            if(line.front() == '#')
            {
                std::cout << "Found a hashtag: " << line << '\n';
                line.erase(line.begin()); // remove the first char
                userList.push_back(line);
            }
            else if(line.front() == '%')
            {
                std::cout << "Found a percentage: " << line << '\n';
                mainList.push_back(userList);
                userList.clear();
            }
            else 
            {
                std::cout << "Found an item: " << line << '\n';
                userList.push_back(line);
            }
        }
    } else 
    {
        std::cout << "Cannot open file for writing.\n";
    }

    db.close();

    return mainList;
}