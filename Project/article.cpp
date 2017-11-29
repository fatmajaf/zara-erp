#include "article.h"
#include<QSqlQuery>
#include<QDebug>
article::article()
{

}
article::article(long identifiant_article ,int quantite ,int prix ,QString sexe,QString taille)
{
    this->identifiant_article=identifiant_article;
   this-> quantite=quantite ;
   this-> prix=prix ;
    this->taille=taille ;
   this-> sexe=sexe ;

}



QSqlQueryModel *article::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel;


       model->setQuery("SELECT * FROM article");

       return model;
}


bool article::Ajouterarticle()
{
    QSqlQuery query;
    QString str= "insert into Article (identifiant,quantite,prix,sexe,taille) values ('"+QString::number(identifiant_article)+"','"+QString::number(quantite)+"','"+QString::number(prix)+"','"+sexe+"','"+taille+"')";
    qDebug()<<str;
    bool res1 = query.exec(str);
    qDebug()<<res1;
    return res1;

}


QSqlQueryModel * article::rechercherArticle(long identifiant_article)
{
    QSqlQueryModel *model= new QSqlQueryModel();

    QString str="select * from Article where identifiant ="+QString::number(identifiant_article);



    model->setQuery(str);

    return model;
}
QSqlQueryModel *article::rechercherArticle2(QString x)
{
    // x=QString::number(identifiant_article);
    QSqlQueryModel *model = new QSqlQueryModel();
    QString str;
    if(x==""){
        str="SELECT * FROM  Article";
    }
    else{

        str="SELECT * FROM  Article where lower(identifiant) like '%"+x+"%'  or lower(quantite) like '%"+x+"%' or lower(prix) like '%"+x+"%' or lower(taille) like '%"+x+"%' or lower(sexe) like '%"+x+"%'" ;
    }

    model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("quantite"));
    model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prix"));
    model->setHeaderData(3, Qt::Horizontal,QObject:: tr("sexe"));
    model->setHeaderData(4, Qt::Horizontal,QObject:: tr("taille"));

    return model;
}


bool article::modifier(long identifiant_article)
{
    QSqlQuery query;
    QString prix_convert=QString::number(prix);
    QString disponibilite_convert=QString::number(quantite);
    QString identifiant_article_convert=QString::number(identifiant_article);


    QString str="update Article set identifiant='"+identifiant_article_convert+"',quantite='"+disponibilite_convert+"',prix='"+prix_convert+"',sexe='"+sexe+"',taille='"+taille+"' where  identifiant='"+identifiant_article_convert+"'" ;


        qDebug()<<str;
        bool res = query.exec(str);
        return res;

}

bool article::supprimerarticle(long identifiant_article)
{
    QSqlQuery query;
    QString str="delete from Article where identifiant ="+QString::number(identifiant_article);
    qDebug()<<str;
    bool res = query.exec(str);
    return res;

}
QSqlQueryModel *article::rechercherArticle3(QString x)
{
     x=QString::number(identifiant_article);
    QSqlQueryModel *model = new QSqlQueryModel();
    QString str;


        str="SELECT * FROM  Article where identifiant='"+x+"'";


    /*model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("quantite"));
    model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prix"));
    model->setHeaderData(3, Qt::Horizontal,QObject:: tr("taille"));
    model->setHeaderData(4, Qt::Horizontal,QObject:: tr("sexe"));

    return model;*/
}
int article::all()
{int val;

    QSqlQuery qry;

    qry.prepare("select count(*) from Article");
    qry.exec();
    while (qry.next()) {

                 val = qry.value(0).toInt();


             }
    return val;
}
int article::Homme()
{int val;

    QSqlQuery qry;

    qry.prepare("select count(*) from Article where sexe='Homme'");
    qry.exec();
    while (qry.next()) {

                 val = qry.value(0).toInt();


             }
    return val;
}
int article::Bebe()
{int val;

    QSqlQuery qry;

    qry.prepare("select count(*) from Article where sexe='Bebe'");
    qry.exec();
    while (qry.next()) {

                 val = qry.value(0).toInt();


             }
    return val;
}
int article::Femme()
{int val;

    QSqlQuery qry;

    qry.prepare("select count(*) from Article where sexe='Femme'");
    qry.exec();
    while (qry.next()) {

                 val = qry.value(0).toInt();


             }
    return val;
}



    int article::verifier(QString a)
    {
        int val;

            QSqlQuery qry;

            qry.prepare("select count(*) from article where identifiant='"+a+"'");
            qry.exec();
            while (qry.next()) {

                         val = qry.value(0).toInt();


                     }
            return val;
    }
    QSqlQueryModel *article::afficher2()
    {
        QSqlQueryModel *model = new QSqlQueryModel;

           model->setQuery("SELECT identifiant  FROM article");

           return model;
    }
    bool article::remplir_modifier(QString id)
    {
        QSqlQuery qry;
        qry.prepare("select * from article where identifiant='"+id+"'");

        if(qry.exec())
        {
        while(qry.next())
        {
        identifiant_article=qry.value(0).toLongLong();
         quantite=qry.value(2).toInt();
         prix=qry.value(1).toInt();
         sexe=qry.value(3).toString();
         taille=qry.value(4).toString();




        }
    return true;
        }
    else return false;}


