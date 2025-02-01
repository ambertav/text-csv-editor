#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QLabel>


#include "windows/texteditor/texteditorwindow.h"
#include "windows/csveditor/csveditorwindow.h"

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
    void openTextEditor();
    void openCsvEditor();
    void openFile();


private:
    Ui::MainWindow *ui;
    QList<TextEditorWindow*> textEditorWindows;
    QList<CsvEditorWindow*> csvEditorWindows;
    QLabel *label;

    void setupMenuBar();
    bool isCsvFile(const QString &filePath);
};
#endif // MAINWINDOW_H
