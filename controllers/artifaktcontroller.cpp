#include "artifaktcontroller.h"
#include "artifakt.h"


ArtifaktController::ArtifaktController(const ArtifaktController &)
    : ApplicationController()
{ }

void ArtifaktController::index()
{
    QList<Artifakt> artifaktList = Artifakt::getAll();
    texport(artifaktList);
    render();
}

void ArtifaktController::show(const QString &pk)
{
    auto artifakt = Artifakt::get(pk.toInt());
    texport(artifakt);
    render();
}

void ArtifaktController::entry()
{
    renderEntry();
}

void ArtifaktController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto form = httpRequest().formItems("artifakt");
    auto artifakt = Artifakt::create(form);
    if (!artifakt.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", artifakt.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void ArtifaktController::renderEntry(const QVariantMap &artifakt)
{
    texport(artifakt);
    render("entry");
}

void ArtifaktController::edit(const QString &pk)
{
    auto artifakt = Artifakt::get(pk.toInt());
    if (!artifakt.isNull()) {
        session().insert("artifakt_lockRevision", artifakt.lockRevision());
        renderEdit(artifakt.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void ArtifaktController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    int rev = session().value("artifakt_lockRevision").toInt();
    auto artifakt = Artifakt::get(pk.toInt(), rev);
    if (artifakt.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    auto form = httpRequest().formItems("artifakt");
    artifakt.setProperties(form);
    if (artifakt.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void ArtifaktController::renderEdit(const QVariantMap &artifakt)
{
    texport(artifakt);
    render("edit");
}

void ArtifaktController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    auto artifakt = Artifakt::get(pk.toInt());
    artifakt.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(artifaktcontroller)
