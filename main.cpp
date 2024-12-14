#include <iostream>
#include "variant.h"
using namespace std;

int main ()
{
    Variant var1 (Symbol, "x");
    Variant var2 (Number, "42");
    Variant var3 (Cadena, "Hola Mundo");

    Variant::List list = {var1, var2, var3};
    Variant var_list (List);
    var_list.list = list;

    cout << "to_string: " << var_list.to_string () << endl;
    cout <<"to_json_string: " << var_list.to_json_string () << endl;

    const string json_str = "[\"z\", 73, \"Hola JSON\"]";
    Variant parsed = Variant::from_json_string (json_str);

    cout << "Parsed a string; " << parsed.to_string () << endl;

    return 0;
}