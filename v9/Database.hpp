#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>


/**
 * Classe contrôlant la base de données
* @authors Guillaume Vautrin
* @version v9 (Dernière modification)
 */
class Database
{

private:
/**
* @brief Base de données SQLite
* @authors Guillaume Vautrin
* @version v9 (Dernière modification)
*/
    QSqlDatabase m_dbb;

public:
/**
* @brief Vérifie la possibilité de se connecter à une base de donnée et prépare celle-ci
* @authors Guillaume Vautrin
* @version v9 (Dernière modification)
*/
    Database();

/**
* @brief Initialise la base de données avec les tables relationnelles
* @authors Guillaume Vautrin
* @version v9 (Dernière modification)
*/
    void initialisation();

};

#endif // DATABASE_HPP
