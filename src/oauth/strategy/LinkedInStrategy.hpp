/*
 * LinkedInStrategy.hpp
 *
 * Created on: 15-okt.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */
#ifndef LINKEDINSTRATEGY_HPP_
#define LINKEDINSTRATEGY_HPP_

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <bb/data/JsonDataAccess>

#include "OAuthStrategy.hpp"

using namespace bb::data;

namespace oauth {
    namespace strategy {

        class LinkedInStrategy : public OAuthStrategy
        {
            Q_OBJECT

            private:
                QNetworkAccessManager* networkManager;
                JsonDataAccess jda;

            public:
                LinkedInStrategy(QObject *parent);

                QUrl getAuthorizationUrl() const;

            private slots:
                void handleRequest(WebNavigationRequest *request);
                void onAccessTokenRetrieved(QNetworkReply *reply);
        };
    } /* namespace strategy */
} /* namespace oauth */

#endif /* LINKEDINSTRATEGY_HPP_ */
