#include "newstorydialog.h"
#include "ui_newstorydialog.h"

NewStoryDialog::NewStoryDialog(PageListController *p_c,
                               QWidget *parent) :
    QDialog(parent),
    ui_n(new Ui::NewStoryDialog),
    page_controller(p_c)
{
    ui_n->setupUi(this);
    ui_n->lineEdit_Title->setText(
                page_controller->title());
    ui_n->lineEdit_Author->setText(
                page_controller->author());
    ui_n->plainTextEdit_Description->setPlainText(
                page_controller->description());

    setupConnections();
}

NewStoryDialog::~NewStoryDialog()
{
    delete ui_n;
}

void NewStoryDialog::cancelNew()
{
    this->close();
    this->setResult(QDialog::Rejected);
}

void NewStoryDialog::okayNew()
{
    page_controller->settitle(
                ui_n->lineEdit_Title->text());
    page_controller->setauthor(
                ui_n->lineEdit_Author->text());
    page_controller->setdescription(
                ui_n->plainTextEdit_Description->toPlainText());

    this->close();
    this->setResult(QDialog::Accepted);
}

void NewStoryDialog::setupConnections()
{
    connect(ui_n->buttonBox_NewStory->button(QDialogButtonBox::Ok),
            &QPushButton::clicked,
            this, &NewStoryDialog::okayNew);

    connect(ui_n->buttonBox_NewStory->button(QDialogButtonBox::Cancel),
            &QPushButton::clicked,
            this, &NewStoryDialog::cancelNew);

}
