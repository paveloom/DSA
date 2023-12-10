#include "registry.hpp"

int main(int argc, char** argv) {
    if (argc == 1) {
        printf("Provide the ID of the solution as the first argument.\n");
        return EXIT_SUCCESS;
    }
    if (auto f = Registry::find(argv[1])) {
        (*f)();
    } else {
        printf("There is no solution with the specified ID!\n");
    }
}