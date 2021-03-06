#include "formsigninwindows.h"
#include "ui_formsigninwindows.h"
#include "visiofacedb.h"
#include <QMessageBox>
#include <QDir>

FormSignInWindows::FormSignInWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormSignInWindows)
{
    ui->setupUi(this);
}

FormSignInWindows::~FormSignInWindows()
{
    delete ui;
}

void FormSignInWindows::on_btnCreerImg_clicked()
{

}

void FormSignInWindows::on_btnCreate_clicked()
{
    QString nom= ui->liedNom->text();
    QString prenom = ui->liedPrenom->text();
    QString mail = ui->liedMail->text();

    QString dbname="visioface";
    QString host="localhost";
    QString user="root";
    QString mdp="";

    VisioFaceDB vfDatabase;

    if(nom==NULL || prenom==NULL || mail== NULL)
    {
      QMessageBox BoiteMessage;
      BoiteMessage.setText("Veuillez remplir le formulaire.");
      BoiteMessage.exec();
    }
    else
    {
      qDebug("non null");
      vfDatabase.createDatabase(dbname,host ,user,mdp);
     if(!vfDatabase.createUser(mail,nom,prenom))
     {
         QMessageBox BoiteMessage;
         BoiteMessage.setText("Utilisateur déjà existant.");
         BoiteMessage.exec();
     }
      QDir dir;
      dir.mkdir("usr/"+mail);
    }



}
