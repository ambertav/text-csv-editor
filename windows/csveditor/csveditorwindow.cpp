#include "csveditorwindow.h"

#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>

CsvEditorWindow::CsvEditorWindow(QWidget *parent)
    : QWidget(parent), label(new QLabel("CSV Editor ", this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(label);

    setLayout(layout);

    setWindowTitle("CSV Editor");
    setMinimumSize(600, 400);
}

CsvEditorWindow::~CsvEditorWindow() {};

void CsvEditorWindow::openFile(const QString &filePath) {}

void CsvEditorWindow::saveFile() {}
