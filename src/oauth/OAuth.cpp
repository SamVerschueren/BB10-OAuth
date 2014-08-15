/*
 * OAuth.cpp
 *
 * Created on: 13-aug.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#include "OAuth.hpp"

namespace oauth {

    OAuth::OAuth(QObject *parent) : QObject(parent), strategy(NULL) {

    }

    QString OAuth::getAccessToken() const {
        return this->accessToken;
    }

    void OAuth::setStrategy(OAuthStrategy *strategy) {
        this->strategy = strategy;
    }

    void OAuth::authorize(WebView *webview) {
        connect(webview, SIGNAL(navigationRequested(bb::cascades::WebNavigationRequest*)), strategy, SLOT(handleRequest(bb::cascades::WebNavigationRequest*)));
        connect(strategy, SIGNAL(accessTokenRetrieved(QString)), this, SLOT(accessTokenRetrieved(QString)));

        webview->setUrl(this->strategy->getAuthorizationUrl());
    }

    void OAuth::accessTokenRetrieved(const QString& token) {
        this->accessToken = token;

        emit authorized();
    }

} /* namespace oauth */
