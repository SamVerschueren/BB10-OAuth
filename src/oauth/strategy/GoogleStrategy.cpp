/*
 * GoogleStrategy.cpp
 *
 * Created on: 16-aug.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#include "GoogleStrategy.hpp"

namespace oauth {
    namespace strategy {

        GoogleStrategy::GoogleStrategy(QObject *parent) : OAuthStrategy(parent) {
            this->networkManager = new QNetworkAccessManager(this);
        }

        QUrl GoogleStrategy::getAuthorizationUrl() const {
            QUrl url("https://accounts.google.com/o/oauth2/auth");
            url.addQueryItem("response_type", "code");
            url.addQueryItem("client_id", OAuthStrategy::getClientKey());
            url.addQueryItem("redirect_uri", OAuthStrategy::getRedirectUrl().toString());
            url.addQueryItem("scope", OAuthStrategy::getScope());

            return url;
        }

        void GoogleStrategy::handleRequest(WebNavigationRequest *request) {
            QUrl url = request->url();

            if(url.host() == OAuthStrategy::getRedirectUrl().host() && url.hasQueryItem("code")) {
                // Retrieve the code out of the querystring
                QString code = url.queryItemValue("code");

                // Exchange the code for an access token
                QNetworkRequest networkRequest;
                networkRequest.setUrl(QUrl("https://accounts.google.com/o/oauth2/token"));
                networkRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

                // Create the post body
                QByteArray data;
                data.append("client_id=").append(OAuthStrategy::getClientKey());
                data.append("&client_secret=").append(OAuthStrategy::getClientSecret());
                data.append("&code=").append(code);
                data.append("&redirect_uri=").append(OAuthStrategy::getRedirectUrl().toString());
                data.append("&grant_type=authorization_code");

                connect(this->networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onAccessTokenRetrieved(QNetworkReply*)));
                this->networkManager->post(networkRequest, data);

                // Ignore the request because we have a code.
                request->setAction(WebNavigationRequestAction::Ignore);
            }
        }

        void GoogleStrategy::onAccessTokenRetrieved(QNetworkReply *reply) {
            disconnect(this->networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onAccessTokenRetrieved(QNetworkReply*)));

            if(reply->error() == QNetworkReply::NoError) {
                // TODO handle errors
                QVariantMap map = jda.loadFromBuffer(reply->readAll()).toMap();

                emit accessTokenRetrieved(map);
            }
        }

    } /* namespace strategy */
} /* namespace oauth */
