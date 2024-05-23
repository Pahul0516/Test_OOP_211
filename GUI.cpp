#include "GUI.h"

GUI::GUI()
{
	gui_init();
	table_init();
	connect_init();
	load_data();
}

void GUI::gui_init()
{
	this->setLayout(ly_main);

	ly_tabel->addWidget(tabel);
	ly_text->addWidget(text_id);
	ly_text->addWidget(text_nume);
	ly_text->addWidget(text_pret);
	ly_progress->addWidget(progress);
	ly_progress->addWidget(plus_minus);

	
	tabel->setSelectionMode(QAbstractItemView::ExtendedSelection);
	ly_main->addLayout(ly_tabel);
	ly_main->addLayout(ly_text);
	ly_main->addLayout(ly_progress);

	ly_btn->addWidget(btn);
	ly_main->addLayout(ly_btn);

}

void GUI::table_init()
{
	contr.contr_populeaza();
}

void GUI::load_data()
{
	tabel->clear();
	vector<stock> stocks = contr.contr_get_repo().get_lista();
	for (auto s : stocks)
	{
		QString val;
		QListWidgetItem* item = new QListWidgetItem{ QString::fromStdString(s.getID()) + " " + QString::number(s.getPrice()) };
		item->setData(Qt::UserRole, QString::fromStdString(s.getID()));
		if (s.getMontchly_ch() < 0)
		{
			item->setBackground(QBrush{ Qt::red });
		}
		else
		{
			item->setBackground(QBrush{ Qt::green });
		}
		tabel->addItem(item);
	}
}


void GUI::connect_init()
{
	connect(tabel, &QListWidget::itemSelectionChanged, [&]() {

		auto sel = tabel->selectedItems();
		if (!sel.isEmpty())
		{
			auto ID = sel[0]->data(Qt::UserRole).toString();

			vector<stock>::iterator s = contr.cautare_dupa_id(ID.toStdString());


			text_id->setText(QString::fromStdString(s->getID()));
			text_nume->setText(QString::fromStdString(s->getNume()));
			text_pret->setText(QString::number(s->getPrice()));

			int monthly = s->getMontchly_ch();

			if (monthly < 0)
				plus_minus->setText("-");
			else
				plus_minus->setText("+");



			if (monthly > 0)
			{
				progress->setFormat("+%p%");
				progress->setStyleSheet("QProgressBar { background-color: red; } QProgressBar::chunk { background-color: green; border-radius: 5px; }");

			}
			else
			{
				progress->setFormat("-%p%");
				progress->setStyleSheet("QProgressBar { background-color: red; } QProgressBar::chunk { background-color: red; border-radius: 5px; }");

			}

			for (int i = 0; i <= qAbs(monthly); i++)
			{
				QThread::msleep(1);
				progress->setValue(i);
			}
		}
		});

	connect(btn, &QPushButton::clicked, [&]() {
		auto sel = tabel->selectedItems();
		if (!sel.isEmpty())
		{
			QMessageBox::StandardButton replay = box->question(nullptr, "Intrebare", "Esti sigur ca vrei sa stergi?", QMessageBox::Yes | QMessageBox:: No);

			if (replay == QMessageBox::Yes)
			{
				for (auto it = sel.begin(); it != sel.end(); it++)
				{
					auto ID = (*it)->data(Qt::UserRole).toString();
					contr.contr_sterge(ID.toStdString());

				}
				load_data();
			}
		}

		});
}
