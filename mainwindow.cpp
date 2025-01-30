#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QComboBox>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QFileDialog>
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , textEditorWidget(new TextEditorWidget(this))
    , csvEditorWidget(new CsvEditorWidget(this))
{
    ui->setupUi(this);

    QWidget *mainWidget = new QWidget(this);
    QWidget *landingWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(mainWidget);

    label = new QLabel("Choose an editor to start:\n", this);
    label->setAlignment(Qt::AlignCenter);

    editorComboBox = new QComboBox(this);
    editorComboBox->addItem("");
    editorComboBox->addItem("Text Editor");
    editorComboBox->addItem("CSV Editor");

    connect(editorComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(onSelectChange(int)));

    stackedWidget = new QStackedWidget(this);

    stackedWidget->addWidget(landingWidget);
    stackedWidget->addWidget(textEditorWidget);
    stackedWidget->addWidget(csvEditorWidget);

    layout->addWidget(label);
    layout->addWidget(editorComboBox);
    layout->addWidget(stackedWidget);

    QPushButton *openFileButton = new QPushButton("Open File", this);
    connect(openFileButton, &QPushButton::clicked, this, &MainWindow::openFile);
    layout->addWidget(openFileButton);


    setCentralWidget(mainWidget);

    setupMenuBar();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete textEditorWidget;
    delete csvEditorWidget;
    delete label;
}

void MainWindow::setupMenuBar()
{
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *fileMenu = menuBar->addMenu("&File");

    QAction *openAction = new QAction("&Open", this);
    openAction->setShortcut(QKeySequence::Open);
    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
    fileMenu->addAction(openAction);

    setMenuBar(menuBar);
}

void MainWindow::onSelectChange(int index)
{
    stackedWidget->setCurrentIndex(index);
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
        editorComboBox->setCurrentIndex(2);
        csvEditorWidget->openFile(filePath);
    }
    else
    {
        editorComboBox->setCurrentIndex(1);
        textEditorWidget->openFile(filePath);
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
