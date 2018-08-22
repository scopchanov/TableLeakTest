#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QStandardItemModel;
class QPushButton;

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = nullptr);

private:
	QStandardItemModel *m_stdItemModel;
	QPushButton *m_btnFill;
	QPushButton *m_btnClear;

private slots:
	void onFill();
	void onClear();
};

#endif // MAINWINDOW_H
