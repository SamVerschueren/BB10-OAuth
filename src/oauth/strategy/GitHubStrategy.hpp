/*
 * For more information on the GitHub OAuth process:
 *      https://developer.github.com/v3/oauth/
 *
 * Created on: 13-aug.-2014
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#ifndef GITHUBSTRATEGY_HPP_
#define GITHUBSTRATEGY_HPP_

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <bb/data/JsonDataAccess>

#include "OAuthStrategy.hpp"

using namespace bb::data;

namespace oauth {
    namespace strategy {

        class GitHubStrategy : public OAuthStrategy
        {
            Q_OBJECT

            private:
                QNetworkAccessManager* networkManager;
                JsonDataAccess jda;

            public:
                GitHubStrategy(QObject *parent=0);

                QUrl getAuthorizationUrl() const;

            private slots:
                void handleRequest(WebNavigationRequest *request);
                void onAccessTokenRetrieved(QNetworkReply *reply);
        };

    } /* namespace strategy */
} /* namespace oauth */
#endif /* GITHUBSTRATEGY_HPP_ */
