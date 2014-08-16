/*
 * For more information on the Google OAuth process:
 *      https://developers.google.com/accounts/docs/OAuth2InstalledApp
 *
 * Created on: 16-aug.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#ifndef GOOGLESTRATEGY_HPP_
#define GOOGLESTRATEGY_HPP_

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <bb/data/JsonDataAccess>

#include "OAuthStrategy.hpp"

using namespace bb::data;

namespace oauth {
    namespace strategy {

        class GoogleStrategy : public OAuthStrategy
        {
            Q_OBJECT

            private:
                QNetworkAccessManager* networkManager;
                JsonDataAccess jda;

            public:
                GoogleStrategy(QObject *parent=0);

                QUrl getAuthorizationUrl() const;

            private slots:
                void handleRequest(WebNavigationRequest *request);
                void onAccessTokenRetrieved(QNetworkReply *reply);
        };

    } /* namespace strategy */
} /* namespace oauth */
#endif /* GOOGLESTRATEGY_HPP_ */
