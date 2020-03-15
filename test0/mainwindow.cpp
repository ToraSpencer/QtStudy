#include "MainWindow.h"




// 自定义主窗口类：继承自QT的标准主窗口类QMainWindow


//  构造函数
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    this->setWindowTitle("主窗口");
    this->resize(500,500);

    b1.setParent(this);             // 指定父对象————该控件依附于父对象。
    b1.setText("close");            // 设置PushButton的文本
    b1.move(200,200);                 // 位移，坐标原点是父对象的左上角。
    b1.resize(100,30);              // QPushButton::resize(int, int)————修改控件大小的接口

    pb1 = new QPushButton(this);
    pb1->resize(150,30);
    pb1->setText("切换到次级窗口");
    pb1->move(0,400);

    pb2 = new QPushButton(this);
    pb2->setText("变脸按钮");
    pb2->move(0,200);

    pb3 = new QPushButton("控制台打印按钮", this);      // 两个参数的QPushButton构造函数
    pb3->setGeometry(0, 100, 150, 30);                // QPushButton::setGeometry()————同时设定坐标和尺寸。

    psw = new SubWin();


    // QMenuBar————菜单栏
    QMenuBar *pMbar = menuBar();                         // QMainWindow::menuBar()————QMainWindow自己的接口，获取菜单栏
    QMenu *pm = pMbar->addMenu("File");                 // QMenu菜单
    QAction *pa = pm->addAction("new file");            // QAction————菜单项（动作）
    pm->addSeparator();                                 // 菜单项new file下面添加分割线。
    QAction *pa1 = pm->addAction("open");



    //  QToolBar————工具栏
    //  工具栏上面有快捷键——菜单项（动作）的快捷方式
    QToolBar *ptb = addToolBar("toolbar");              // QMainWindow::addToolBar()——获取工具栏
    ptb->addAction(pa);                                 // 工具栏添加快捷键
    //          将按钮做成工具栏上的快捷键。
    ptb->addWidget(&b1);                                // QToolBar::addWidget()
    ptb->addWidget(pb1);
    ptb->addWidget(pb2);
    ptb->addWidget(pb3);



    //  状态栏————在窗口的底部，显示窗口的状态
    QStatusBar *psb = statusBar();                      // QMainWindow::statusBar()——生成状态栏
    QLabel *pl = new QLabel("main window",this);             // QLable————标签
    //       状态栏上从左往右地添加控件
    psb->addWidget(pl);
    psb->addWidget(new QLabel("QtCreatorTest", this));
    //      状态栏上从右往左地添加控件
    psb->addPermanentWidget(new QLabel("created in QtCreator", this));



    //  模态对话框————必须处理完模态对话框以后，才能处理其他窗口
    QPushButton *pb4 = new QPushButton("模态对话框", this);
    ptb->addWidget(pb4);
    connect(pb4, QPushButton::clicked,
            [=]()
            {
                QDialog *pdl = new QDialog();
                std::cout <<"this is a modal dialog" << std::endl;
                pdl->exec();            // 程序卡在这里，不处理完该对话框不能继续，所以该对话框为非模态。
            }
    );



    //  非模态对话框————不干扰其他操作。
    QPushButton *pb5 = new QPushButton("非模态对话框", this);
    ptb->addWidget(pb5);
    connect(pb5, QPushButton::clicked,
            [=]()
            {
                QDialog *pdl = new QDialog();
                std::cout <<"this is a modeless dialog."<< std::endl;
                pdl->show();
                //   设置对话框属性，关闭对话框即释放对话框对象的内存，防止内存泄露。
                pdl->setAttribute(Qt::WA_DeleteOnClose);                    // QDialog::setAttribute()————设置对话框属性

            }
    );


    // QMessageBox————标准对话框，封装有多种按钮。
    QPushButton *pb6 = new QPushButton("标准对话框", this);
    ptb->addWidget(pb6);
    connect(pb6, QPushButton::clicked,
            [=]()
            {
                // 使用QMessageBox的静态类方法来创建一个标准对话框对象，并打开。
                int ret = QMessageBox::question(this,                            // static int QMessageBox::question()
                                                "标准对话框————问题",
                                                "你弄懂标准对话框了吗？",
                                                QMessageBox::Yes,
                                                QMessageBox::No,
                                                QMessageBox::Cancel);
                switch(ret)
                {
                case QMessageBox::Yes:
                    std::cout << "Attaboy!" << std::endl;
                    break;
                case QMessageBox::No:
                    std::cout << "Dumass!" <<std::endl;
                    break;
                default:
                    break;
                }

            }
    );



    //  QFileBox————文件对话框
    QPushButton  *pb7 = new QPushButton("文件对话框", this);
    ptb->addWidget(pb7);
    connect(pb7, QPushButton::clicked,
            [=]()
            {
                // 使用QFileDialog的静态类方法来创建文件对话框对象，并打开
                /* QFileDialog::getOpenFileName()————此对话框返回文件的路径。
                 * static QString QFileDialog::getOpenFileName(QWidget *parent = Q_NULLPTR,
                                                                const QString &caption = QString(),
                                                                const QString &dir = QString(),
                                                                const QString &filter = QString(),
                                                                QString *selectedFilter = Q_NULLPTR,
                                                                Options options = Options()
                                                                )
                */
                QString path = QFileDialog::getOpenFileName(this,
                                                            "打开文件",
                                                            "../",             // 指示打开的文件夹。
                                                            "source(*.cpp *.h *.hpp);;"
                                                            "text(*.txt);;"     // 文件类型限制，此处;;结尾的字符串自动合并
                                                            "all(*)"
                                                            );
                qDebug() <<path;


            }
    );



    //  核心控件
    //  QTextEdit————文本编辑框
    //QTextEdit *pte = new QTextEdit(this);
    //      将创建的文本编辑框对象设置为本窗口的核心控件：
    //setCentralWidget(pte);                              // QMainWindow::setCentralWidget()设置核心控件



    // 浮动窗口
    QDockWidget *pdw = new QDockWidget(this);
    //      创建的浮动窗口对象添加到本窗口中。
    addDockWidget(Qt::RightDockWidgetArea, pdw);
    //      给浮动窗口添加控件
    pdw->setWidget(new QTextEdit(this));




    //      lambda表达式槽函数：控制台打印字符串
    connect(pb3, &QPushButton::clicked,
            [=]()
            {
                std::cout << "pb3 is clicked." << std::endl;
            }
    );



    // 变脸按钮的链接函数
    connect(pb2, &QPushButton::clicked, 
        [=]()  
        {
            std::string stemp = (pb2->text()).toStdString();     // text()————获取按钮类的text数据，是一个QString对象
            if(stemp == "变脸按钮")
            {
                pb2->setText("HAHAHA");
            }
            else
            {
                pb2->setText("变脸按钮");
            }
            
        }
    );

    // connect函数：指定signal传递接收的规则————连接信号和槽
    //      使用标准信号和槽
    connect(&b1, &QPushButton::pressed, this, &MainWindow::close);          // pressed是标准信号，close是标准槽。
    
    //      使用自定义槽
    connect(pb1, &QPushButton::pressed, this, &MainWindow::switchWindow);

    //      连接信号—槽：次级窗口发出的切换窗口signal -- deal_signal_switch_window
    connect(psw, &SubWin::signal_switch_window, this, &MainWindow::deal_signal_switch_window);

    // "new file"菜单项的connect
    connect(pa, &QAction::triggered,
            [=]()
                {
                    std::cout <<"QAction-new file is pressed." << std::endl;
                }
    );

    // "open"菜单项的connect
    connect(pa1, &QAction::triggered,
            [=]()
                {
                    std::cout <<"QAction-open is pressed." << std::endl;
                }
    );



 
}



MainWindow::~MainWindow()
{

}



void MainWindow::switchWindow (void)
{
    this->hide();
    psw->show();
}



// 槽函数——处理次级窗口对象发出的切换窗口signal
void MainWindow::deal_signal_switch_window(void)
{
    psw->hide();
    this->show();
    std::cout <<"deal signal switch window" << std::endl;
}
