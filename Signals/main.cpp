#include <iostream>
#include <csignal>
using namespace std;

/*Signal Handling*/
void signalHandler(int sig)
{
    cout <<endl;
    cout <<"Interrupt Handle: "<<sig<<endl;
    exit(sig);
}

int main()
{
    /*Handle Signal*/
    signal(SIGINT, signalHandler);
    while(1)
    {
        /*DO NOTHING*/
    }
    return 0;
}