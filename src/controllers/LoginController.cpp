/*
 * LoginController.cpp
 *
 * Created on: 13-aug.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#include "LoginController.hpp"

#include "oauth/strategy/OAuthStrategy.hpp"
#include "oauth/strategy/GitHubStrategy.hpp"
#include "oauth/strategy/GoogleStrategy.hpp"
#include "oauth/strategy/LinkedInStrategy.hpp"
#include "oauth/strategy/FacebookStrategy.hpp"

using namespace oauth::strategy;

LoginController::LoginController(QObject *parent) : QObject(parent) {
    OAuthStrategy *facebook = new FacebookStrategy(this);
    facebook->setClientKey("client_key");
    facebook->setClientSecret("client_secret");
    facebook->setScope("email,public_profile");         // comma separated list
    facebook->setRedirectUrl(QUrl("redirect_uri"));     // Facebook does not allow you to use http://localhost as redirect URI.

    OAuthStrategy *google = new GoogleStrategy(this);
    google->setClientKey("client_key");
    google->setClientSecret("client_secret");
    google->setScope("email profile");                  // space separated list

    OAuthStrategy *linkedin = new LinkedInStrategy(this);
    linkedin->setClientKey("client_key");
    linkedin->setClientSecret("client_secret");
    linkedin->setScope("r_basicprofile rw_groups");     // space separated list

    OAuthStrategy *github = new GitHubStrategy(this);
    github->setClientKey("client_key");
    github->setClientSecret("client_secret");
    github->setScope("user,repo");                      // comma separated list

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
