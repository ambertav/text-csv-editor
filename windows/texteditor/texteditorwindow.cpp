#include "texteditorwindow.h"

#include <QTextEdit>
#include <QTextStream>
#include <QVBoxLayout>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QMenuBar>
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

    setupMenuBar();
}

TextEditorWindow::~TextEditorWindow() {};

void TextEditorWindow::closeEvent(QCloseEvent *event) {
    if (textEdit->document()->isModified()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(
            this,
            "Unsaved Changes",
            "You have unsaved changes. Do you wish to save before exiting?",
            QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel
            );

        if (reply == QMessageBox::Yes)
        {
            saveFile();
            event->accept();
        }

        else if (reply == QMessageBox::No) event->accept();
        else if (reply == QMessageBox::Cancel) event->ignore();
    }

    else event->accept();
}

void TextEditorWindow::setupMenuBar()
{
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *fileMenu = menuBar->addMenu("&File");

    QAction *saveAction = new QAction("&Save", this);
    saveAction->setShortcut((QKeySequence::Save));
    connect(saveAction, &QAction::triggered, this, &TextEditorWindow::saveFile);

    fileMenu->addAction(saveAction);
}

void TextEditorWindow::loadFile(const QString &filePath)
{
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not opne file");
        return;
    }

    QTextStream in(&file);
    textEdit->setText(in.readAll());
    currentFilePath = filePath;
}

void TextEditorWindow::saveFile()
{
    if (currentFilePath.isEmpty()) {
        currentFilePath = QFileDialog::getSaveFileName(this, "Save File", "","Text Files (*.txt);;All Files (*)");
        if (currentFilePath.isEmpty()) return;
    }

    QFile file(currentFilePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not save file");
        return;
    }

    QTextStream out(&file);
    out << textEdit->toPlainText();
}


