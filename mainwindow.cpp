#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QVBoxLayout>
#include <QMenuBar>
#include <QFileDialog>
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    textEditorWindows.clear();
    csvEditorWindows.clear();

    QWidget *mainWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(mainWidget);

    label = new QLabel("Welcome:\n", this);
    label->setAlignment(Qt::AlignCenter);

    QPushButton *textEditorButton = new QPushButton("New Blank Document", this);
    QPushButton *csvEditorButton = new QPushButton("New Blank CSV", this);
    QPushButton *openFileButton = new QPushButton("Open File", this);


    connect(textEditorButton, &QPushButton::clicked, this, &MainWindow::openTextEditor);
    connect(csvEditorButton, &QPushButton::clicked, this, &MainWindow::openCsvEditor);
    connect(openFileButton, &QPushButton::clicked, this, &MainWindow::openFile);


    layout->addWidget(label);
    layout->addWidget(textEditorButton);
    layout->addWidget(csvEditorButton);
    layout->addWidget(openFileButton);

    setCentralWidget(mainWidget);

    setupMenuBar();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete label;

    qDeleteAll(textEditorWindows);
    qDeleteAll(csvEditorWindows);
    textEditorWindows.clear();
    csvEditorWindows.clear();
}

void MainWindow::setupMenuBar()
{
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *fileMenu = menuBar->addMenu("&File");

    QAction *openNewTextEditor = new QAction("&New Text File...", this);
    connect(openNewTextEditor, &QAction::triggered, this, &MainWindow::openTextEditor);

    QAction *openNewCsvEditor = new QAction("&New CSV File...", this);
    connect(openNewCsvEditor, &QAction::triggered, this, &MainWindow::openCsvEditor);

    QAction *openAction = new QAction("&Open...", this);
    openAction->setShortcut(QKeySequence::Open);
    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);

    fileMenu->addAction(openNewTextEditor);
    fileMenu->addAction(openNewCsvEditor);
    fileMenu->addSeparator();
    fileMenu->addAction(openAction);

    setMenuBar(menuBar);
}

void MainWindow::openTextEditor()
{
    TextEditorWindow *newWindow = new TextEditorWindow(this);
    textEditorWindows.append(newWindow);

    newWindow->setWindowFlags(Qt::Window);
    connect(newWindow, &QObject::destroyed, this, [this, newWindow]() {
        textEditorWindows.removeAll(newWindow);
    });

    newWindow->show();
}

void MainWindow::openCsvEditor()
{
    CsvEditorWindow *newWindow = new CsvEditorWindow(this);
    csvEditorWindows.append(newWindow);

    newWindow->setWindowFlags(Qt::Window);
    connect(newWindow, &QObject::destroyed, this, [this, newWindow]() {
        csvEditorWindows.removeAll(newWindow);
    });

    newWindow->show();
}

void MainWindow::openFile()
{
    QString filePath = QFileDialog::getOpenFileName(
        this,
        "Open File",
        "",
        "All Files (*);;Text Files (*.txt);;CSV Files (*.csv)"
        );

    if (filePath.isEmpty()) return;

    if (isCsvFile(filePath))
    {
        openCsvEditor();
        csvEditorWindows.last()->openFile(filePath);
    }
    else
    {
        openTextEditor();
        textEditorWindows.last()->loadFile(filePath);
    }
}

bool MainWindow::isCsvFile(const QString &filePath)
{
    if (filePath.endsWith(".csv", Qt::CaseInsensitive) ||
        filePath.endsWith(".tsv", Qt::CaseInsensitive) ||
        filePath.endsWith(".xls", Qt::CaseInsensitive) ||
        filePath.endsWith(".xlsx", Qt::CaseInsensitive))
    {
        return true;
    }

    return false;
}
