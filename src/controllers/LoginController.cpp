/*
 * LoginController.cpp
 *
 * Created on: 13-aug.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#include "LoginController.hpp"

LoginController::LoginController(QObject *parent) : QObject(parent) {
    OAuthStrategy *github = new GitHubStrategy(this);
    github->setClientKey("client_key");
    github->setClientSecret("client_secret");
    github->setScope("user,repo");                      // comma separated list

    OAuthStrategy *google = new GoogleStrategy(this);
    google->setClientKey("client_key");
    google->setClientSecret("client_secret");
    google->setScope("email profile");                  // space separated list

    this->oauth = new OAuth(this);
    this->oauth->setStrategy(google);

    connect(this->oauth, SIGNAL(authorized(QVariantMap)), this, SLOT(authorized(QVariantMap)));
}

void LoginController::authorize(WebView *webview) {
    this->oauth->authorize(webview);
}

void LoginController::authorized(const QVariantMap& data) {
    qDebug() << data;
}
