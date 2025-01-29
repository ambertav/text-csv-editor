#include "texteditorwidget.h"

#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>

TextEditorWidget::TextEditorWidget(QWidget *parent)
    : QWidget(parent), textEdit(new QTextEdit(this))
    , label(new QLabel("Hello from the text editor widget", this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(label);
    layout->addWidget(textEdit);

    setLayout(layout);
}

TextEditorWidget::~TextEditorWidget() {};

void TextEditorWidget::openFile(const QString &filePath) {}

void TextEditorWidget::saveFile() {}
