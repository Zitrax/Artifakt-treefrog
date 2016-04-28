#ifndef ARTIFAKTCONTROLLER_H
#define ARTIFAKTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ArtifaktController : public ApplicationController
{
    Q_OBJECT
public:
    ArtifaktController() { }
    ArtifaktController(const ArtifaktController &other);

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &artifakt = QVariantMap());
    void renderEdit(const QVariantMap &artifakt = QVariantMap());
};

T_DECLARE_CONTROLLER(ArtifaktController, artifaktcontroller)

#endif // ARTIFAKTCONTROLLER_H
