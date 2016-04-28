#include <QtCore>
#include <TreeFrogView>
#include "artifakt.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT artifakt_editView : public TActionView
{
  Q_OBJECT
public:
  artifakt_editView() : TActionView() { }
  artifakt_editView(const artifakt_editView &) : TActionView() { }
  QString toString();
};

QString artifakt_editView::toString()
{
  responsebody.reserve(1677);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, artifakt);
  responsebody += QLatin1String("<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Artifakt</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", artifakt["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"artifakt[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(artifakt["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Title<br /><input type=\"text\" name=\"artifakt[title]\" value=\"");
  responsebody += THttpUtility::htmlEscape(artifakt["title"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Body<br /><input type=\"text\" name=\"artifakt[body]\" value=\"");
  responsebody += THttpUtility::htmlEscape(artifakt["body"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", artifakt["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(artifakt_editView)
T_REGISTER_VIEW(artifakt_editView)

#include "artifakt_editView.moc"
