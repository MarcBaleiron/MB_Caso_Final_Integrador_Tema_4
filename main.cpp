#include <iostream>
#include "variant.h"
using namespace std;

int main ()
{
    // Creación de instancias de la clase Variant
    Variant var1 (Symbol, "x");
    Variant var2 (Number, "42");
    Variant var3 (Cadena, "Hola Mundo");

    // Creación de una lista que contiene las instancias previamente definidas
    vector list = {var1, var2, var3};
    Variant var_list (List);
    var_list.list = list;

    // Uso de las funciones to_string y to_json_string
    cout << "to_string: " << var_list.to_string () << endl;
    cout << "to_json_string: " << var_list.to_json_string () << endl;

    // Creación de una cadena JSON
    string json_str = "[\"y\", 73, \"Hola JSON\"]";

    // Uso de la función from_json_string
    Variant parsed1 = Variant::from_json_string (json_str);
    cout << "Parsed a string: " << parsed1.to_string () << endl;

    // Uso de la función parse_json
    Variant parsed2 = Variant::parse_json (json_str);
    cout << "Parsed a string: " << parsed2.to_string () << endl;

    return 0;
}