#include "app.h"


int main(int argc, char* argv[]) {
    App app{argc, argv};
    if (app.invalidArgumentCount == true) {
        return 1;
    }
    app.run();

    return 0;
}