#ifndef VARIANT_H
#define VARIANT_H

#include <vector>
#include <string>
#include "json11/json11.hpp"
using namespace std;

enum variant_type { Symbol, Number, List, Proc, Lambda, Cadena };

// Declaración de un Entorno para evitar dependencias circulares
struct Entorno;

// Declaración de la clase Variant
class Variant
{
public:
	using proc_type = Variant (*) (const vector <Variant>&);

	// Tipos de datos
    variant_type type;
    string val;
    vector <Variant> list;
    proc_type proc;
    Entorno* env;

	// Constructores creados
	Variant (variant_type type = Symbol);
    Variant (variant_type type, const string& val);
    Variant (proc_type proc);

	// Funciones creadas
    string to_string ();
    string to_json_string ();
    static Variant from_json_string (const string& json);
	static Variant parse_json (const json11::Json& job);
};

#endif