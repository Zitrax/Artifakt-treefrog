#ifndef ARTIFAKT_H
#define ARTIFAKT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ArtifaktObject;
class QJsonArray;


class T_MODEL_EXPORT Artifakt : public TAbstractModel
{
public:
    Artifakt();
    Artifakt(const Artifakt &other);
    Artifakt(const ArtifaktObject &object);
    ~Artifakt();

    int id() const;
    QString filename() const;
    void setFilename(const QString &filename);
    QString sha1() const;
    void setSha1(const QString &sha1);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    int lockRevision() const;
    Artifakt &operator=(const Artifakt &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static Artifakt create(const QString &filename, const QString &sha1);
    static Artifakt create(const QVariantMap &values);
    static Artifakt get(int id);
    static Artifakt get(int id, int lockRevision);
    static int count();
    static QList<Artifakt> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ArtifaktObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Artifakt)
Q_DECLARE_METATYPE(QList<Artifakt>)

#endif // ARTIFAKT_H
