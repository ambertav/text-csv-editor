#ifndef TEXTEDITORWINDOW_H
#define TEXTEDITORWINDOW_H

#include <QWidget>
#include <QCloseEvent>
#include <QTextEdit>
#include <QLabel>

class TextEditorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TextEditorWindow(QWidget *parent = nullptr);
    ~TextEditorWindow();

    void loadFile(const QString &filePath);
    void saveFile();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    QTextEdit *textEdit;
    QString currentFilePath;
    QLabel *label;

    void setupMenuBar();
};

#endif // TEXTEDITORWINDOW_H
