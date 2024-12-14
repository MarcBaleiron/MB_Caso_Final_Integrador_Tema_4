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

string Variant::to_json_string ()
{
    switch (type)
    {
        case Symbol: return "\"" + val + "\"";
        case Number: return val;
        case Cadena: return "\"" + val + "\"";
        case List:
        {
            ostringstream oss;
            oss << "[";
            for (size_t i = 0; i < list.size (); ++i)
            {
                oss << list [i].to_string ();
                if (i != list.size () -1) oss << " ";
            }
            oss << "]";
            return oss.str ();
        }
        case Proc: return "\"<procedure>\"";
        case Lambda: return "\"<lambda>\"";
        default: return "\"<unknown>\"";
    }
}

Variant Variant::from_json_string (const string& sjson)
{
    string err;
    json11::Json parsed_json = json11::Json::parse (sjson, err);
    if (!err.empty ()) throw runtime_error ("JSON invalido: " + err);

    return parse_json (parsed_json);
}

Variant Variant::parse_json (const json11::Json& job)
{
    if (job.is_string ()) return Variant (Symbol, job.string_value ());
    if (job.is_number ()) return Variant (Number, to_string (job.number_value ()));
    if (job.is_array ())
    {
        Variant result (List);
        for (const auto& item : job.array_items ())
        {
            result.list.push_back (parse_json (item));
        }
        return result;
    }
    throw runtime_error ("Tipo de JSON no importado");
}