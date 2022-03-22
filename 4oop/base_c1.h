#ifndef BASE_C1_H
#define BASE_C1_H
#include <string>
#include "base.h"
using namespace std;
class base_c1 :
    public base
{
public:
    base_c1(base* b, string n);
};

#endif