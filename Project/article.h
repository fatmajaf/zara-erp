#ifndef ARTICLE_H
#define ARTICLE_H
#include<QString>

#include<QSqlQueryModel>
#include <qmessagebox.h>
class article
{
public:
    article();
    article(long identifiant_article ,int quantite ,int prix ,QString sexe,QString taille);

      virtual  QSqlQueryModel *afficher();
    bool Ajouterarticle();
    bool modifier(long identifiant_article);

    QSqlQueryModel *afficher2();
     bool supprimerarticle(long identifiant_article);


    QSqlQueryModel * rechercherArticle(long identifiant_article);
    QSqlQueryModel * rechercherArticle2(QString x) ;
    int verifier(QString a) ;

QSqlQueryModel * rechercherArticle3(QString x);
bool remplir_modifier(QString id);
int all() ;
int Homme() ;
int Femme() ;
int Bebe() ;
long get_identifiant_article(){return identifiant_article;}
int get_quantite(){return quantite; }
float get_prix(){return prix ;}
QString get_taille(){return taille; }
 QString get_sexe() {return sexe;}






private:
    long identifiant_article ;
    int quantite ;
    float prix ;
    QString taille ;
    QString sexe ;
};

#endif // ARTICLE_H
