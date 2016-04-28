#include <QtCore>
#include <TreeFrogView>
#include "artifakt.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT artifakt_showView : public TActionView
{
  Q_OBJECT
public:
  artifakt_showView() : TActionView() { }
  artifakt_showView(const artifakt_showView &) : TActionView() { }
  QString toString();
};

QString artifakt_showView::toString()
{
  responsebody.reserve(1651);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Artifakt, artifakt);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Artifakt</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(artifakt.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Title</dt><dd>");
  responsebody += THttpUtility::htmlEscape(artifakt.title());
  responsebody += QLatin1String("</dd><br />\n<dt>Body</dt><dd>");
  responsebody += THttpUtility::htmlEscape(artifakt.body());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(artifakt.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(artifakt.updatedAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(artifakt.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", artifakt.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(artifakt_showView)
T_REGISTER_VIEW(artifakt_showView)

#include "artifakt_showView.moc"
