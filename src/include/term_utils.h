#include <termios.h>

class TermUtils
{
    private:
    protected:
    public:  
        TermUtils() {
            static struct termios old, new1;
        }

        ~TermUtils() {}

        void initTermios(int echo);
        void resetTermios(void);
};