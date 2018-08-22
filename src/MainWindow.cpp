#include "MainWindow.h"
#include <QStandardItemModel>
#include <QTableView>
#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	m_stdItemModel(new QStandardItemModel(this)),
	m_btnFill(new QPushButton(tr("Fill"), this)),
	m_btnClear(new QPushButton(tr("Clear"), this))
{
	auto *widget = new QWidget(this);
	auto *layoutMain = new QVBoxLayout(widget);
	auto *table = new QTableView(this);

	table->setModel(m_stdItemModel);

	layoutMain->addWidget(m_btnFill);
	layoutMain->addWidget(m_btnClear);
	layoutMain->addWidget(table);

	setCentralWidget(widget);

	connect(m_btnFill, &QPushButton::clicked, this, &MainWindow::onFill);
	connect(m_btnClear, &QPushButton::clicked, this, &MainWindow::onClear);
}

void MainWindow::onFill()
{
	m_btnFill->setDisabled(true);

	QList<QStandardItem*> itemList ;

	for (int var = 0; var < 100000; ++var) {
		itemList = {new QStandardItem(""),new QStandardItem(""),new QStandardItem(""),new QStandardItem(""),new QStandardItem(""),new QStandardItem("")};
		m_stdItemModel->appendRow(itemList);
	}

	m_btnClear->setEnabled(true);
}

void MainWindow::onClear()
{
	m_btnClear->setDisabled(true);

	m_stdItemModel->setRowCount(0);

	m_btnFill->setEnabled(true);
}
