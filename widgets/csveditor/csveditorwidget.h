#ifndef CSVEDITORWIDGET_H
#define CSVEDITORWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QLabel>

class CsvEditorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CsvEditorWidget(QWidget *parent = nullptr);
    ~CsvEditorWidget();

    void openFile(const QString &filePath);
    void saveFile();

private:
    QLabel *label;
    QTableWidget *tableWidget;
    QString currentFilePath;
};


#endif // CSVEDITORWIDGET_H
