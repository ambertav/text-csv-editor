#include "texteditorwindow.h"

#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>

TextEditorWindow::TextEditorWindow(QWidget *parent)
    : QWidget(parent), textEdit(new QTextEdit(this))
    , label(new QLabel("Text Editor", this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(label);
    layout->addWidget(textEdit);

    setLayout(layout);

    setWindowTitle("Text Editor");
    setMinimumSize(600, 400);
}

TextEditorWindow::~TextEditorWindow() {};

void TextEditorWindow::openFile(const QString &filePath) {}

void TextEditorWindow::saveFile() {}
