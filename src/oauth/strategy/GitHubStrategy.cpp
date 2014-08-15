/*
 * GitHubStrategy.cpp
 *
 * Created on: 13-aug.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#include "GitHubStrategy.hpp"

namespace oauth {
    namespace strategy {

        GitHubStrategy::GitHubStrategy(QObject *parent) : OAuthStrategy(parent) {
            qDebug() << "GitHubStrategy injected";

            this->networkManager = new QNetworkAccessManager(this);
        }

        QUrl GitHubStrategy::getAuthorizationUrl() const {
            QString url("https://github.com/login/oauth/authorize");
            url.append("?client_id=").append(OAuthStrategy::getClientKey());
            url.append("&redirect_uri=").append(OAuthStrategy::getCallbackUrl().toString());

            return QUrl(url);
        }

        void GitHubStrategy::handleRequest(WebNavigationRequest *request) {
            QUrl url = request->url();

            if(url.host() == OAuthStrategy::getCallbackUrl().host() && url.hasQueryItem("code")) {
                QByteArray data;

                // Retrieve the code out of the querystring
                QString code = url.queryItemValue("code");

                // Exchange the code for an access token
                QNetworkRequest networkRequest;
                networkRequest.setUrl(QUrl("https://github.com/login/oauth/access_token"));
                networkRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
                networkRequest.setRawHeader("accept", "application/json");

                // Create the post body
                QVariantMap map;
                map.insert("client_id", OAuthStrategy::getClientKey());
                map.insert("client_secret", OAuthStrategy::getClientSecret());
                map.insert("code", code);
                map.insert("redirect_uri", OAuthStrategy::getCallbackUrl().toString());

                // Convert the body to json
                jda.saveToBuffer(map, &data);

                connect(this->networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onAccessTokenRetrieved(QNetworkReply*)));
                this->networkManager->post(networkRequest, data);

                // Ignore the request because we have a code.
                request->setAction(WebNavigationRequestAction::Ignore);
            }
        }

        void GitHubStrategy::onAccessTokenRetrieved(QNetworkReply *reply) {
            disconnect(this->networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onAccessTokenRetrieved(QNetworkReply*)));

            if(reply->error() == QNetworkReply::NoError) {
                // TODO handle errors
                QVariantMap map = jda.loadFromBuffer(reply->readAll()).toMap();

                QString token = map.value("access_token").toString();

                emit accessTokenRetrieved(token);
            }
        }

    } /* namespace strategy */
} /* namespace oauth */
