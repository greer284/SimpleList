#include <iostream>
#include <vector>
#include <fstream>

class Database
{
    private:
    protected:
    public:

        Database() {
            // constructor
        }

        ~Database() {
            // destructor
        }

        std::vector<std::vector<std::string>> mainList;
        std::string name;

        void write(std::vector<std::vector<std::string>> mainList);
        std::vector<std::vector<std::string>> read();
};