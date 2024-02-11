#include <QApplication>
#include <QTableView>
#include "mytablemodel.h"
#include "exercise.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Exercise *e1{new Exercise("one", 1)};
    Exercise *e2{new Exercise("two", 2)};

    MyTableModel model;
    model.addExercise(e1);
    model.addExercise(e2);

    // view object
    QTableView view;
    // connect view and model
    view.setModel(&model);
        // show view
    view.show();

    return a.exec();
}
