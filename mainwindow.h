#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QStackedWidget>
#include <QLabel>

#include "widgets/texteditor/texteditorwidget.h"
#include "widgets/csveditor/csveditorwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSelectChange(int index);

private:
    Ui::MainWindow *ui;
    QComboBox *editorComboBox;
    QStackedWidget *stackedWidget;
    TextEditorWidget *textEditorWidget;
    CsvEditorWidget *csvEditorWidget;
    QLabel *label;
};
#endif // MAINWINDOW_H
