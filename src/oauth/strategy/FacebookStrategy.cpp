/*
 * FacebookStrategy.cpp
 *
 * Created on: 18-okt.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#include "FacebookStrategy.hpp"

namespace oauth {
    namespace strategy {

        FacebookStrategy::FacebookStrategy(QObject *parent) : OAuthStrategy(parent) {
            this->networkManager = new QNetworkAccessManager(this);
        }

        QUrl FacebookStrategy::getAuthorizationUrl() const {
            QUrl url("https://www.facebook.com/dialog/oauth");
            url.addQueryItem("response_type", "code");
            url.addQueryItem("client_id", OAuthStrategy::getClientKey());
            url.addQueryItem("redirect_uri", OAuthStrategy::getRedirectUrl().toString());
            url.addQueryItem("state", OAuthStrategy::getState());

            if(!OAuthStrategy::getScope().isEmpty()) {
                url.addQueryItem("scope", OAuthStrategy::getScope());
            }

            return url;
        }

        void FacebookStrategy::handleRequest(WebNavigationRequest *request) {
            QUrl url = request->url();

            if(url.host() == OAuthStrategy::getRedirectUrl().host() && url.hasQueryItem("code") && url.queryItemValue("state") == OAuthStrategy::getState()) {
                QByteArray data;

                // Retrieve the code out of the querystring
                QString code = url.queryItemValue("code");

                QUrl url("https://graph.facebook.com/oauth/access_token");
                url.addQueryItem("client_id", OAuthStrategy::getClientKey());
                url.addQueryItem("client_secret", OAuthStrategy::getClientSecret());
                url.addQueryItem("code", code);
                url.addQueryItem("redirect_uri", OAuthStrategy::getRedirectUrl().toString());

                // Exchange the code for an access token
                QNetworkRequest networkRequest;
                networkRequest.setUrl(url);
                networkRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
                networkRequest.setRawHeader("accept", "application/json");

                connect(this->networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onAccessTokenRetrieved(QNetworkReply*)));
                this->networkManager->get(networkRequest);

                // Ignore the request because we have a code.
                request->setAction(WebNavigationRequestAction::Ignore);
            }
        }

        void FacebookStrategy::onAccessTokenRetrieved(QNetworkReply *reply) {
            disconnect(this->networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onAccessTokenRetrieved(QNetworkReply*)));

            if(reply->error() == QNetworkReply::NoError) {
                QUrl data("?" + reply->readAll());

                // TODO handle errors
                QVariantMap map;
                map.insert("access_token", data.queryItemValue("access_token"));
                map.insert("expires", data.queryItemValue("expires").toInt());

                emit accessTokenRetrieved(map);
            }
        }

    } /* namespace strategy */
} /* namespace oauth */
