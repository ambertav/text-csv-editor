#include "csveditorwidget.h"

#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>

CsvEditorWidget::CsvEditorWidget(QWidget *parent)
    : QWidget(parent), label(new QLabel("Hello from the csv editor widget", this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(label);

    setLayout(layout);
}

CsvEditorWidget::~CsvEditorWidget() {};

void CsvEditorWidget::openFile(const QString &filePath) {}

void CsvEditorWidget::saveFile() {}
