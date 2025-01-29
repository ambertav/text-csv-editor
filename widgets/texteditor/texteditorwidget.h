#ifndef TEXTEDITORWIDGET_H
#define TEXTEDITORWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QLabel>

class TextEditorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TextEditorWidget(QWidget *parent = nullptr);
    ~TextEditorWidget();

    void openFile(const QString &filePath);
    void saveFile();

private:
    QTextEdit *textEdit;
    QString currentFilePath;

    QLabel *label;
};

#endif // TEXTEDITORWIDGET_H
