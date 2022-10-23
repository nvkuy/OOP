#include "list_congtrinh.h"
#include <iostream>
using namespace std;

list_congtrinh::list_congtrinh()
{
    size = 0;
}

list_congtrinh::~list_congtrinh()
{
    delete [] data;
}
