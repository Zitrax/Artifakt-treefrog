#include <TreeFrogModel>
#include "artifakt.h"
#include "artifaktobject.h"

Artifakt::Artifakt()
    : TAbstractModel(), d(new ArtifaktObject)
{
    d->id = 0;
    d->lock_revision = 0;
}

Artifakt::Artifakt(const Artifakt &other)
    : TAbstractModel(), d(new ArtifaktObject(*other.d))
{ }

Artifakt::Artifakt(const ArtifaktObject &object)
    : TAbstractModel(), d(new ArtifaktObject(object))
{ }

Artifakt::~Artifakt()
{
    // If the reference count becomes 0,
    // the shared data object 'ArtifaktObject' is deleted.
}

int Artifakt::id() const
{
    return d->id;
}

QString Artifakt::title() const
{
    return d->title;
}

void Artifakt::setTitle(const QString &title)
{
    d->title = title;
}

QString Artifakt::body() const
{
    return d->body;
}

void Artifakt::setBody(const QString &body)
{
    d->body = body;
}

QDateTime Artifakt::createdAt() const
{
    return d->created_at;
}

QDateTime Artifakt::updatedAt() const
{
    return d->updated_at;
}

int Artifakt::lockRevision() const
{
    return d->lock_revision;
}

Artifakt &Artifakt::operator=(const Artifakt &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Artifakt Artifakt::create(const QString &title, const QString &body)
{
    ArtifaktObject obj;
    obj.title = title;
    obj.body = body;
    if (!obj.create()) {
        return Artifakt();
    }
    return Artifakt(obj);
}

Artifakt Artifakt::create(const QVariantMap &values)
{
    Artifakt model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Artifakt Artifakt::get(int id)
{
    TSqlORMapper<ArtifaktObject> mapper;
    return Artifakt(mapper.findByPrimaryKey(id));
}

Artifakt Artifakt::get(int id, int lockRevision)
{
    TSqlORMapper<ArtifaktObject> mapper;
    TCriteria cri;
    cri.add(ArtifaktObject::Id, id);
    cri.add(ArtifaktObject::LockRevision, lockRevision);
    return Artifakt(mapper.findFirst(cri));
}

int Artifakt::count()
{
    TSqlORMapper<ArtifaktObject> mapper;
    return mapper.findCount();
}

QList<Artifakt> Artifakt::getAll()
{
    return tfGetModelListByCriteria<Artifakt, ArtifaktObject>(TCriteria());
}

QJsonArray Artifakt::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ArtifaktObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ArtifaktObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Artifakt(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Artifakt::modelData()
{
    return d.data();
}

const TModelObject *Artifakt::modelData() const
{
    return d.data();
}
