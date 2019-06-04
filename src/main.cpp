// main.cpp

#include "aux_header.hpp"
#include "main_window.hpp"

int main(int argc, char * argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":/resources/icons/qt_icon.png"));
    w.show();

    return a.exec();
}
