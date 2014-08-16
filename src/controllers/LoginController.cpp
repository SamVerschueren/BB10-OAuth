/*
 * LoginController.cpp
 *
 * Created on: 13-aug.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#include "LoginController.hpp"

LoginController::LoginController(QObject *parent) : QObject(parent) {
    OAuthStrategy *strategy = new GitHubStrategy(this);
    strategy->setClientKey("client_key");
    strategy->setClientSecret("client_secret");

    this->oauth = new OAuth(this);
    this->oauth->setStrategy(strategy);

    connect(this->oauth, SIGNAL(authorized()), this, SLOT(authorized()));
}

void LoginController::authorize(WebView *webview) {
    this->oauth->authorize(webview);
}

void LoginController::authorized() {
    qDebug() << "The access token is: " << this->oauth->getAccessToken();
}
