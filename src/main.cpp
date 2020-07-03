#include "../include/App.h"
#include "../include/Configuration.h"

int main(int argc, char* argv[])
{
    App aplicativo(get_path());
    return aplicativo.run(argc, argv);
}
