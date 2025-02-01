#ifndef TEXTEDITORWINDOW_H
#define TEXTEDITORWINDOW_H

#include <QWidget>
#include <QTextEdit>
#include <QLabel>

class TextEditorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TextEditorWindow(QWidget *parent = nullptr);
    ~TextEditorWindow();

    void openFile(const QString &filePath);
    void saveFile();

private:
    QTextEdit *textEdit;
    QString currentFilePath;

    QLabel *label;
};

#endif // TEXTEDITORWINDOW_H
