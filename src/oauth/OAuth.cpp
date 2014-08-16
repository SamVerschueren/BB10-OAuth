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

    void OAuth::setStrategy(OAuthStrategy *strategy) {
        qDebug() << strategy->metaObject()->className() << "injected";

        this->strategy = strategy;
    }

    void OAuth::authorize(WebView *webview) {
        connect(webview, SIGNAL(navigationRequested(bb::cascades::WebNavigationRequest*)), strategy, SLOT(handleRequest(bb::cascades::WebNavigationRequest*)));
        connect(strategy, SIGNAL(accessTokenRetrieved(QVariantMap)), this, SLOT(accessTokenRetrieved(QVariantMap)));

        webview->setUrl(this->strategy->getAuthorizationUrl());
    }

    void OAuth::accessTokenRetrieved(const QVariantMap& result) {
        emit authorized(result);
    }

} /* namespace oauth */
