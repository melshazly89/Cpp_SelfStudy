#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

#define EnterFn enterFn enFn =enterFn(__func__);
#define ExitFn exitFn exFn = exitFn(__func__);
#define PRINT_BT     backtrace bk = backtrace();\
                     bk.printbtrace();

class backtrace{
    public:
        const string funcname;
        static string bt;
        static string bt_exit;
        static queue<string> bk_callfunc;
        backtrace();
        void printbtrace();


};

class enterFn:public backtrace
{
    public :
        const string funcname;
        enterFn(const string& funcname);

};

class exitFn:public backtrace
{
    public :
        const string funcname;
        exitFn(const string& funcname);

};


backtrace::backtrace()
{
    /*DO NOTHING */
}
queue<string> backtrace::bk_callfunc;
string backtrace::bt;
void backtrace::printbtrace()
{
    int lcount = 0;
    bt+="Backtrace as follows :\n";
    while (!bk_callfunc.empty())
    {
        bt+=to_string(lcount) + " - " + bk_callfunc.front()+"\n";
        bk_callfunc.pop();
        lcount++;
    }
    cout << bt <<endl;
    cout << "Back Trace is Finsihed" <<endl;
    

}
enterFn::enterFn(const string& funcname):funcname(funcname)
{
    bt += "Enter to [" + funcname + "]\n";
    bk_callfunc.push(funcname);
    
}

exitFn::exitFn(const string& funcname):funcname(funcname)
{
    cout << "Exit from [" + funcname + "]\n"; 
}


void func1();
void func2();
void func3();
void func1()
{
    EnterFn
    func2();
    ExitFn
}
void func2()
{
    EnterFn
    func3();
    ExitFn
}
void func3()
{
    EnterFn
    PRINT_BT;
    ExitFn
}
int main ()
{
    /*Test Code*/
    EnterFn
    func1();
    ExitFn

    return 0;
}