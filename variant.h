#ifndef VARIANT_H
#define VARIANT_H

#include <vector>
#include <string>
#include <map>
#include "json11/json11.hpp"
using namespace std;

enum variant_type { Symbol, Number, List, Proc, Lambda, Cadena };

struct Entorno;

class Variant
{
public:
	using proc_type = Variant (*) (const vector <Variant>&);
    using map = map <string, Variant>;

    variant_type type;
    string val;
    vector <Variant> list;
    proc_type proc;
    Entorno* env;

	Variant (variant_type type = Symbol);
    Variant (variant_type type, const string& val);
    Variant (proc_type proc);

    string to_string ();
    string to_json_string ();
    static Variant from_json_string (const string& json);
	static Variant parse_json (const json11::Json& job);
};

#endif