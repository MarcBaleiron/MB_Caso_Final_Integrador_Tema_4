#ifndef ENTORNO_H
#define ENTORNO_H

#include <map>
#include <string>
#include <stdexcept>
#include "variant.h"
using namespace std;

struct Entorno
{
    map <string, Variant> variables;

    Variant find (const string& name)
    {
        auto it = variables.find (name);
        if (it != variables.end ()) return it -> second;
        throw runtime_error ("Variable no encontrada: " + name);
    }
};

#endif