#include "application.h"

int main(int argc, char *argv[])
{
        QApplication a(argc, argv);


        Application scs;
        scs.run();

        return a.exec();

}
