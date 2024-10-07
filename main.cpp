#include <QApplication>
#include <QTabWidget>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QTabWidget *tabWidget = new QTabWidget;
    QWidget *leaderTab = new QWidget;
    QLabel *leaderLabel = new QLabel("隊長:張志華 41243227\n組員1 徐聖硯 41243128\n組員2 黃詩方 41243205\n組員3 陳霑汶 50915110");
    leaderLabel->setStyleSheet("color: blue;");
    QVBoxLayout *leaderLayout = new QVBoxLayout;
    leaderLayout->addWidget(leaderLabel);
    leaderTab->setLayout(leaderLayout);

    QWidget *member2Tab = new QWidget;
    QLabel *member2Label = new QLabel("這是組員2頁面");
    QPushButton *styleButton = new QPushButton("Front select");
    QVBoxLayout *member2Layout = new QVBoxLayout;
    member2Layout->addWidget(member2Label);
    member2Layout->addWidget(styleButton);
    member2Tab->setLayout(member2Layout);


    QObject::connect(styleButton, &QPushButton::clicked, [=]() {
        bool ok;
        QFont font = QFontDialog::getFont(&ok, leaderLabel->font(), nullptr, "選擇字體");
        if (ok) {
            leaderLabel->setFont(font);
        }
    });

    tabWidget->addTab(leaderTab, "隊長");
    //tabWidget->addTab(member1Tab, "組員1");
    tabWidget->addTab(member2Tab, "組員2");
    //tabWidget->addTab(member3Tab, "組員3");

    tabWidget->setWindowTitle("example");
    tabWidget->resize(400, 300);
    tabWidget->show();

    return app.exec();
}
