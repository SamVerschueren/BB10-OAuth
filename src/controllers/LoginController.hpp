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

#include "OAuth.hpp"
#include "OAuthStrategy.hpp"
#include "GitHubStrategy.hpp"

using namespace bb::cascades;
using namespace oauth;
using namespace oauth::strategy;

class LoginController : public QObject
{
    Q_OBJECT

    private:
        OAuth *oauth;

    public:
        LoginController(QObject *parent=0);

        Q_INVOKABLE void authorize(WebView *webview);

    private slots:
        void authorized();
};

#endif /* LOGINCONTROLLER_HPP_ */
