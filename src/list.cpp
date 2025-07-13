#include "include/list.h"
#include "include/term_utils.h"

void List::print_menu()
{
    int choice = -1;

    clear_screen();
    std::cout << "Main Menu\n";
    std::cout << "***********************\n"; 
    std::cout << " 1 - Print list.\n";
    std::cout << " 2 - Add to list.\n";
    std::cout << " 3 - Delete from list.\n";
    std::cout << " 4 - Quit.\n";
    std::cout << "***********************\n"; 
    std::cout << "Input: ";

    std::cin >> choice;

    // Ignore the carriage return at the end of the std::cin.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (choice)
    {
    case 4:
        std::cout << "Quitting...\n";
        exit(0);
        break;
    case 3:
        delete_item();
        break;
    case 2:
        add_item();
        break;
    case 1:
        print_list();
        break;
    default:
        std::cout << "Sorry choice hasn't been implemented.\n";
        break;
    }
}

void List::add_item()
{
    clear_screen();
    std::cout << "*** Add Item ***\n";
    std::cout << "Type in an item and press enter: ";

    std::string item;
    std::getline(std::cin, item);

    list.push_back(item);

    std::cout << "Successfully added an item to the list.";
    std::cin.clear();
    wait_for_keypress();

    print_menu();
}

void List::delete_item()
{
    clear_screen();
    std::cout << "*** Delete Item ***\n";
    std::cout << "Select an item index number to delete\n";

    if(list.size())
    {
        for (unsigned int list_index = 0; list_index < list.size(); list_index++)
        {
            std::cout << list_index << ": " << list[list_index] << "\n";
        }
    }
    else
    {
        std::cout << "No items in the list or to delete.\n";
    }

    wait_for_keypress();

    print_menu();
}

void List::print_list() {
    clear_screen();
    std::cout << "*** Printing List ***\n";

    for (unsigned int list_index = 0; list_index < list.size(); list_index++)
    {
        std::cout << " * " << list[list_index] << "\n";
    }

    std::cout << "\nM - Menu \nInput: ";
    char choice;
    std::cin.get(choice);

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if(choice == 'M' || choice == 'm')
    {
        print_menu();
    }
    else 
    {
        std::cout << "Invalid choice. Quitting...\n";
    }
}

void List::clear_screen()
{
    // Clear the screen and move the cursor to the top left
    std::cout << "\033[2J\033[1;1H"; 
}

void List::wait_for_keypress()
{
    TermUtils temp;
    temp.initTermios(0);
    std::cin.get();
    std::cin.clear();
    temp.resetTermios();
}