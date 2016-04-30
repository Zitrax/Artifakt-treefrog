#ifndef ARTIFAKTOBJECT_H
#define ARTIFAKTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ArtifaktObject : public TSqlObject, public QSharedData
{
public:
    int id;
    QString filename;
    QString sha1;
    QDateTime created_at;
    QDateTime updated_at;
    int lock_revision;

    enum PropertyIndex {
        Id = 0,
        Filename,
        Sha1,
        CreatedAt,
        UpdatedAt,
        LockRevision,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("artifakt"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString filename READ getfilename WRITE setfilename)
    T_DEFINE_PROPERTY(QString, filename)
    Q_PROPERTY(QString sha1 READ getsha1 WRITE setsha1)
    T_DEFINE_PROPERTY(QString, sha1)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // ARTIFAKTOBJECT_H
