#include <QtCore>
#include <TreeFrogView>
#include "artifakt.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT artifakt_entryView : public TActionView
{
  Q_OBJECT
public:
  artifakt_entryView() : TActionView() { }
  artifakt_entryView(const artifakt_entryView &) : TActionView() { }
  QString toString();
};

QString artifakt_entryView::toString()
{
  responsebody.reserve(1288);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, artifakt);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Artifakt</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Title<br /><input name=\"artifakt[title]\" value=\"");
  responsebody += THttpUtility::htmlEscape(artifakt["title"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Body<br /><input name=\"artifakt[body]\" value=\"");
  responsebody += THttpUtility::htmlEscape(artifakt["body"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(artifakt_entryView)
T_REGISTER_VIEW(artifakt_entryView)

#include "artifakt_entryView.moc"
