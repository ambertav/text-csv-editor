#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QComboBox>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , textEditorWidget(new TextEditorWidget(this))
    , csvEditorWidget(new CsvEditorWidget(this))
{
    ui->setupUi(this);

    QWidget *mainWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(mainWidget);

    label = new QLabel("Choose an editor to start:\n", this);
    label->setAlignment(Qt::AlignCenter);

    editorComboBox = new QComboBox(this);
    editorComboBox->addItem("Text Editor");
    editorComboBox->addItem("CSV Editor");

    connect(editorComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(onSelectChange(int)));

    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(textEditorWidget);
    stackedWidget->addWidget(csvEditorWidget);

    layout->addWidget(label);
    layout->addWidget(editorComboBox);
    layout->addWidget(stackedWidget);

    setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete textEditorWidget;
    delete csvEditorWidget;
    delete label;
}

void MainWindow::onSelectChange(int index)
{
    stackedWidget->setCurrentIndex(index);
}
