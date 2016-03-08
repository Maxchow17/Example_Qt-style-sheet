#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QFileInfo>

//set library paths for RELEASE version
void set_LibrPath()
{
   QTextCodec *xcodec = QTextCodec::codecForLocale();
   QString exeDir = xcodec->toUnicode(QByteArray(""));
   QString BKE_CURRENT_DIR = QFileInfo(exeDir).path();
   QStringList  libpath;
   libpath << BKE_CURRENT_DIR + QString::fromLocal8Bit("/plugins/imageformats");
   libpath << BKE_CURRENT_DIR + QString::fromLocal8Bit("/plugins/platforms");
   libpath << BKE_CURRENT_DIR + QString::fromLocal8Bit("/plugins");
   libpath << QApplication::libraryPaths();
   QApplication::setLibraryPaths(libpath);
}

//set stylesheet for main window
void set_StyleSheet()
{
    QString qss;
    QFile qssFile(":/qss/StyleSheet.css");
    qssFile.open(QFile::ReadOnly);

    if (qssFile.isOpen())
    {
       qss = QLatin1String(qssFile.readAll());
       qApp->setStyleSheet(qss);
       qssFile.close();
     }
}

int main(int argc, char *argv[])
{
    set_LibrPath();

    QApplication a(argc, argv);
    set_StyleSheet();

    MainWindow w;
    w.show();

    return a.exec();
}


