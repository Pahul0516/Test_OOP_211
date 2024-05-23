#pragma once
#include <qwidget.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qprogressbar.h>
#include <qstring.h>
#include <qobject.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qbrush.h>
#include <qthread.h>
#include <qpushbutton.h>
#include <qmessagebox.h>

#include "controller.h"


class GUI: public QWidget
{

private:

	controller contr;

	QVBoxLayout* ly_main = new QVBoxLayout;
	QVBoxLayout* ly_tabel = new QVBoxLayout;
	QVBoxLayout* ly_text = new QVBoxLayout;
	QHBoxLayout* ly_progress = new QHBoxLayout;
	QVBoxLayout* ly_btn = new QVBoxLayout;

	QListWidget* tabel = new QListWidget;
	
	QLineEdit* text_id = new QLineEdit;
	QLineEdit* text_nume = new QLineEdit;
	QLineEdit* text_pret = new QLineEdit;

	QProgressBar* progress = new QProgressBar;

	QLabel* plus_minus = new QLabel{"Nimic"};

	QPushButton* btn = new QPushButton{ "Sterge" };

	QMessageBox* box = new QMessageBox;

	void gui_init(); // functie care initializeaza interfata
	void table_init(); // functie care initializeaza tableul cu citire din fisier
	void load_data(); // functie care incarca datele in table
	void connect_init(); // functie care initializeaza connectul


public:

	GUI();
};

