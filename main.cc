#include "LuckyTickets.h"
#include "Tester.h"

int main()
{
    ITask *task = new LuckyTickets();
    Tester *tester = new Tester(task, "./1.Tickets/");
    tester->RunTests();
}