#include "variant.h"
#include <sstream>
#include <stdexcept>
using namespace std;

Variant::Variant (variant_type type) : type (type), env (nullptr), proc (nullptr) { }
Variant::Variant (variant_type type, const string& val) : type (type), val (val), env (nullptr), proc (nullptr) { }
Variant::Variant (proc_type proc) : type (Proc), proc (proc), env (nullptr) { }

string Variant::to_string ()
{
    switch (type)
    {
        case Symbol: return val;
        case Number: return val;
        case Cadena: return "\"" + val + "\"";
        case List:
        {
            ostringstream oss;
            oss << "(";
            for (size_t i = 0; i < list.size (); ++i)
            {
                oss << list [i].to_string ();
                if (i != list.size () -1) oss << " ";
            }
            oss << ")";
            return oss.str ();
        }
        case Proc: return "<procedure>";
        case Lambda: return "<lambda>";
        default: return "<unknown>";
    }
}