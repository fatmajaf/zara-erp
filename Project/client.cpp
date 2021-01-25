#include "client.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QPrinter>
#include <QPainter>

Client::Client()
{
}

Client::Client(QString nom, QString prenom, int age, QString sexe, QString adresse, int CIN, int Ntel)
{
    this->nom=nom;
    this->prenom=prenom;
    this->age=age;
    this->sexe=sexe;
    this->adresse=adresse;
    this->CIN=CIN;
    this->Ntel=Ntel;
}

bool Client::Ajouter()
{
    QSqlQuery qrt;
    QString str="insert into client  values ('"+nom+"' , '"+prenom+"' , '"+QString::number(age)+"', '"+sexe+"' , '"+adresse+"', '"+QString::number(CIN)+"' , '"+QString::number(Ntel)+"' )";
    bool resultat=qrt.exec(str);
    qDebug()<<str<<resultat;

    return resultat;
}

bool Client::Ajouter_fidele()
{
    QSqlQuery qrt;
    QString str="insert into fidele  values ('"+nom+"' , '"+prenom+"' , '"+QString::number(age)+"', '"+sexe+"' , '"+adresse+"', '"+QString::number(CIN)+"' , '"+QString::number(Ntel)+"' )";
    bool resultat=qrt.exec(str);
    qDebug()<<str<<resultat;

    return resultat;
}

QSqlQueryModel * Client::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM client");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Ntel"));

    return model;
}


QSqlQueryModel * Client::afficher_fidele()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM fidele");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Ntel"));

    return model;
}

bool Client::Supprimer(int CIN)
{
    //QSqlQuery query("DELETE FROM client WHERE CIN = "+QString::number(CIN));
    QSqlQuery query;
    QString str="DELETE FROM client WHERE CIN = "+QString::number(CIN);
    qDebug()<<str;
    bool resultat=query.exec(str);
    return resultat;
}

Client Client::rechercher(int CIN)
{
    QSqlQuery query;

    QString str="SELECT * FROM Client WHERE CIN = "+QString::number(CIN);
    bool res=query.exec(str);

    qDebug()<<str<<res;

    query.next();
    QString nom_rech=query.value(0).toString();
    QString prenom_rech=query.value(1).toString();
    int age_rech=query.value(2).toInt();
    QString sexe_rech=query.value(3).toString();
    QString adresse_rech=query.value(4).toString();
    int CIN_rech=query.value(5).toInt();
    int Ntel_rech=query.value(6).toInt();

    Client * C=new Client(nom_rech,prenom_rech,age_rech,sexe_rech,adresse_rech,CIN_rech,Ntel_rech);


    return * C;
}


QSqlQueryModel * Client::recherche_av(QString chaine)
{
        QSqlQueryModel * model= new QSqlQueryModel();

        QString str="select * from client where nom like'"+chaine+"%'or prenom like'"+chaine+"%'or age like'"+chaine+"%' or sexe like'"+chaine+"%'or adresse like'"+chaine+"%'or CIN like'"+chaine+"%'or N°telephone like'"+chaine+"%'";
            model->setQuery(str);
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("age"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("N°telephone"));


            return model;

}


bool Client::Modifier_client(int c)
{
    QSqlQuery query;
    QString str="update client set nom='"+nom+"',prenom='"+prenom+"',age='"+QString::number(age)+"',sexe='"+sexe+"',adresse='"+adresse+"',cin='"+QString::number(CIN)+"',N°telephone='"+QString::number(Ntel)+"' where rowid='"+QString::number(c)+"' ";

    qDebug()<<str;
    bool res = query.exec(str);
    return res;
}

bool Client::pdf_client()
{

       QString age_pdf=QString::number(age);
       QString CIN_pdf=QString::number(CIN);
       QString Ntel_pdf=QString::number(Ntel);

       QPrinter printer;
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setOutputFileName("C:/Users/seif oueslati/Desktop/PDF/PDF_client/"+nom+"_"+prenom+".pdf");
       QPainter painter;
       if (! painter.begin(&printer))
           {
           qWarning("failed to open file, is it writable?");
           return 1;
           }
                painter.drawText(20, 50, "ZARA ");
                painter.drawText(200, 100, "Client");
                painter.drawText(20, 100, "Nom : ");
                painter.drawText(200, 100, nom);
                painter.drawText(20, 120, "Prénom : ");
                painter.drawText(200, 120, prenom);
                painter.drawText(20, 140, "age : ");
                painter.drawText(200, 140, age_pdf);
                painter.drawText(20, 160, "sexe : ");
                painter.drawText(200, 160, sexe);
                painter.drawText(20, 180, "adresse : ");
                painter.drawText(200, 180, adresse);
                painter.drawText(20, 200, "CIN : ");
                painter.drawText(200, 200, CIN_pdf);
                painter.drawText(20, 220, "Téléphone : ");
                painter.drawText(200, 220, Ntel_pdf);
       painter.end();
}


bool Client::remplir_modifier(int CIN)
{
        QSqlQuery qry;
        qry.prepare("select * from client where rowid='"+QString::number(CIN)+"'");
        if(qry.exec())
            {
                while(qry.next())
                {
                    nom=qry.value(0).toString();
                    prenom=qry.value(2).toString();
                    age=qry.value(1).toInt();
                    sexe=qry.value(3).toString();
                    adresse=qry.value(4).toString();
                    CIN=qry.value(5).toInt();
                    Ntel=qry.value(6).toInt();
                }
                return true;
            } else
            return false;
}
