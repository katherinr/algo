#include <QtCore/QCoreApplication>
#include <QFile>
#include <QString>
#include <cstdlib>
#include <iostream>
#include <exception>
#include <QTextStream>
#include <string>

using namespace  std;


namespace Algotester
{

class ITask
{
   public:
    virtual QString Run(const std::vector <QString>& data){return "";};
};


class Tester
{
 public:
    ITask *task;
    QString path;

    Tester(ITask *task, QString path)
    {
        this->path = path;
        this->task = task;
    }

    bool RunTest(const QString inFile, const QString outFile)
    {
        try
        {
            std::vector <QString> data;
            QFile inputFile(inFile);
            if (inputFile.open(QIODevice::ReadOnly))
            {
                QTextStream in(&inputFile);
                while (!in.atEnd())
                {
                    QString line = in.readLine();
                    data.push_back(line);
                }
            }
            else
            {

                cout<<"inpBr"<<endl;
            }

            QFile outputFile(outFile);
            QString expect = "";

            if (outputFile.open(QIODevice::ReadOnly))
            {
                QTextStream out(&outputFile);
                while (!out.atEnd())
                {
                    QString line = out.readLine();
                    expect+=line;
                }
            }
            else
            {

                cout<<"outpBr"<<endl;
            }
            QString actual = task->Run (data);
            return actual == expect;
        }

            catch (std::exception e)
            {
                cout<<e.what();
                return false;
            }
        }

        void RunTests()
        {
            int nr = 0;
            while (true)
            {
                const auto inFile = path + "\\" + "test." + QString::number(nr) + QString(".in");
                const auto outFile = path + "\\" + "test."+ QString::number(nr)  + QString(".out");


                if (!QFile(inFile).exists() || !QFile(outFile).exists())
                {
                    break;
                }

                QString answer = "Test #" + QString::number(nr) + " " + QVariant(RunTest(inFile, outFile)).toString();
                cout << answer.toStdString() << endl;
                nr++;
            }
        }
    };



class StringLength:public ITask
{
  public:
    QString Run(const vector <QString>& data) override
    {
        return QString::number(data[0].length());
    }
};

};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Algotester::ITask *task = new Algotester::StringLength();

    Algotester::Tester *tester =  new Algotester::Tester(task,
                               "D:\\coding\\otus1\\A01_\\0.String");
    tester->RunTests();
    system("pause");
    return a.exec();
}
