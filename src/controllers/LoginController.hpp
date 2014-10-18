/*
 * LoginController.hpp
 *
 * Created on: 13-aug.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#ifndef LOGINCONTROLLER_HPP_
#define LOGINCONTROLLER_HPP_

#include <QObject>
#include <bb/cascades/WebView>

#include "oauth/OAuth.hpp"

using namespace bb::cascades;
using namespace oauth;

class LoginController : public QObject
{
    Q_OBJECT

    private:
        OAuth *oauth;

    public:
        LoginController(QObject *parent=0);

        Q_INVOKABLE void authorize(WebView *webview);

    private slots:
        void authorized(const QVariantMap& data);
};

#endif /* LOGINCONTROLLER_HPP_ */
