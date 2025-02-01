#ifndef CSVEDITORWINDOW_H
#define CSVEDITORWINDOW_H

#include <QWidget>
#include <QTableWidget>
#include <QLabel>

class CsvEditorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CsvEditorWindow(QWidget *parent = nullptr);
    ~CsvEditorWindow();

    void openFile(const QString &filePath);
    void saveFile();

private:
    QLabel *label;
    QTableWidget *tableWidget;
    QString currentFilePath;
};


#endif // CSVEDITORWINDOW_H
